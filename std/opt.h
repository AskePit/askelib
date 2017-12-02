#ifndef ASKELIB_STD_OPT_H
#define ASKELIB_STD_OPT_H

#include <utility>

namespace aske {

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

    operator bool() const { return m_initialized; }
    T &get() { return m_val; }
    const T &get() const { return m_val; }
    T get_or(T def) const { return m_initialized? m_val : def; }

private:
    bool m_initialized {false};
    T m_val;
};

} // namespace aske

#endif //ASKELIB_STD_OPT_H
