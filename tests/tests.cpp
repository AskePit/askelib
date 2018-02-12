#include <iostream>
#include <QString>
#include <std/money.h>
#include <std/tree.h>

static bool pass {true};

#define print(X) std::cout << X << " ";
#define printl(X) std::cout << X << std::endl;
#define printll(X) std::cout << X << std::endl << std::endl;

#define TEST(EXPR) \
    if(!(EXPR)) { print("\t"#EXPR); printl("[FAIL]"); pass=false; }

#define TEST_DOUBLE(X, UNITS, CENTS) \
    if((X).units_cents() != Money::money_pair(UNITS, CENTS)) { \
        print("\t"#X" == "#UNITS"."#CENTS); \
        print("[FAIL]"); \
        print("res: "); \
        printl((X).units_cents().first << '.' << (X).units_cents().second); \
        pass = false; \
    }

void testMoney()
{
    printl("[Money start]");

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

    Currency::setWeight(Currency::Usd, 0.5);
    Currency::setWeight(Currency::Eur, 0.25);
    Money dollars(2, Currency::Usd);
    Money euro = dollars.convertToCopy(Currency::Eur);
    TEST_DOUBLE(euro, 1, 0);
    euro.convertTo(Currency::Usd);
    TEST_DOUBLE(euro, 2, 0);
    TEST(euro.currency() == Currency::Usd);

    Currency::setWeight(Currency::Usd, 1);
    Currency::setWeight(Currency::Rub, 58.17);

    Money rubles(500, Currency::Rub);
    TEST(rubles.currency() == Currency::Rub);
    dollars = rubles;
    TEST(dollars.currency() == Currency::Rub);
    TEST_DOUBLE(dollars, 500, 0);
    dollars.convertTo(Currency::Usd);
    TEST_DOUBLE(dollars, 8, 59);

    printll("[Money end]");
}

void testTree()
{
    printl("[Tree start]");

    // Food
    //    Bread
    //    Sweets
    //       Ice-Cream
    //       Chocolate
    //       Cookies
    //    Meat
    //       Pork
    //       Fish
    //          Salmon
    //          Cod
    //          Mackerel
    //          Cat-fish
    //          Perch
    //       Chicken
    //    Drinks
    //       Alcohol
    //          Vodka
    //       Alcohol-free
    //          Coke
    //             Coka-Cola
    //             Pepsi
    // Rent
    // Clothes
    //    Pants
    // Study
    //    Internet-cources
    //    Books

    Tree<QString> t;
    Node<QString> *food = t.addChild("Food");
    Node<QString> *rent = t.addChild("Rent");
    Node<QString> *clothes = t.addChild("Clothes");
    Node<QString> *study = t.addChild("Study");

    Node<QString> *pants = clothes->addChild("Pants");
    Node<QString> *internetCources = study->addChild("Internet-cources");
    Node<QString> *books = study->addChild("Books");

    Node<QString> *bread = food->addChild("Bread");
    Node<QString> *sweets = food->addChild("Sweets");
    Node<QString> *meat = food->addChild("Meat");
    Node<QString> *drinks = food->addChild("Drinks");

    Node<QString> *iceCream = sweets->addChild("Ice-Cream");
    Node<QString> *chocolate = sweets->addChild("Chocolate");
    Node<QString> *cookies = sweets->addChild("Cookies");

    Node<QString> *pork = meat->addChild("Pork");
    Node<QString> *fish = meat->addChild("Fish");
    Node<QString> *chicken = meat->addChild("Chicken");

    Node<QString> *salmon = fish->addChild("Salmon");
    Node<QString> *cod = fish->addChild("Cod");
    Node<QString> *mackerel = fish->addChild("Mackerel");
    Node<QString> *catFish = fish->addChild("Cat-fish");
    Node<QString> *perch = fish->addChild("Perch");

    Node<QString> *alcohol = drinks->addChild("Alcohol");
    Node<QString> *alcoholFree = drinks->addChild("Alcohol-Free");

    Node<QString> *vodka = alcohol->addChild("Vodka");
    Node<QString> *coke = alcoholFree->addChild("Coke");

    Node<QString> *cokaCola = coke->addChild("Coka-Cola");
    Node<QString> *pepsi = coke->addChild("Pepsi");

    // Data check
    TEST(food->data == "Food");
    TEST(rent->data == "Rent");
    TEST(clothes->data == "Clothes");
    TEST(study->data == "Study");
    TEST(pants->data == "Pants");
    TEST(internetCources->data == "Internet-cources");
    TEST(books->data == "Books");
    TEST(bread->data == "Bread");
    TEST(sweets->data == "Sweets");
    TEST(meat->data == "Meat");
    TEST(drinks->data == "Drinks");
    TEST(iceCream->data == "Ice-Cream");
    TEST(chocolate->data == "Chocolate");
    TEST(cookies->data == "Cookies");
    TEST(pork->data == "Pork");
    TEST(fish->data == "Fish");
    TEST(chicken->data == "Chicken");
    TEST(salmon->data == "Salmon");
    TEST(cod->data == "Cod");
    TEST(mackerel->data == "Mackerel");
    TEST(catFish->data == "Cat-fish");
    TEST(perch->data == "Perch");
    TEST(alcohol->data == "Alcohol");
    TEST(alcoholFree->data == "Alcohol-Free");
    TEST(vodka->data == "Vodka");
    TEST(coke->data == "Coke");
    TEST(cokaCola->data == "Coka-Cola");
    TEST(pepsi->data == "Pepsi");

    // Child count
    TEST(t.childCount() == 4);
    TEST(food->childCount() == 4);
    TEST(rent->childCount() == 0);
    TEST(clothes->childCount() == 1);
    TEST(cod->childCount() == 0);
    TEST(fish->childCount() == 5);

    // Food
    //    Bread
    //    Sweets
    //       Ice-Cream
    //       Chocolate
    //       Cookies
    //    Meat
    //       Pork
    //       Fish
    //          Salmon
    //          Cod
    //          Mackerel
    //          Cat-fish
    //          Perch
    //       Chicken
    //    Drinks
    //       Alcohol
    //          Vodka
    //       Alcohol-free
    //          Coke
    //             Coka-Cola
    //             Pepsi
    // Rent
    // Clothes
    //    Pants
    // Study
    //    Internet-cources
    //    Books

    // Index-based search
    TEST( t.at(0) == food );
    TEST( t.at(1) == rent );
    TEST( t.at(3) == study );
    TEST( t.at(3)->at(1) == books );
    TEST( study->at(1) == books );
    TEST( t.at(0)->at(1)->at(1) == chocolate );
    TEST( food->at(1)->at(1) == chocolate );
    TEST( t.at(0)->at(2)->at(2) == chicken );
    TEST( t.at(0)->at(2)->at(1) == fish );
    TEST( meat->at(1) == fish );
    TEST( fish->at(2) == mackerel );

    // Data-based search
    TEST( t.child("Food") == food );
    TEST( t.child("Rent") == rent );
    TEST( t.child("Study") == study );
    TEST( study->child("Books") == books );
    TEST( t.child("Food")->child("Sweets")->child("Chocolate") == chocolate );
    TEST( sweets->child("Chocolate") == chocolate );
    TEST( t.child("Food")->child("Meat")->child("Chicken") == chicken );
    TEST( meat->child("Chicken") == chicken );
    TEST( meat->child("Fish") == fish );
    TEST( t.child("Food")->child("Meat")->child("Fish")->child("Mackerel") == mackerel );
    TEST( fish->child("Mackerel") == mackerel );

    // Parents
    TEST(t.parent == nullptr);
    TEST(chocolate->parent == sweets);
    TEST(food->parent == &t);
    TEST(meat->parent == food);
    TEST(mackerel->parent == fish);
    TEST(books->parent == study);
    TEST(rent->parent == &t);

    // Data change
    alcoholFree->data = "Alcohol-free";
    TEST(alcoholFree->data == "Alcohol-free");

    // Clone
    {
        Tree<QString> *t2 = t.clone();

        TEST( t2->at(0)->data == "Food" );
        TEST( t2->at(1)->data == "Rent" );
        TEST( t2->at(3)->data == "Study" );
        TEST( t2->at(3)->at(1)->data == "Books" );
        TEST( t2->at(0)->at(1)->at(1)->data == "Chocolate" );
        TEST( t2->at(0)->at(2)->at(2)->data == "Chicken" );
        TEST( t2->at(0)->at(2)->at(1)->data == "Fish" );

        TEST(t2->child("Food")->child("Meat")->child("Chicken") != chicken);
        TEST(t2->child("Food")->child("Sweets") != sweets);
        TEST(t2->child("Rent") != rent);
        TEST(t2->child("Food")->child("Drinks")->child("Alcohol-free")->child("Coke")->child("Pepsi") != pepsi);
        TEST(t2->child("Clothes") != clothes);
        TEST(t2->child("Clothes")->child("Pants") != pants);

        {
            Tree<QString> *t = t2->clone();

            Node<QString> *meat = t->child("Food")->child("Meat");
            Node<QString> *fish = meat->child("Fish");

            // t:
            // Food
            //    Bread
            //    Sweets
            //       Ice-Cream
            //       Chocolate
            //       Cookies
            //    Meat             <-- meat
            //       Pork
            //       Fish          <-- fish
            //          Salmon
            //          Cod
            //          Mackerel
            //          Cat-fish
            //          Perch
            //       Chicken
            //    Drinks
            //       Alcohol
            //          Vodka
            //       Alcohol-free
            //          Coke
            //             Coka-Cola
            //             Pepsi
            // Rent
            // Clothes
            //    Pants
            // Study
            //    Internet-cources
            //    Books

            {
                Node<QString> *fish_clone = fish->clone(); // cloned nodes are detached from parent

                // Fish          <-- fish_clone
                //    Salmon
                //    Cod
                //    Mackerel
                //    Cat-fish
                //    Perch

                TEST(fish_clone != fish);
                TEST(fish_clone->childCount() == 5);
                TEST(fish_clone->at(0) != fish->at(0));
                TEST(fish_clone->data == fish->data);
                TEST(fish_clone->at(0)->data == fish->at(0)->data);
                TEST(fish_clone->parent == nullptr);
                TEST(fish_clone->data == "Fish");
                TEST(fish_clone->at(0)->data == "Salmon");
                TEST(fish_clone->at(1)->data == "Cod");
                TEST(fish_clone->at(4)->data == "Perch");
                TEST(fish_clone->at(4)->childCount() == 0);

                Tree<QString> fish_tree;
                fish_clone->attachSelfAsChildToBegin(&fish_tree);

                // ""               <-- fish_tree
                //    Fish          <-- fish_clone
                //       Salmon
                //       Cod
                //       Mackerel
                //       Cat-fish
                //       Perch

                TEST(fish_clone->parent == &fish_tree);
                TEST(fish_tree.at(0) == fish_clone);

                Node<QString> *cod = fish_tree.child("Fish")->child("Cod");

                // ""               <-- fish_tree
                //    Fish          <-- fish_clone
                //       Salmon
                //       Cod        <-- cod
                //       Mackerel
                //       Cat-fish
                //       Perch

                TEST(cod == fish_clone->child("Cod"));

                fish_tree.attachChildToEnd(cod);

                // ""               <-- fish_tree
                //    Fish          <-- fish_clone
                //       Salmon
                //       Mackerel
                //       Cat-fish
                //       Perch
                //    Cod           <-- cod

                TEST(fish_clone->childCount() == 4);
                TEST(fish_clone->at(0)->data == "Salmon");
                TEST(fish_clone->at(1)->data == "Mackerel");
                TEST(fish_clone->at(3)->data == "Perch");
                TEST(fish_tree.at(0)->data == "Fish");
                TEST(fish_tree.at(1)->data == "Cod");
                TEST(fish_tree.at(0) == fish_clone);
                TEST(fish_tree.at(1) == cod);
                TEST(cod->parent == &fish_tree);
                TEST(fish_clone->parent == &fish_tree);
                TEST(cod->childCount() == 0);
                TEST(fish_tree.childCount() == 2);
            }

            meat->detach(); // detach meat from t tree

            // t:
            // Food
            //    Bread
            //    Sweets
            //       Ice-Cream
            //       Chocolate
            //       Cookies
            //    Drinks
            //       Alcohol
            //          Vodka
            //       Alcohol-free
            //          Coke
            //             Coka-Cola
            //             Pepsi
            // Rent
            // Clothes
            //    Pants
            // Study
            //    Internet-cources
            //    Books
            //
            //
            // meat:
            // Meat             <-- meat
            //    Pork
            //    Fish          <-- fish
            //       Salmon
            //       Cod
            //       Mackerel
            //       Cat-fish
            //       Perch
            //    Chicken

            TEST(meat->parent == nullptr);
            TEST(fish->parent == meat);
            TEST(t->child("Food")->childCount() == 3);
            TEST(meat->child("Fish")->child("Salmon") == fish->child("Salmon"));
            TEST(t->child("Food")->child("Meat") == nullptr);
            TEST(t->child("Food")->at(1)->data == "Sweets");
            TEST(t->child("Food")->at(2)->data == "Drinks");

            t->child("Food")->attachChildAfter(fish, t->child("Food")->child("Sweets"));
            // attach does:
            // - detach from old parent
            // - attach to new parent

            // t:
            // Food
            //    Bread
            //    Sweets
            //       Ice-Cream
            //       Chocolate
            //       Cookies
            //    Fish          <-- fish
            //       Salmon
            //       Cod
            //       Mackerel
            //       Cat-fish
            //       Perch
            //    Drinks
            //       Alcohol
            //          Vodka
            //       Alcohol-free
            //          Coke
            //             Coka-Cola
            //             Pepsi
            // Rent
            // Clothes
            //    Pants
            // Study
            //    Internet-cources
            //    Books
            //
            //
            // meat:
            // Meat             <-- meat
            //    Pork
            //    Chicken

            TEST(meat->parent == nullptr);
            TEST(fish->parent == t->child("Food"));
            TEST(t->child("Food")->childCount() == 4);
            TEST(meat->childCount() == 2);
            TEST(fish->childCount() == 5);
            TEST(meat->child("Fish") == nullptr);
            TEST(meat->at(0)->data == "Pork");
            TEST(meat->at(1)->data == "Chicken");
            TEST(t->child("Food")->child("Meat") == nullptr);
            TEST(t->child("Food")->child("Fish") == fish);
            TEST(t->child("Food")->at(1)->data == "Sweets");
            TEST(t->child("Food")->at(2)->data == "Fish");
            TEST(t->child("Food")->at(2) == fish);
        }
    }

    t.child("Food")->addChildAt("Milk", 1);

    // Food
    //    Bread
    //    Milk
    //    Sweets
    //       Ice-Cream
    //       Chocolate
    //       Cookies
    //    Meat
    //       Pork
    //       Fish
    //          Salmon
    //          Cod
    //          Mackerel
    //          Cat-fish
    //          Perch
    //       Chicken
    //    Drinks
    //       Alcohol
    //          Vodka
    //       Alcohol-free
    //          Coke
    //             Coka-Cola
    //             Pepsi
    // Rent
    // Clothes
    //    Pants
    // Study
    //    Internet-cources
    //    Books

    TEST(food->at(1)->data == "Milk");
    TEST(food->childCount() == 5);

    t.removeChild("Rent");
    food->removeChildAt(2);

    // Food
    //    Bread
    //    Milk
    //    Meat
    //       Pork
    //       Fish
    //          Salmon
    //          Cod
    //          Mackerel
    //          Cat-fish
    //          Perch
    //       Chicken
    //    Drinks
    //       Alcohol
    //          Vodka
    //       Alcohol-free
    //          Coke
    //             Coka-Cola
    //             Pepsi
    // Clothes
    //    Pants
    // Study
    //    Internet-cources
    //    Books

    TEST(t.childCount() == 3);
    TEST(food->childCount() == 4);
    TEST(t.at(1)->data == "Clothes");
    TEST(food->at(2)->data == "Meat");

    printll("[Tree end]");
}

int main()
{
    printll("Tests start");

    testMoney();
    testTree();

    print("Tests end");
    if(pass) {
        printl("- [PASSED]");
    } else {
        printl("- [FAILED]");
    }

    return 0;
}
