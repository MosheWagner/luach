#ifndef CHANGELOCATION_H
#define CHANGELOCATION_H

#include <QtGui/QDialog>

#include "functions.h"

namespace Ui {
    class ChangeLocation;
}

class ChangeLocation : public QDialog {
    Q_OBJECT
public:
    ChangeLocation(QWidget *parent, QString *locationName, double *latitude, double *longitude, QString *timeZone, double *elavation);
    ~ChangeLocation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ChangeLocation *m_ui;

    QString *locationNameptr;
    double *latitudeptr;
    double *longitudeptr;
    double *elavationeptr;
    QString *timeZoneptr;

signals:
    void changed();

private slots:
    void on_okBTN_clicked();
    void on_exitBTN_clicked();
    void gotTZ();
};

#endif // CHANGELOCATION_H
