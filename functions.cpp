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

#include "functions.h"


//Converts numbers into strs:
QString stringify(double x)
{
    QString qs = QString::number(x);
    return qs;
}


//Returns a hebrew string representing the given gematria value
// You can tell it weather to add quote signs (Geresh or Gershaiim) or not
QString NumberToGematria (int num, bool addquotes)
{
    QString hundredChars[] = {"ק","ר","ש","ת"};
    QString tenChars[] = {"י","כ","ל","מ","נ","ס","ע","פ","צ"};
    QString oneChars[] = {"א","ב","ג","ד","ה","ו","ז","ח","ט"};

    QString str = "";

    while (num > 400)
    {
        str += "ת";
        num = num - 400;
    }

    int hundreds = (int)(num / 100);
    num = num % 100;

    if (hundreds > 0 ) str += hundredChars[hundreds - 1];

    if (num == 16) str += "טז";
    else if (num == 15) str += "טו";
    else
    {
        int tens = (int)(num / 10);
        num = num % 10;
        if (tens > 0) str += tenChars[tens-1];

        if (num > 0) str += oneChars[num -1];

    }

    if (addquotes)
    {
        // '
        if (str.length() == 1)
            str += "'";
        // ""
        else
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


//Writes the given data to the given file path
void writetofile(QString filename, QString data, bool overwrite)
{
    //Open given file
    QFile outfile(filename);
    //Set a TextStream to it
    QTextStream outstream( &outfile );

    outstream.setCodec(QTextCodec::codecForName("utf8"));

    QFlag *mode;
    if (overwrite == false) mode = new QFlag(QIODevice::WriteOnly | QIODevice::Append);
    else mode = new QFlag(QIODevice::WriteOnly);

    //Write the data to the file
    if (outfile.open(*mode))
    {
        outstream << data;
    }
    outfile.close();

    delete mode;
}

//Returns the Daf Yomi of a day by it's given julian day
QString dafYomi(int jd)
{
    QStringList masehtot;

    masehtot << "ברכות" << "שבת" << "עירובין" << "פסחים" << "שקלים" << "יומא" << "סוכה" << "ביצה" << "ראש השנה" << "תענית" << "מגילה" << "מועד קטן" << "חגיגה" << "יבמות" << "כתובות" << "נדרים" << "נזיר" << "סוטה" << "גיטין" << "קידושין" << "בבא קמא" << "בבא מציעא" << "בבא בתרא" << "סנהדרין" << "מכות" << "שבועות" << "עבודה זרה" << "הוריות" << "זבחים" << "מנחות" << "חולין" << "בכורות" << "ערכין" << "תמורה" << "כריתות" << "מעילה" << "נידה";

    QList <int> dapim;
    dapim << 64 << 157 << 105 << 121 << 22 << 88 << 56 << 40 << 35 << 31 << 32 << 29 << 27 << /*Yevamot*/122 << 112 << 91 << 66 << 49 << 90 << 82 << /*Bava Kama*/119 << 119 << 176 << 113 << 24 << 49 << 76 << 14 << /*Zevahim*/120 << 110 << 142 << 61 << 34 << 34 << 28 << 37 << 73;

    int numDapim = 0;
    for (int i=0; i<dapim.size(); i++) numDapim += dapim[i] - 1;

    hdate::Hdate d; d.set_hdate(26,10,5683);

    int i=(jd - d.get_julian()+1) % numDapim;

    if ( i < 0 ) return "";
    else if (i==0) i = numDapim;

    int masehet=0;

    while (dapim[masehet]-1 < i)
    {
        i-=dapim[masehet++]-1;

    }

    return masehtot[masehet] + ' ' + NumberToGematria(i+1, false);
}

