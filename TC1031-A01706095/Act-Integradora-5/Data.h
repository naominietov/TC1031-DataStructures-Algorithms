// --------------------------------------------------------
// ID:          A01706095 
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 02/06/2021 20:48:26
// File name:   Data.h
// Title:       Act-Integradora-5
// --------------------------------------------------------
#ifndef Data_h
#define Data_h

#include <string>
#include <iostream>
#include <sstream> 

class Data {
  private:
  std::string month;
  std::string day;
  std::string hour;
  std::string min;
  std::string sec;
  std::string ipAddress;
  std::string errorMsg;
  std::string port;
  int key;

  public:
  /* Utility functions */
  Data(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
  Data();
  std::string monthToNumber();
};

std::string removeIpDots(char *ipAddress) {
	int dotsCount = 0;
	for (int i = 0; ipAddress[i]; i++) 
		if (ipAddress[i] != '.') {
			ipAddress[dotsCount++] = ipAddress[i]; 
        }
	ipAddress[dotsCount] = '\0';
  std::string stringIP = ipAddress;
  return stringIP;
}

/* This constructor helps to initialize objects of the class, 
its used in main and it receives string type parameters and it 
points to the equivalent variable */

Data::Data(std::string month, std::string day, std::string hour, std::string min, std::string sec, std::string ipAddress, std::string port, std::string errorMsg) {
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->min = min;
  this->sec = sec;
  this->ipAddress = ipAddress;
  this->port = port;
  this->errorMsg = errorMsg;
};

Data::Data() {
  this->month = "";
  this->day = "";
  this->hour = "";
  this->min = "";
  this->sec = "";
  this->ipAddress = "";
  this->port = "";
  this->errorMsg = "";
};

/* This is an utility function that helps to convert month given 
in text or normal words to number so we can use the month number 
later to create a unique string key identifier. It receives the
first 3 words of the month and returns the month number */

std::string Data::monthToNumber() {
  if (!this->month.compare("Jan")) {
    return "1";
  }
  else if (!this->month.compare("Feb")) {
    return "2";
  }
  else if (!this->month.compare("Mar")) {
    return "3";
  }
  else if (!this->month.compare("Apr")) {
    return "4";
  }
  else if (!this->month.compare("May")) {
    return "5";
  }
  else if (!this->month.compare("Jun")) {
    return "6";
  }
  else if (!this->month.compare("Jul")) {
    return "7";
  }
  else if (!this->month.compare("Aug")) {
    return "8";
  }
  else if (!this->month.compare("Sep")) {
    return "9";
  }
  else if (!this->month.compare("Oct")) {
    return "10";
  }
  else if (!this->month.compare("Nov")) {
    return "11";
  }
  else if (!this->month.compare("Dec")) {
    return "12";
  }
  else {
    return "0";
  } 
}

#endif /* Data_h */