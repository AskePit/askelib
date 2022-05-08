//! @file

#ifndef ASKELIB_STD_MASK_H
#define ASKELIB_STD_MASK_H

#include <bitset>
#include <optional>

namespace aske {

/*!
 * @brief Bitmap mask class.
 *
 * @details
 * Thin wrapper around integer value used as a bitmap mask for collection of
 * bits, enum values etc.
 *
 * Very similar to `std::bistet` but works with real bits' values instead of
 * their ordered numbers.
 *
 * Ex.:
 * @code{.cpp}
 * std::bitset<32> b;
 * b.set(3);
 * @endcode
 *
 * is equal to
 *
 * @code{.cpp}
 * aske::mask b;
 * b.set(1<<3);
 * @endcode
 *
 * Also, in addition to common `set`, `test`, `clear` functions it has such
 * handy fuctions as `count` (returns count of bits) or `unique` (returns if
 * this mask has only one bit set).
 *
 * @tparam base_type Type of mask integer value. Default type `unsigned long`.
 */
template <typename base_type = unsigned long>
class mask {
public:
    mask(base_type val)
        : m(val)
    {}
    mask(const mask &other)
        : m(other.m)
    {}
    mask &operator=(const mask& other) {
        m = other.m; return *this;
    }
    mask &operator=(base_type val) {
        m = val; return *this;
    }

    /*!
     * Tests if bit(s) `t` is(are) set.
     * @sa test
     */
    bool operator&(base_type t) const { return !!(m & t); }

    /*!
     * Tests if bit(s) `t` is(are) set.
     * @sa operator&
     */
    bool test(base_type t) const { return *this & t; }

    /*!
     * Tests if bit(s) `t` is(are) not set.
     * @sa operator&
     * @sa test
     */
    bool hasNo(base_type t) const { return !(*this & t); }

    /*!
     * Sets bit(s) `t` to mask.
     * @sa set
     */
    mask &operator|=(base_type t) {
        m |= t;
        return *this;
    }

    /*!
     * Sets bit(s) `t` to mask.
     * @sa operator|=
     */
    mask &set(base_type t) { return *this |= t; }

    /*!
     * Clears mask.
     * @sa clear(base_type t)
     */
    mask &clear() {
        m = 0;
        return *this;
    }

    /*!
     * Clears bit(s) `t`.
     * @sa clear()
     */
    mask &clear(base_type t) {
        m & (~t);
        return this;
    }

    /*! Returns mask's bit count. */
    size_t count() const {
        std::bitset<sizeof(base_type)*CHAR_BIT> bits(m);
        return bits.count();
    }

    /*! Retuns if mask has only one bit set. */
    std::optional<base_type> unique() {
        std::optional<base_type> u;
        if(count() == 1) {
            u = m;
        }
        return u;
    }

private:
    base_type m {0};
};

} // namespace aske

#endif //ASKELIB_STD_MASK_H
