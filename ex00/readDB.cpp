#include "btc.hpp"

static double	readRate(const std::string& rate)
{
	double res;
	char *endptr;
	errno = 0;
	res = std::strtod(rate.c_str(), &endptr);
	if (*endptr || errno == ERANGE){

		std::cout << rate << std::endl;
		throw std::runtime_error("Error: Data format is wrong.");}
	
	return (res);
}

static void	addToMap(std::map<std::string, double>& database, const std::string& buf, std::string sep)
{
	std::size_t sepPos;
	sepPos = buf.find(sep);
	if (sepPos == std::string::npos)
		throw std::runtime_error("Error: Data format is wrong.");
	std::string date = buf.substr(0, sepPos);
	std::string rate = buf.substr(sepPos + sep.length(), buf.length() - sepPos - sep.length());
	if (!checkDate(date))
	{
		throw std::runtime_error("Error: Data format is wrong.");
	}
	database[date] = readRate(rate);
}

std::map<std::string, double> readDB(const std::string &name, std::string sep)
{
	std::ifstream inputFile(name.c_str());

	if (!inputFile)
	{
		throw std::runtime_error("Error: could not open file " + name + ".");
	}

	std::string buf;
	std::map<std::string, double> database;
	if (sep == ",")
	{
		if (!std::getline(inputFile, buf))
			throw std::runtime_error("Error: Empty file.");
		if (buf.find("date") != 0 || buf.find("exchange_rate") != buf.length() - std::strlen("exchange_rate")){//
			throw std::runtime_error("Error: Wrong file format.");
		}
		sep = buf.substr(4, buf.find("exchange_rate") - 4);
		//if (buf != "date,exchange_rate")//maybe use the separator in the first line?
		//	throw std::runtime_error("Error: Wrong file format.");
	}
	while (std::getline(inputFile, buf))
	{
		addToMap(database, buf, sep);
	}
	if (database.empty())
		throw std::runtime_error("Error: Empty file.");
	return (database);
}