#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <string>
#include <iostream>

using namespace std;

//Converts numbers into strings:
// (Returns a QString representing the given value)
QString stringify(int);


//Returns a hebrew string representing the given gematria value
// You can tell it weather to add quote signs (Geresh or Gershaiim) or not
QString NumberToGematria (int num, bool addquotes = true);

//Prints (couts) the given Qstring
void print(QString);

//Prints (couts) the given int
void print(int);

#endif // FUNCTIONS_H
