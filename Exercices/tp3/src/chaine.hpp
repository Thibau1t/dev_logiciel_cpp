#ifndef __ZZ3_CPP_CHAINE__
#define __ZZ3_CPP_CHAINE__

#include <string>
#include <typeinfo>
#include <sstream>
#include <tuple>

#include "exceptionChaine.hpp"

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

#endif