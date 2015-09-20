#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <list>
#include <utility>
#include <string>
#include <chrono>

class ErrorHandler
{
public:
    static ErrorHandler* instance() {
        static ErrorHandlerGuard guard;

        if (!myInstance)
            myInstance = new ErrorHandler();

        return myInstance;
    }

    void addError(std::string errorMessage);
    std::list<std::pair<std::chrono::system_clock::time_point, std::string> > getErrors();
    static std::string timeString(std::chrono::system_clock::time_point time);

private:
    static ErrorHandler* myInstance;

    ErrorHandler() {}
    ErrorHandler(const ErrorHandler&);
    ~ErrorHandler() {}

    class ErrorHandlerGuard {
    public:
        ~ErrorHandlerGuard() {
            if (0 != ErrorHandler::myInstance) {
                delete ErrorHandler::myInstance;
                ErrorHandler::myInstance = 0;
            }
        }
    };
    friend class ErrorHandlerGuard;

    std::list<std::pair<std::chrono::system_clock::time_point, std::string> > errorList;
};

#endif // ERRORHANDLER_H
