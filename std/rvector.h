/*! @file
 *
 * Reverse vector class.
 *
 */

#ifndef ASKELIB_STD_RVECTOR_H
#define ASKELIB_STD_RVECTOR_H

#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

/*!
 * @brief   Vector container that grows from front.
 * @details Container has very fast push_front() function.
 *          Actually this class is a wrapper around usual std::vector
 *          with remapped indexing.
 */
namespace aske {

template <class T>
class rvector
{
public:
    rvector() {}

    explicit rvector (size_t n)
        : m_v(n) {}

    rvector(const rvector &other)
        : m_v(other.m_v) {}

    rvector(rvector &&other)
        : m_v(other.m_v) {}

    rvector(const std::vector<T> &other)
        : m_v(other.size())
    {
        std::reverse_copy(other.begin(), other.end(), m_v.begin());
    }

    rvector(std::vector<T> &&other)
        : m_v(other)
    {
        std::reverse(m_v.begin(), m_v.end());
    }

    void push_front(const T &val) {
        m_v.push_back(val);
    }

    void push_front(T &&val) {
        m_v.push_back(std::forward(val));
    }

    void pop_front() {
        m_v.pop_back();
    }

    size_t size() const noexcept {
        return m_v.size();
    }

    T &at(size_t n) {
        return m_v.at(mapIndex(n));
    }

    const T &at(size_t n) const {
        return m_v.at(mapIndex(n));
    }

    T &operator[](size_t n) {
        return m_v[mapIndex(n)];
    }

    const T &operator[](size_t n) const {
        return m_v[mapIndex(n)];
    }

    bool empty() const noexcept {
        return m_v.empty();
    }

    void clear() noexcept {
        m_v.clear();
    }

    void insert(size_t position, const T& val) {
        m_v.insert(std::next(m_v.begin(), mapIndex(position)+1), val);
    }

    void insert(size_t position, size_t n, const T& val) {
        m_v.insert(std::next(m_v.begin(), mapIndex(position)+1), n, val);
    }

    void remove(size_t position) {
        auto it = std::next(m_v.begin(), mapIndex(position));
        m_v.erase(it);
    }

    void remove(size_t position, size_t n) {
        auto first = std::next(m_v.begin(), mapIndex(position));
        auto last = std::next(m_v.begin(), mapIndex(position+n-1));
        m_v.erase(first, last);
    }

    typename std::vector<T>::reverse_iterator begin() noexcept {
        return m_v.rbegin();
    }

    typename std::vector<T>::const_reverse_iterator begin() const noexcept {
        return m_v.rbegin();
    }

    typename std::vector<T>::reverse_iterator end() noexcept {
        return m_v.rend();
    }

    typename std::vector<T>::const_reverse_iterator end() const noexcept {
        return m_v.rend();
    }

private:
    std::vector<T> m_v;

    size_t mapIndex(size_t index) const {
        return m_v.size() - index - 1;
    }
};

}

#endif // ASKELIB_STD_RVECTOR_H
