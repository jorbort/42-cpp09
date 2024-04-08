#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
    this->parseDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    this->dataBase = src.dataBase;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

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

void BitcoinExchange::checkDates(std::string &path)
{

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
