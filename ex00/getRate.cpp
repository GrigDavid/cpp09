#include "btc.hpp"

double getRate(std::map<std::string, double> rates, const std::string &date)
{
	std::map<std::string, double>::iterator it = rates.upper_bound(date);

	if (it == rates.begin())
	{
		throw std::runtime_error("Error: Invalid date.");
	}
	return ((--it)->second);
}