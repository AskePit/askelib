#include <iostream>
#include <std/money.h>

static bool pass {true};

#define print(X) std::cout << X << " ";
#define printl(X) std::cout << X << std::endl;
#define printll(X) std::cout << X << std::endl << std::endl;

#define TEST(EXPR) \
    print("\t"#EXPR); \
    if(EXPR) printl("[PASS]") else { printl("[FAIL]"); pass=false; }

#define TEST_DOUBLE(X, UNITS, CENTS) \
    print("\t"#X" == "#UNITS"."#CENTS); \
    if((X).units_cents() == Money::money_pair(UNITS, CENTS)) \
        printl("[PASS]") \
    else {\
        printl("[FAIL]"); \
        pass = false; \
    }

int main()
{
    printll("Tests start");
    printl("[Money end]");

    Money x;
    TEST(x == 0.0);
    x += 1.0;
    TEST_DOUBLE(x, 1, 0);
    x = 1055.82;
    TEST_DOUBLE(x, 1055, 82);
    x = 1055.823;
    TEST_DOUBLE(x, 1055, 82);
    x = 1055.83;
    TEST_DOUBLE(x, 1055, 83);
    x -= 815.44;
    TEST_DOUBLE(x, 240, 39);
    Money y(x);
    TEST_DOUBLE(y, 240, 39);
    Money z = x + y;
    TEST_DOUBLE(z, 480, 78);
    x += 1.01;
    y -= 10.01;
    z -= 105.03;
    TEST_DOUBLE(x, 241, 40);
    TEST_DOUBLE(y, 230, 38);
    TEST_DOUBLE(z, 375, 75);
    TEST_DOUBLE(x+y+z, 847, 53);
    TEST_DOUBLE(x-z, -134, -35);
    TEST(x > y);
    TEST(x >= y);
    TEST(y < x);
    TEST(y <= x);
    TEST(y < z);
    TEST(y <= z);
    TEST(z > y);
    TEST(z >= y);
    TEST(x < z);
    TEST(x <= z);
    TEST(z > x);
    TEST(z >= x);
    TEST(x != z);
    TEST(x != y);
    TEST(z != y);
    TEST(x + 134.35 == z);
    y += 0.02;
    TEST_DOUBLE(y, 230, 40);
    TEST(y + 11 == x);
    TEST(x - 11 == y);
    TEST(x == y + 11);
    TEST(y == x - 11);
    TEST(x - x == 0);
    TEST(x - x == 0u);
    TEST(x - x == 0.0);

    TEST_DOUBLE(z, 375, 75);
    z *= -1;
    TEST_DOUBLE(z, -375, -75);
    z *= -1;
    TEST_DOUBLE(z, 375, 75);
    z /= -1;
    TEST_DOUBLE(z, -375, -75);
    z /= -1;
    TEST_DOUBLE(z, 375, 75);

    z *= 2;
    TEST_DOUBLE(z, 751, 50);
    z /= 2;
    TEST_DOUBLE(z, 375, 75);
    z *= -2;
    TEST_DOUBLE(z, -751, -50);
    z /= -2;
    TEST_DOUBLE(z, 375, 75);

    TEST_DOUBLE(z = y = x, 241, 40);
    TEST_DOUBLE(x, 241, 40);
    TEST_DOUBLE(y, 241, 40);
    TEST_DOUBLE(z, 241, 40);

    printll("[Money end]");
    print("Tests end");
    if(pass) {
        printl("- [PASSED]");
    } else {
        printl("- [FAILED]");
    }

    return 0;
}

