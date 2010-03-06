#include "mtranslator.h"

#include "mainwindow.h"

QStringList dict[2];
QStringList d;

extern QString LANG;

void addToList(QString orig, QString trans)
{
    dict[0] << orig; dict[1] << trans;
}

void BuildHebrewTranslationList()
{
    addToList("Sunday", "ראשון");
    addToList("Monday", "שני");
    addToList("Tuesday", "שלישי");
    addToList("Wednesday", "רביעי");
    addToList("Thursday", "חמישי");
    addToList("Friday", "שישי");
    addToList("Saturday", "שבת");

    addToList("January", "ינואר" );
    addToList("February", "פברואר");
    addToList("March", "מרס" );
    addToList("April","אפריל" );
    addToList("May", "מאי" );
    addToList("June", "יוני" );
    addToList("July", "יולי");
    addToList("August", "אוגוסט");
    addToList("September","ספטמבר" );
    addToList("October","אוקטובר" );
    addToList("November", "נובמבר");
    addToList("December", "דצמבר");

    addToList("About", "אודות");
    addToList("Show English Date", "הצג תאריך לועזי");
    addToList("Print Luach", "הדפס לוח");
    addToList("Quit", "יציאה");
    addToList("Show Time List", "הצג זמנים");
    addToList("Change Location", "שנה מיקום");

    addToList("Settings", "הגדרות");
    addToList("Display", "תצוגה");
    addToList("File", "קובץ");

    addToList("Alos", "עלות השחר");
    addToList("Sunrise", "זריחה");
    addToList("Shma MGA", "סוף זמן קריאת שמע מג\"א");
    addToList("Shma GRA", "סוף זמן קריאת שמע גר\"א");
    addToList("Tfila MGA", "סוף זמן תפילה מג\"א");
    addToList("Tfila GRA", "סוף זמן תפילה גר\"א");
    addToList("Chatzos", "חצות");
    addToList("Mincha Gedola", "מנחה גדולה");
    addToList("Mincha Ktana", "מנחה קטנה");
    addToList("Plag Hamincha", "פלג המנחה");
    addToList("Sunset", "שקיעה");
    addToList("Tzais", "צאת הכוכבים");
    addToList("Tzais 72", "צאת הכוכבים ר\"ת");
    addToList("Candle Lighting", "הדלקת נרות");

    addToList("Zmanim", "זמני היום:");

    addToList("Hebrew GUI", "ממשק אנגלי");

    addToList("Israel", "ארץ ישראל");
    addToList("Diaspora", "חוץ לארץ");
    addToList("Latitude:", "קו רוחב:");
    addToList("Longitude:", "קו אורך:");
    addToList("Time Zone:", "אזור זמן:");
    addToList("Elavation:", "גובה:");
    addToList("Candle Lighting Time:", "זמן כניסת שבת:");
    addToList("(Minutes before sunset)", " - דקות לפני שקיעה");
    addToList("OK", "שמור");
    addToList("Cancel", "ביטול");
    addToList("Location Name (effects the title only):", "שם המיקום (משפיע על התצוגה בלבד):");
    addToList("Save Settings", "שמור מיקום להפעלה הבאה");
}

QString mTr(QString orig)
{
    int a = 0; int b = 1;
    if (LANG == "Hebrew")
    {
        a = 1;
        b = 0;
    }

    int i = dict[b].indexOf(orig);
    if (i != -1) return (dict[a][i]);

    return orig;

}
