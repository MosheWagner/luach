/* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Moshe Wagner. <moshe.wagner@gmail.com>
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <string>
#include <iostream>

using namespace std;

//Converts numbers into strings:
// (Returns a QString representing the given value)
QString stringify(double);


//Returns a hebrew string representing the given gematria value
// You can tell it weather to add quote signs (Geresh or Gershaiim) or not
QString NumberToGematria (int num, bool addquotes = true);

//Prints (couts) the given Qstring
void print(QString);

//Prints (couts) the given int
void print(int);

#endif // FUNCTIONS_H
