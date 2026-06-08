#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {
	_readDB();
}

BitcoinExchange::~BitcoinExchange() {
	// Destructor implementation
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	if (this != &other) 
		*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_quotesDB = other._quotesDB;
	return *this;
}

void BitcoinExchange::execute(const std::string& inputFile) {

	std::ifstream file(inputFile);
	if (!file.is_open())
		throw FileException();
	
	std::string line;
	// check is the first line is "date | value"
	std::getline(file, line);
	if (line != "date | value")
		throw FileException();

	while (std::getline(file,line))
	{
		std::string date;
		std::string value;
		double priceValue;
		std::istringstream ss(line); // line is the string but getline reads from a stream 
		std::getline(ss, date, '|');
		std::getline(ss, value, '|');

		// validate date 
		// validate value
		// convert the value to double and calculate. use lowest date if no specificed date
		if (date.empty() || value.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; // skip this line and continue with the next one
		}
		
		if(!date.empty())
			date.erase(date.length() - 1); // remove trailing space
		
		if(!validateDate(date))
		{
			std::cerr << "Error: Invalid date format in line: " << line << std::endl;
			continue; // skip this line and continue with the next one
		}

		if (!value.empty())
			value.erase(0,1); // remove leading space
		
		if ((priceValue = validateAmmount(value)) != -1)
		{
			calculate(date, priceValue);
		}


	}

	file.close();
}

bool BitcoinExchange::validateDate(const std::string& date)
{
	// Check basic format: YYYY-MM-DD (10 chars with hyphens at positions 4 and 7)
	if (date.length() != 10)
		return (false);
	if (date.at(4) != '-' || date.at(7) != '-')
		return (false);
	
	// Verify all positions except hyphens contain digits
	for (size_t idx = 0; idx < date.length(); idx++)
	{
		if (idx == 4 || idx == 7)
			continue;
		if (!std::isdigit(date[idx]))
			return (false);
	}

	// Validate month (01-12)
	char monthFirst = date[5];
	char monthSecond = date[6];
	if (monthFirst < '0' || monthFirst > '1')
		return (false);
	if (monthFirst == '1' && monthSecond > '2')
		return (false);
	if (monthFirst == '0' && monthSecond < '1')
		return (false);

	// Validate day (01-31)
	char dayFirst = date[8];
	char daySecond = date[9];
	if (dayFirst < '0' || dayFirst > '3')
		return (false);
	if (dayFirst == '3' && daySecond > '1')
		return (false);
	if (dayFirst == '0' && daySecond < '1')
		return (false);
	
	return (true);
}



double BitcoinExchange::validateAmmount(const std::string& amount)
{
	double ret;
	std::istringstream ss(amount);
	// Try to convert the string amount to a double and store bytes in ret. if it fails, it will return false
	if (!(ss >> ret))
	{
		std::cerr << "Error: Invalid amount format: " << amount << std::endl;
		return -1;
	}
	if (ret < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	if (ret > 1000)
	{
		std::cerr << "Error: too large a number." <<  std::endl;
		return -1;
	}
	return ret;
}

void BitcoinExchange::calculate(const std::string& date, double value)
{
	std::map<std::string, double>::iterator it = _quotesDB.upper_bound(date);
	if (it == _quotesDB.begin())
	{
		std::cerr << "Error: No exchange rate available for date: " << date << std::endl;
		return;
	}

	--it;

	double exchangeRate = it->second;
	double result = value * exchangeRate;

	std::cout << date << " => " << value << " = " << result << std::endl;
}

// _quotesDB["2023-01-01"] = 50000.11;
// _quotesDB["2023-01-02"] = 51000.22;
// _quotesDB["2023-01-03"] = 52000.33;
void BitcoinExchange::_readDB()
{

	std::ifstream file("data.csv");
	std::string line;

	if (!file.is_open())
		throw FileException();

	std::getline(file, line);
	if (line != "date,exchange_rate")
	   	throw FileException();
	
	while (std::getline(file, line))
	{
		std::string date;
		std::string price;


		// we use istringstream to parse the line into getline
		// because we can't use getline directly on the line string, we need to use a stringstream to read from it
		// getline reads until it finds a delimiter, and we want to read until we find a comma, not until the end of the line
		// we create a stringstream object because getline reads from a stream not a string, so we need to create a stream from the line string
		// we can call it "converter" because it converts the line string into a stream that we can read from

		std::istringstream ss(line); 
		std::getline(ss, date, ',');
		std::getline(ss, price, ',');

		double priceValue; 
		std::istringstream priceStream(price);
		if (!(priceStream >> priceValue))
			throw FileException();
		_quotesDB[date] = priceValue;
	}

	file.close();
}