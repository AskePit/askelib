#include "money.h"

Money operator+(const Money &m1, const Money &m2) { return Money(m1.as_cents() + m2.as_cents()); }
Money operator-(const Money &m1, const Money &m2) { return Money(m1.as_cents() - m2.as_cents()); }
Money operator*(const Money &m1, const Money &m2) { return Money(m1.as_cents() * m2.as_cents()); }
Money operator/(const Money &m1, const Money &m2) { return Money(m1.as_cents() / m2.as_cents()); }
Money operator%(const Money &m1, const Money &m2) { return Money(m1.as_cents() % m2.as_cents()); }

bool operator< (const Money &m1, const Money &m2) { return m1.as_cents() <  m2.as_cents(); }
bool operator<=(const Money &m1, const Money &m2) { return m1.as_cents() <= m2.as_cents(); }
bool operator> (const Money &m1, const Money &m2) { return m1.as_cents() >  m2.as_cents(); }
bool operator>=(const Money &m1, const Money &m2) { return m1.as_cents() >= m2.as_cents(); }
