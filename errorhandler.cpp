#include "errorhandler.h"

#include <ctime>
#include <algorithm>

ErrorHandler* ErrorHandler::myInstance = 0;

void ErrorHandler::addError(std::string errorMessage) {
    std::chrono::system_clock::time_point currentTime;

    currentTime = std::chrono::system_clock::now();
    errorList.push_front(std::pair<std::chrono::system_clock::time_point, std::string>(currentTime, errorMessage));
}

std::list<std::pair<std::chrono::system_clock::time_point, std::string> > ErrorHandler::getErrors() {
    return errorList;
}

std::string ErrorHandler::timeString(std::chrono::system_clock::time_point time) {
    std::time_t cTime = std::chrono::system_clock::to_time_t(time);
    std::string timeString = std::ctime(&cTime);

    timeString.erase(std::find_if(timeString.rbegin(), timeString.rend(),
        std::ptr_fun<int, int>(std::isgraph)).base(), timeString.end());

    return timeString;
}
