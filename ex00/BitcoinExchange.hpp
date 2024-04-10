#pragma once


#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string , float > dataBase;

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &src);
  ~BitcoinExchange();
  BitcoinExchange &operator=(BitcoinExchange const &rhs);

  void checkInput(std::string &inputPath);

  static bool checkDate(std::string date);
  static bool checkValue(std::string value);
  static bool checkDay(int day, int month);

  void printDate(std::string day);
  void printValue(float amount);
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
    virtual const char *what() const throw();
  };
  class BadFormat : public std::exception
  {
      virtual const char * what() const throw();
  };
};
