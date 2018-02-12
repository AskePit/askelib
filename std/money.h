/*! @file
 *
 * Simple money type.
 *
 */

#ifndef ASKELIB_STD_DECIMAL_H
#define ASKELIB_STD_DECIMAL_H

#include <stdint.h>
#include <cassert>
#include <utility>
#include <QString>

class Currency
{
public:

    enum t {
        Rub,
        Usd,
        Eur,
        Btc,
    };

    static QString symbol(Currency::t type) {
        switch(type) {
            default:
            case Rub: return "₽";
            case Usd: return "$";
            case Eur: return "€";
            case Btc: return "฿";
        }
    }
};

class Money {
public:
    typedef std::pair<intmax_t, intmax_t> money_pair;

    // creation
    Money()
    {}

    Money(intmax_t units, intmax_t cents)
        : m_amount(units*m_centsPerUnit + cents)
    {}

    explicit Money(intmax_t cents)
        : m_amount(cents)
    {}

    Money(double value)
    {
        double cents = value*m_centsPerUnit;
        cents = round(cents*m_centsPerUnit)/m_centsPerUnit; // round hack
        m_amount = intmax_t(cents);
    }

    friend void swap(Money& first, Money& second) // nothrow
    {
        using std::swap;

        swap(first.m_amount, second.m_amount);
        swap(first.m_currency, second.m_currency);
        swap(first.m_centsPerUnit, second.m_centsPerUnit);
    }

    Money(const Money &other)
        : m_amount(other.m_amount)
        , m_currency(other.m_currency)
        , m_centsPerUnit(other.m_centsPerUnit)
    {}

    Money(Money &&other)
        : Money()
    {
        swap(*this, other);
    }

    Money &operator=(Money other)
    {
        swap(*this, other);
        return *this;
    }

    // casts
    explicit operator double() const
    {
        return m_amount/(double)m_centsPerUnit;
    }

    intmax_t units() const
    {
        return m_amount/m_centsPerUnit;
    }

    intmax_t cents() const
    {
        return m_amount%m_centsPerUnit;
    }

    intmax_t as_cents() const
    {
        return m_amount;
    }

    int centsPerUnit() const
    {
        return m_centsPerUnit;
    }

    std::pair<intmax_t, intmax_t> units_cents() const
    {
        return {units(), cents()};
    }

    Currency::t currency() const
    {
        return m_currency;
    }

    void setCurrency(Currency::t currency)
    {
        m_currency = currency;
    }

    // arithmetic
    Money &operator+=(const Money &other) { m_amount += other.m_amount; return *this; }
    Money &operator-=(const Money &other) { m_amount -= other.m_amount; return *this; }
    Money &operator*=(double mult) { m_amount = intmax_t(m_amount*mult); return *this; }
    Money &operator/=(double div) { m_amount = intmax_t(m_amount/div); return *this; }
    Money &operator%=(intmax_t div) { m_amount %= div; return *this; }

    bool operator==(const Money &other) const
    {
        return m_amount == other.m_amount
            && m_currency == other.m_currency
            && m_centsPerUnit == other.m_centsPerUnit;
    }
    bool operator!=(const Money &other) const { return !((*this) == other); }
    bool operator< (const Money &other) const { return m_amount <  other.m_amount; }
    bool operator<=(const Money &other) const { return m_amount <= other.m_amount; }
    bool operator> (const Money &other) const { return m_amount >  other.m_amount; }
    bool operator>=(const Money &other) const { return m_amount >= other.m_amount; }

    bool operator==(double other) const { return (double)m_amount == other; }
    bool operator!=(double other) const { return (double)m_amount != other; }
    bool operator< (double other) const { return (double)m_amount <  other; }
    bool operator<=(double other) const { return (double)m_amount <= other; }
    bool operator> (double other) const { return (double)m_amount >  other; }
    bool operator>=(double other) const { return (double)m_amount >= other; }

private:
    intmax_t m_amount {0};
    Currency::t m_currency {Currency::Rub};
    int m_centsPerUnit {100};
};

Money operator+(const Money &m1, const Money &m2);
Money operator-(const Money &m1, const Money &m2);
Money operator*(const Money &m1, const Money &m2);
Money operator/(const Money &m1, const Money &m2);
Money operator%(const Money &m1, const Money &m2);

Money operator+(double m1, const Money &m2);
Money operator-(double m1, const Money &m2);
Money operator*(double m1, const Money &m2);
Money operator/(double m1, const Money &m2);
Money operator%(double m1, const Money &m2);

Money operator+(const Money &m1, double m2);
Money operator-(const Money &m1, double m2);
Money operator*(const Money &m1, double m2);
Money operator/(const Money &m1, double m2);
Money operator%(const Money &m1, double m2);

#endif //ASKELIB_STD_DECIMAL_H
