#ifndef DAYBUTTON_H
#define DAYBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QFrame>
#include <QLayout>
#include <QLabel>

#include <hdatepp.h>
using namespace hdate;

#include "functions.h"

class dayButton : public QFrame
{
        Q_OBJECT

public:
    dayButton(QWidget * parent, int jd);

private:
    Hdate date;

    bool selected;
    bool today;

    void updateStyle ();

    //Widgets:
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QLabel *hebday, *engday, *event, *reading;

public slots:
    void Select();
    void Unselect();

    void setToday();

    Hdate *getHDate();

private slots:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(dayButton *);
};

#endif // DAYBUTTON_H
