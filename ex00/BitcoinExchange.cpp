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
    badInput = "";
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
    {
		 throw InvalidFilePath();
	}
    while (!dbFile.eof())
    {
        getline(dbFile, line);
        if (firstLine == true)
        {
            if (line != "date,exchange_rate")
                throw BadInput();
			firstLine = false;
        }
        else
		{
			date = line.substr(0, line.find(","));
			value = std::atof(line.substr(line.find(",")+1 ,line.length()).c_str());
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
                throw BadInput();
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
                    value = line.substr(line.find("|") + 2, line.length());
                    try
                    {
                        BitcoinExchange::checkDate(date);
                        BitcoinExchange::checkValue(value);
                        BitcoinExchange::formatedPrint(date, std::atof(value.c_str()));
                    }
                    catch(std::exception &e)
                    {
                        std::cout << e.what()  << this->badInput << std::endl; ;
                    }
                }
            }
        }
    }
    inFile.close();
}

void BitcoinExchange::checkDate(std::string date)
{
    std::string year = "";
    std::string month = "";
    std::string day = "";
   year = date.substr(0, date.find("-"));
   if (year.length() != 4)
   {
       throw tooLargeException();
   }
   month = date.substr(date.find("-") + 1, date.find("-") -2);
	int checkMonth = std::atoi(month.c_str());
	if (month.length() != 2 || checkMonth <= 0 || checkMonth > 12)
	{
	   this->badInput = date;
	   throw BadInput();
	}
   day = date.substr(date.rfind("-") + 1,date.rfind("-") +2);
   int checkDay = std::atoi(day.c_str());
   if (day.length() != 2)
   {
       this->badInput = date;
       throw BadInput();
   }
   try
   {
       BitcoinExchange::checkDay(checkDay, checkMonth);
   }
   catch(std::exception &e)
   {
       std::cout << e.what()  << date << std::endl;
   }
}

void BitcoinExchange::checkDay(int day , int month)
{
	if (day <= 0)
		throw BadInput();
	if (month == 2 && day > 28)
	   throw BadInput();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BadInput();
	else if (day > 31)
		throw BadInput();
}

void BitcoinExchange::checkValue(std::string value)
{
	if (value.length() > 4)
	{
	   throw tooLargeException();
	}
	float checkValue = std::atof(value.c_str());
	if (checkValue > 1000.0)
    {
        throw tooLargeException();
    }
	else if(checkValue < 0.0)
	{
	   throw notApositiveNumber();
	}
}

void BitcoinExchange::formatedPrint(std::string date, float value)
{
    std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
    if (it == dataBase.end())
    {
        it--;
    }
    std::cout << it->first << " => " << value << " = "<< (value * it->second) << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/*exceptions */

const char *BitcoinExchange::InvalidFilePath::what() const  throw()
{
    return ("file can't be opened either for wrong permits or wrong path");
}

const char *BitcoinExchange::tooLargeException::what() const throw()
{
    return ("Error: too large a number");
}
const char *BitcoinExchange::notApositiveNumber::what() const throw()
{
    return ("Error: not a positive number");
}
const char *BitcoinExchange::BadInput::what() const throw()
{
    return ("Error : bad input  => ");
}

const char *BitcoinExchange::BadFormat::what() const throw()
{
    return ("invalid file format");
}

/* ************************************************************************** */
