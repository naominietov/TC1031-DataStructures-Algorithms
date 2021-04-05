/* 
* Actividad: Sem07-1 Listas encadenadas
* 25 marzo 2021 11:50:52
* OutOfRangeException.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera
*/

#ifndef OutOfRangeException_h
#define OutOfRangeException_h

#include <string>
#include <stdio.h>
#include <exception>
#include <sstream>

using namespace std;

class out_of_range : public logic_error {
public:
  explicit out_of_range (const string& what_arg);
  explicit out_of_range (const char* what_arg);
};

#endif /* OutOfRangeException_h */