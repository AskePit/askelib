//! @file

#ifndef ASKELIB_STD_OPT_H
#define ASKELIB_STD_OPT_H

#include <utility>

namespace aske {

/*!
 * @brief Simple class for optional values.
 *
 * @details
 * The simplest nonoptimized optional implementation.
 * Contained value should be default-constructible.
 *
 * If you have C++17 support, please use `std::optional` instead.
 * If your compiler has `std::experimental::optional` support, please use it instead.
 * If you have boost support, please use `boost::optional` instead.
 *
 * @tparam T Contained (or not contained) value. Should be default-constructible.
 */
template <typename T>
class opt {
public:
    opt()
        : m_initialized(false)
        , m_val(T())
    {}

    opt(T val)
        : m_initialized(true)
        , m_val(val)
    {}

    opt(const opt &other)
        : m_initialized(other.m_initialized)
        , m_val(other.m_val)
    {}

    opt(opt &&other)
        : m_initialized(other.m_initialized)
        , m_val(std::move(other.m_val))
    {}

    opt &operator=(T val) {
        m_val = val;
        m_initialized = true;
        return *this;
    }

    /*! Returns if `optional` contains value */
    operator bool() const { return m_initialized; }

    /*! Returns value if it exists. Otherwise returns default-constructed value. */
    T &get() { return m_val; }

    /*! Returns constant value if it exists. Otherwise returns default-constructed value. */
    const T &get() const { return m_val; }

    /*! Returns value if it exists. Otherwise returns `def`. */
    T get_or(T def) const { return m_initialized? m_val : def; }

private:
    bool m_initialized {false};
    T m_val;
};

} // namespace aske

#endif //ASKELIB_STD_OPT_H
