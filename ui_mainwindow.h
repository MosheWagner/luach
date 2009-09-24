/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Sep 24 21:37:55 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *backDayBTN;
    QLabel *daylabel;
    QToolButton *nextDayBTN;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *backMonthBTN;
    QLabel *monthlabel;
    QToolButton *nextMonthBTN;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *doublebackYearBTN;
    QToolButton *backYearBTN;
    QLabel *yearlabel;
    QToolButton *nextYearBTN;
    QToolButton *doublenextYearBTN;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_2;
    QLabel *hmonthlbl;
    QLabel *gmonthlbl;
    QSpacerItem *horizontalSpacer_11;
    QLabel *engdaylbl;
    QLabel *engmonthlbl;
    QLabel *engyearlbl;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QHBoxLayout *horizontalLayout_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(757, 348);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(246, 249, 250, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(250, 252, 252, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(123, 124, 125, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(164, 166, 167, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(25);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(-1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 10, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        backDayBTN = new QToolButton(centralWidget);
        backDayBTN->setObjectName(QString::fromUtf8("backDayBTN"));
        backDayBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/arrow-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        backDayBTN->setIcon(icon);
        backDayBTN->setAutoRaise(true);

        horizontalLayout_4->addWidget(backDayBTN);

        daylabel = new QLabel(centralWidget);
        daylabel->setObjectName(QString::fromUtf8("daylabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(daylabel->sizePolicy().hasHeightForWidth());
        daylabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        daylabel->setFont(font);
        daylabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(daylabel);

        nextDayBTN = new QToolButton(centralWidget);
        nextDayBTN->setObjectName(QString::fromUtf8("nextDayBTN"));
        nextDayBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/arrow-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextDayBTN->setIcon(icon1);
        nextDayBTN->setAutoRaise(true);

        horizontalLayout_4->addWidget(nextDayBTN);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        backMonthBTN = new QToolButton(centralWidget);
        backMonthBTN->setObjectName(QString::fromUtf8("backMonthBTN"));
        backMonthBTN->setFocusPolicy(Qt::NoFocus);
        backMonthBTN->setIcon(icon);
        backMonthBTN->setAutoRaise(true);

        horizontalLayout_3->addWidget(backMonthBTN);

        monthlabel = new QLabel(centralWidget);
        monthlabel->setObjectName(QString::fromUtf8("monthlabel"));
        sizePolicy.setHeightForWidth(monthlabel->sizePolicy().hasHeightForWidth());
        monthlabel->setSizePolicy(sizePolicy);
        monthlabel->setFont(font);
        monthlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(monthlabel);

        nextMonthBTN = new QToolButton(centralWidget);
        nextMonthBTN->setObjectName(QString::fromUtf8("nextMonthBTN"));
        nextMonthBTN->setFocusPolicy(Qt::NoFocus);
        nextMonthBTN->setIcon(icon1);
        nextMonthBTN->setCheckable(false);
        nextMonthBTN->setAutoRaise(true);

        horizontalLayout_3->addWidget(nextMonthBTN);


        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        doublebackYearBTN = new QToolButton(centralWidget);
        doublebackYearBTN->setObjectName(QString::fromUtf8("doublebackYearBTN"));
        doublebackYearBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/arrow-right-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        doublebackYearBTN->setIcon(icon2);
        doublebackYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(doublebackYearBTN);

        backYearBTN = new QToolButton(centralWidget);
        backYearBTN->setObjectName(QString::fromUtf8("backYearBTN"));
        backYearBTN->setFocusPolicy(Qt::NoFocus);
        backYearBTN->setIcon(icon);
        backYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(backYearBTN);

        yearlabel = new QLabel(centralWidget);
        yearlabel->setObjectName(QString::fromUtf8("yearlabel"));
        sizePolicy.setHeightForWidth(yearlabel->sizePolicy().hasHeightForWidth());
        yearlabel->setSizePolicy(sizePolicy);
        yearlabel->setFont(font);
        yearlabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(yearlabel);

        nextYearBTN = new QToolButton(centralWidget);
        nextYearBTN->setObjectName(QString::fromUtf8("nextYearBTN"));
        nextYearBTN->setFocusPolicy(Qt::NoFocus);
        nextYearBTN->setIcon(icon1);
        nextYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(nextYearBTN);

        doublenextYearBTN = new QToolButton(centralWidget);
        doublenextYearBTN->setObjectName(QString::fromUtf8("doublenextYearBTN"));
        doublenextYearBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/arrow-left-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        doublenextYearBTN->setIcon(icon3);
        doublenextYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(doublenextYearBTN);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        hmonthlbl = new QLabel(centralWidget);
        hmonthlbl->setObjectName(QString::fromUtf8("hmonthlbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hmonthlbl->sizePolicy().hasHeightForWidth());
        hmonthlbl->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(18);
        hmonthlbl->setFont(font1);
        hmonthlbl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(hmonthlbl);

        gmonthlbl = new QLabel(centralWidget);
        gmonthlbl->setObjectName(QString::fromUtf8("gmonthlbl"));
        sizePolicy1.setHeightForWidth(gmonthlbl->sizePolicy().hasHeightForWidth());
        gmonthlbl->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(11);
        gmonthlbl->setFont(font2);
        gmonthlbl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gmonthlbl);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        engdaylbl = new QLabel(centralWidget);
        engdaylbl->setObjectName(QString::fromUtf8("engdaylbl"));
        sizePolicy.setHeightForWidth(engdaylbl->sizePolicy().hasHeightForWidth());
        engdaylbl->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        engdaylbl->setFont(font3);
        engdaylbl->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(engdaylbl);

        engmonthlbl = new QLabel(centralWidget);
        engmonthlbl->setObjectName(QString::fromUtf8("engmonthlbl"));
        sizePolicy.setHeightForWidth(engmonthlbl->sizePolicy().hasHeightForWidth());
        engmonthlbl->setSizePolicy(sizePolicy);
        engmonthlbl->setFont(font3);
        engmonthlbl->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(engmonthlbl);

        engyearlbl = new QLabel(centralWidget);
        engyearlbl->setObjectName(QString::fromUtf8("engyearlbl"));
        sizePolicy.setHeightForWidth(engyearlbl->sizePolicy().hasHeightForWidth());
        engyearlbl->setSizePolicy(sizePolicy);
        engyearlbl->setFont(font3);
        engyearlbl->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(engyearlbl);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, -1);

        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 757, 29));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        horizontalLayout_5 = new QHBoxLayout(dockWidgetContents);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setMargin(11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        MainWindow->setStyleSheet(QString());
        backDayBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        daylabel->setText(QApplication::translate("MainWindow", "\327\231\327\225\327\235", 0, QApplication::UnicodeUTF8));
        nextDayBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        backMonthBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        monthlabel->setText(QApplication::translate("MainWindow", "\327\227\327\225\327\223\327\251", 0, QApplication::UnicodeUTF8));
        nextMonthBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        doublebackYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        backYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        yearlabel->setText(QApplication::translate("MainWindow", "\327\251\327\240\327\224", 0, QApplication::UnicodeUTF8));
        nextYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        doublenextYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        hmonthlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        gmonthlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        engdaylbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        engmonthlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        engyearlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
