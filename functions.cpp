#include "functions.h"


//Converts numbers into strs:
QString stringify(int x)
{
    QString qs = QString::number(x);
    return qs;
}


//Returns a hebrew string representing the given gematria value
// You can tell it weather to add quote signs (Geresh or Gershaiim) or not
QString NumberToGematria (int num, bool addquotes)
{
    QString str;
    while (num > 400)
    {
        str += "ת";
        num = num - 400;
    }
    int hundreds = (int)(num / 100);
    num = num % 100;
    if (hundreds == 4) str += "ת";
    else if (hundreds == 3) str += "ש";
    else if (hundreds == 2) str += "ר";
    else if (hundreds == 1) str += "ק";

    if (num == 16) str += "טז";
    else if (num == 15) str += "טו";
    else
    {
        int tens = (int)(num / 10);
        num = num % 10;
        if (tens == 9) str += "צ";
        else if (tens == 8) str += "פ";
        else if (tens == 7) str += "ע";
        else if (tens == 6) str += "ס";
        else if (tens == 5) str += "נ";
        else if (tens == 4) str += "מ";
        else if (tens == 3) str += "ל";
        else if (tens == 2) str += "כ";
        else if (tens == 1) str += "י";

        if (num == 9) str += "ט";
        else if (num == 8) str += "ח";
        else if (num == 7) str += "ז";
        else if (num == 6) str += "ו";
        else if (num == 5) str += "ה";
        else if (num == 4) str += "ד";
        else if (num == 3) str += "ג";
        else if (num == 2) str += "ב";
        else if (num == 1) str += "א";
    }
    if (addquotes)
    {
        if (str.length() == 1)
            // '
            str += "'";
        else
            // ""
        {
            QChar c = str[str.length() - 1];
            str[str.length() - 1] = '\"';
            str += c;
        }
    }

    return str;
}

//Prints (couts) the given Qstring
void print(QString qstr)
{
    string str(qstr.toUtf8());
    cout << str << endl;
}

//Prints (couts) the given int
void print(int num)
{
    QString qstr = stringify(num);
    string str(qstr.toUtf8());
    cout << str << endl;
}
