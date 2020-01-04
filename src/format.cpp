#include <string>
#include <time.h>
#include<sstream>
#include <iomanip>
#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds[[maybe_unused]]) {
    try {
        time_t tSeconds(seconds);
        tm *time = gmtime(&tSeconds);
        if (time == nullptr) {
            return "00:00:00";
        }
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << time->tm_hour << ":"
           << std::setfill('0') << std::setw(2) << time->tm_min << ":"
           << std::setfill('0') << std::setw(2) << time->tm_sec;
        return ss.str();
    } catch (...) {
        return "00:00:00";
    }
}