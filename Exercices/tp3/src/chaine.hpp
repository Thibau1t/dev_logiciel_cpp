#ifndef __ZZ3_CPP_CHAINE__
#define __ZZ3_CPP_CHAINE__

#include <string>
#include <typeinfo>
#include <sstream>
#include <tuple>

#include "exceptionChaine.hpp"

// Declaration des prototype cf question 5
template <typename T>
std::string chaine(const T &);

template <>
std::string chaine(const int &);

template <>
std::string chaine(const std::string &);

template <>
std::string chaine(const double &);

template <typename T, typename... Args>
std::string chaine(const T &, const Args &...);

template <typename Tuple, std::size_t... Is>
std::string chaine_rec(const Tuple &, std::index_sequence<Is...>);

template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> &);

// Implementation
template <typename T>
std::string chaine(const T &x)
{
    throw ExceptionChaine(x);
}

template <>
std::string chaine(const int &x)
{
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template <>
std::string chaine(const std::string &x)
{
    return x;
}

template <>
std::string chaine(const double &x)
{
    return std::to_string(x);
}

template <typename T, typename... Args>
std::string chaine(const T &first, const Args &...args)
{
    return chaine(first) + " " + chaine(args...);
    // return chaine(first) + (sizeof...(args) > 0 ? " " + chaine(args...) : "");
}

// variadic tuple
template <typename Tuple, std::size_t... Is>
std::string chaine_rec(const Tuple &t, std::index_sequence<Is...>)
{
    return chaine(std::get<Is>(t)...);
}

template <typename... ARGS>
std::string chaine(const std::tuple<ARGS...> &t)
{
    return chaine_rec(t, std::make_index_sequence<sizeof...(ARGS)>());
}

#endif