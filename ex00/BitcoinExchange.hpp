#pragma once


#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, float> dataBase;

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &src);
  ~BitcoinExchange();
  BitcoinExchange &operator=(BitcoinExchange const &rhs);

  void checkDates(std::string &inputPath);

  protected:
    void parseDataBase(void);



  class InvalidDateException : public std::exception
  {
      virtual const char *what() const throw();
  };
};
