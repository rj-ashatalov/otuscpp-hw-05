#pragma once
#include <sstream>
#include <list>
#include <vector>
#include <iterator>

struct _char_print_tag {};
struct _short_print_tag {};
struct _int_print_tag{};
struct _long_long_print_tag{};
struct _string_print_tag{};
struct _iterable_print_tag{};
struct _default_print_tag{};

template <class T>
struct _print_traits {
    using category = _default_print_tag;
};

template <>
struct _print_traits<char> {
    using category = _char_print_tag;
};

template <>
struct _print_traits<short> {
    using category = _short_print_tag;
};

template <>
struct _print_traits<int> {
    using category = _int_print_tag;
};

template <>
struct _print_traits<long long int> {
    using category = _long_long_print_tag;
};

template <>
struct _print_traits<std::string> {
    using category = _string_print_tag;
};

template <class T, class U>
struct _print_traits<std::vector<T, U>> {
    using category = _iterable_print_tag;
};

template <class T, class U>
struct _print_traits<std::list<T, U>> {
    using category = _iterable_print_tag;
};

///

template<class T>
std::string toStringInternal(T&& src, _default_print_tag)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return "incompatible type";
}

template<class T>
std::string toStringInternal(T&& src, _char_print_tag)
{
    return std::to_string(static_cast<unsigned char>(src));
}

template<class T>
std::string toStringInternal(T&& src, _short_print_tag)
{
    //todo
    return "";
}

template<class T>
std::string toStringInternal(T&& src, _int_print_tag)
{
    //todo
    return "";
}

template<class T>
std::string toStringInternal(T&& src, _long_long_print_tag)
{
    //todo
    return "";
}

template<class T>
std::string toStringInternal(T&& src, _string_print_tag)
{
    return src;
}

template<class T>
std::string toStringInternal(T&& src, _iterable_print_tag)
{
    if (src.size() <= 0) {
        return "";
    }

    std::stringstream output;
    std::copy(src.begin(), std::prev(src.end()), std::ostream_iterator<typename std::remove_reference_t<T>::value_type>(output, "."));
    output << src.back();
    return output.str();
}


template<class T>
std::string toString(T&& src)
{
    return toStringInternal(std::forward<T>(src), typename _print_traits<typename std::remove_reference_t<T>>::category());
}
