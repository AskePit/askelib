#include "money.h"

Money operator+(const Money &m1, const Money &m2) { return Money(m1.as_cents() + m2.as_cents()); }
Money operator-(const Money &m1, const Money &m2) { return Money(m1.as_cents() - m2.as_cents()); }
Money operator*(const Money &m1, const Money &m2) { return Money(m1.as_cents() * m2.as_cents()); }
Money operator/(const Money &m1, const Money &m2) { return Money(m1.as_cents() / m2.as_cents()); }
Money operator%(const Money &m1, const Money &m2) { return Money(m1.as_cents() % m2.as_cents()); }

Money operator+(double m1, const Money &m2) { return Money(m1) + m2; }
Money operator-(double m1, const Money &m2) { return Money(m1) - m2; }
Money operator*(double m1, const Money &m2) { return Money(m1) * m2; }
Money operator/(double m1, const Money &m2) { return Money(m1) / m2; }
Money operator%(double m1, const Money &m2) { return Money(m1) % m2; }

Money operator+(const Money &m1, double m2) { return m1 + Money(m2); }
Money operator-(const Money &m1, double m2) { return m1 - Money(m2); }
Money operator*(const Money &m1, double m2) { return m1 * Money(m2); }
Money operator/(const Money &m1, double m2) { return m1 / Money(m2); }
Money operator%(const Money &m1, double m2) { return m1 % Money(m2); }
