#ifndef __ZZ3_CPP_EXCPETION_CHAINE__
#define __ZZ3_CPP_EXCPETION_CHAINE__

#include <exception>
#include <string>

class ExceptionChaine : public std::exception
{
private:
    std::string _message;

public:
    template <typename T>
    ExceptionChaine(const T &type)
    {
        _message = "Conversion en chaine impossible pour '" + demangle(typeid(type).name()) + "'";
    }

    const char *what() const noexcept override
    {
        return _message.c_str();
    }
};

#endif