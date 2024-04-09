#include "BitcoinExchange.hpp"
#include <cstdlib>
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
    (void )rhs;
    //*this = rhs;
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

void BitcoinExchange::checkInput(std::string &path)
{
    std::ifstream inFile;
    std::string line = "";
    std::string date = "";
    bool firstLine = true;
    std::string  value = "";
    inFile.open(path.c_str(), std::ifstream::in);
    if (!inFile.is_open())
        throw InvalidFilePath();
    while (!inFile.eof())
    {
        getline(inFile, line);
        if (firstLine == true)
        {
            if (line != "date | value")
                throw BadFormat();
            firstLine = false;
        }
        else
        {
            if (line.find("|") == line.npos || line.empty() || line.find("|") != 11)
            {
                std::cout << "Error: invalid format" << std::endl;
            }
            else
            {
                if (line[0] != '\n')
                {
                    date = line.substr(0, line.find("|") -1);
                    if(!::BitcoinExchange::checkDate(date))
                    {
                        std::cout << "Error: invalid format" << std::endl;
                        continue;
                    }

                    value = line.substr(line.find("|") + 2, line.length());
                    // if (!::BitcoinExchange::checkValue(value))
                    // {
                    //     std::cerr << "Error: invalid format" <<std::endl;
                    //     continue ;
                    // }
                    //std::cout << value << std::endl;
                }
            }
        }
    }
}

bool BitcoinExchange::checkDate(std::string date)
{
    std::string year = "";
    std::string month = "";
    std::string day = "";

   year = date.substr(0, date.find("-"));
   if (year.length() != 4)
   {
       return false;
   }
   month = date.substr(date.find("-") + 1, date.find("-") -2);
   //std::cout << month <<std::endl;
   day = date.substr(date.rfind("-") + 1,date.rfind("-") +2);
   std::cout << day << std::endl;

   return (true);
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
const char *BitcoinExchange::BadInput::what() const throw()
{
    return ("Error : bad input ");
}

const char *BitcoinExchange::BadFormat::what() const throw()
{
    return ("invalid file format");
}
/* ************************************************************************** */
