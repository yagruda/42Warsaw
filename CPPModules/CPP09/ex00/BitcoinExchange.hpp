#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> _quotesDB; // Database to store date and corresponding Bitcoin price
    void _readDB(); 
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void execute(const std::string& inputFile);
    bool validateDate(const std::string& date);
    double validateAmmount(const std::string& amount);
    void calculate(const std::string& date, double value);

    std::map<std::string, double> getQuotesDB() const { return _quotesDB; }
    
    // Exception class for file opening errors
    class FileException : public std::exception 
    {
        public: 
            virtual const char* what() const throw()
            {
                return ("Here's some issues with the file you provided. Please check the file and try again.");
            }
    };

};

#endif
