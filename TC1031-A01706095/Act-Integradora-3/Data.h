// --------------------------------------------------------
// ID:          A01706095
// Name:        Naomi Estefanía Nieto Vega 
// Last update: 24/04/2021 14:06:56
// File name:   Data.h
// Title:       Act-Integradora-3 
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
  void removeIpDots(char*);
  void setKey();
  void print();
  /* Getters */
  std::string getMonth();
  std::string getDay();
  std::string getHour();
  std::string getMins();
  std::string getSecs();
  std::string getIpAddress();
  std::string getErrorMsg();
  std::string getPort();
  int getKey();
  std::string valor;
  int access;
};

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
  this->setKey();
  this->valor = this->month  + " " + this->day + " " + this->hour + ":" + this->min + ":" + this->sec + " " + this->ipAddress + ":" + this->port + " " + this->errorMsg;
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
  this->setKey();
  this->valor = "";
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

void Data::removeIpDots(char *ipAddress) {
	int dotsCount = 0;
	for (int i = 0; ipAddress[i]; i++) 
		if (ipAddress[i] != '.') {
			ipAddress[dotsCount++] = ipAddress[i]; 
    }
	ipAddress[dotsCount] = '\0';
}

/* This function is to set a unique ID to each line of the file and then
convert it from string to int */

void Data::setKey() {
  std::string id(this->ipAddress);
  char str[id.length()];
  for (int i = 0; i < sizeof(str); i++) {
    str[i] = id[i];
  }
  removeIpDots(str);
  std::string newId(str);
  std::stringstream string2int(newId);
  string2int >> this->key;
}

/* This utility function prints the array using the same format as the 
original text file, it doesnt receives an input because its only used to
print when needed */

void Data::print() {
  std::cout << " " << this->month << " " << this->day << " " << this->hour << ":" << this->min << ":" << this->sec << " " << this->ipAddress << " " << this->errorMsg << "\n";
}

/* The following lines are getters of each variable so we can take
its value when needed, used in main, each getter returns the value of
the requested variable */

std::string Data::getMonth() {
  return this->month;
}

std::string Data::getDay() {
  return this->day;
}

std::string Data::getHour() {
  return this->hour;
}

std::string Data::getMins() {
  return this->min;
}

std::string Data::getSecs() {
  return this->sec;
}

std::string Data::getIpAddress() {
  return this->ipAddress;
}

std::string Data::getErrorMsg() {
  return this->errorMsg;
}

int Data::getKey() {
  return this->key;
}

#endif /* Data_h */