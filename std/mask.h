#ifndef ASKELIB_STD_MASK_H
#define ASKELIB_STD_MASK_H

#include "opt.h"
#include <bitset>

namespace aske {

template <typename base_type = unsigned long>
class mask {
public:
    mask(base_type val)
        : m(val)
    {}
    mask(const mask &other)
        : m(other.m)
    {}
    mask &operator=(base_type val) {
        m = val; return *this;
    }

    bool operator&(base_type t) const { return !!(m & t); }
    bool test(base_type t) const { return *this & t; }
    bool hasNo(base_type t) const { return !(*this & t); }

    mask &operator|=(base_type t) {
        m |= t;
        return *this;
    }

    mask &set(base_type t) { return *this |= t; }

    mask &clear() {
        m = 0;
        return *this;
    }

    mask &clear(base_type t) {
        m & (~t);
        return this;
    }

    size_t count() const {
        std::bitset<sizeof(base_type)*CHAR_BIT> bits(m);
        return bits.count();
    }

    opt<base_type> unique() {
        opt<base_type> u;
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
