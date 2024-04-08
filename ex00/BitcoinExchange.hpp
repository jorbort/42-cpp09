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
  class InvalidFilePath : public std::exception
  {
    virtual const char *what() const throw();
  };
  class notApositiveNumber : public std::exception
  {
      virtual const char *what() const throw();
  };
  class toLargeException : public std::exception
  {
    virtual const char *what() const throw();
  };
  class BadInput : public std::exception
  {
    virtual const char * what(std::string) const throw();
  };
  class BadFormat : public std::exception
  {
      virtual const char * what() const throw();
  };
};
