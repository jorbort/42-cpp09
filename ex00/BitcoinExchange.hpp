#pragma once


#include <exception>
#include <map>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string , float> dataBase;
  std::string badInput;

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &src);
  ~BitcoinExchange();
  BitcoinExchange &operator=(BitcoinExchange const &rhs);

  void checkInput(std::string &inputPath);

   void checkDate(std::string date);
   void checkValue(std::string value);
   void checkDay(int day, int month);
   void formatedPrint(std::string date, float value);

  void setBadInput(std::string input);
  void getBadInput();
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
  class tooLargeException : public std::exception
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
