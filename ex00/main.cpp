#include "btc.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}

	std::map<std::string, double> rates;
	std::map<std::string, double> inputFile;

	try
	{
		rates = readDB("./cpp_09/data.csv");
		inputFile = readDB((std::string)argv[1]);

		for (std::map<std::string, double>::iterator it = inputFile.begin(); it != inputFile.end(); ++it)
		{
			std::cout << it->first << " => " << getRate(rates, it->first) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}


	
}