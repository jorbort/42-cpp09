#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
    try
    {
        this->parseDataBase();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    this->dataBase = src.dataBase;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
    dataBase.empty();
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    *this = rhs;
    return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::parseDataBase()
{
    std::ifstream dbFile;
    std::string date = "";
	std::string line = "";
	float value = 0.0;
    bool firstLine = true;
    dbFile.open("/Users/jbortolo/Desktop/42-cpp09/ex00/data.csv", std::ifstream::in);
    if (!dbFile.is_open())
        throw InvalidFilePath();
    while (!dbFile.eof())
    {
        getline(dbFile, line);
        if (firstLine == true)
        {
            if (line != "date,exchange_rate")
                throw BadFormat();
			firstLine = false;
        }
		else 
		{
			date = line.substr(0, line.find(","));
			value = atof(line.substr(line.find(",")+1 ,line.length()).c_str());
			dataBase.insert(std::make_pair(date,value));
		}
    }
	dbFile.close();
}

void BitcoinExchange::checkDates(std::string &path)
{
    std::ifstream inFile;
    inFile.open(path.c_str(), std::ifstream::in);
    if (!inFile.is_open())
        throw InvalidFilePath();

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/*exceptions */

const char *BitcoinExchange::InvalidFilePath::what() const  throw()
{
    return ("file can't be opened either for wrong permits or wrong path");
}

const char *BitcoinExchange::toLargeException::what() const throw()
{
    return ("Error: too large a number");
}
const char *BitcoinExchange::notApositiveNumber::what() const throw()
{
    return ("Error: not a positive number");
}
const char *BitcoinExchange::BadInput::what(std::string input) const throw()
{
    std::string err = "Error bad input => " + input;
    const char *ret = err.c_str();
    return (ret);
}

const char *BitcoinExchange::BadFormat::what() const throw()
{
    return ("invalid file format");
}
/* ************************************************************************** */
