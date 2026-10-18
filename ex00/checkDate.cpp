#include "btc.hpp"

bool checkDate(const std::string &date)
{
	return (date == date);
}
//generated with claude, re-write later
//static bool isLeapYear(int year)
//{
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}

//bool checkDate(const std::string &date)
//{
//    // Format: YYYY-MM-DD (exactly 10 chars)
//    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
//        return false;

//    // All other positions must be digits
//    for (size_t i = 0; i < date.length(); ++i)
//    {
//        if (i == 4 || i == 7)
//            continue;
//        if (date[i] < '0' || date[i] > '9')
//            return false;
//    }

//    int year  = std::atoi(date.substr(0, 4).c_str());
//    int month = std::atoi(date.substr(5, 2).c_str());
//    int day   = std::atoi(date.substr(8, 2).c_str());

//    if (year < 1 || month < 1 || month > 12 || day < 1)
//        return false;

//    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//    if (month == 2 && isLeapYear(year))
//        daysInMonth[1] = 29;

//    return day <= daysInMonth[month - 1];
//}