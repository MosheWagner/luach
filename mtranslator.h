#ifndef MTRANSLATOR_H
#define MTRANSLATOR_H

#include <QString>
#include <QStringList>
#include <QLocale>
#include <locale.h>
#include <QtGui/QMainWindow>

void BuildHebrewTranslationList();

QString mTr(QString orig);

#endif // MTRANSLATOR_H
