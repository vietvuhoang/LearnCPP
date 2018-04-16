#ifndef _APP_EXCEPTION_HPP_
#define _APP_EXCEPTION_HPP_
#include <stdexcept>
#include <string>

class AppException : public std::exception
{
  private:
    std::string message;

  public:
    AppException(const std::string &message) : message(message)
    {
    }

    virtual ~AppException() throw()
    {
    }

    virtual const char *what() const throw()
    {
        return message.c_str();
    }
};

#endif
