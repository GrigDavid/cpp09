#include "btc.hpp"


std::map<std::string, double> readDB(const std::string &name)
{
	std::ifstream inputFile(name.c_str());

	if (!inputFile)
	{
		throw std::runtime_error("Error: could not open file " + name + ".");
	}

	std::string buf;
	std::map<std::string, double> database;
	while (!std::getline(inputFile, buf))
	{
		if (!checkDate(buf))
		{
			throw std::runtime_error("Error: Data format is wrong.");
		}
		database[buf] = 0;//cut buf to two parts, atof the right side
	}
	return (database);
}