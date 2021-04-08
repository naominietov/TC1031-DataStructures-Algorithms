/* 
* Actividad: Sem08-2 Listas doblemente encadenadas
* 5 febrero 2021 11:24:52
* OutOfRangeException.h
* A01706095 Naomi Estefanía Nieto Vega
* A01283687 Ramsés Herrera Santiago
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