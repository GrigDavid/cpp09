#ifndef BTC_HPP
# define BTC_HPP

# include <iostream>
# include <string>
# include <bits/stdc++.h>//getline
# include <map>
# include <fstream>
# include <exception>
# include <iomanip>

bool checkDate(const std::string &date);
std::map<std::string, double> readDB(const std::string &name, std::string sep);
double getRate(std::map<std::string, double> rates, const std::string &date);

#endif