/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed Oct 14 14:47:11 2009
**      by: Qt User Interface Compiler version 4.5.3
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
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
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
    QAction *changelocationaction;
    QAction *exitaction;
    QAction *gdateaction;
    QAction *zmanimpanelaction;
    QAction *aboutaction;
    QAction *printaction;
    QAction *timeformat;
    QAction *viewsettings_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
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
    QVBoxLayout *verticalLayout_2;
    QLabel *hmonthlbl;
    QLabel *gmonthlbl;
    QHBoxLayout *horizontalLayout;
    QToolButton *backgdayBTN;
    QLabel *engdaylbl;
    QToolButton *nextgdayBTN;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *backgmonthBTN;
    QLabel *engmonthlbl;
    QToolButton *nextgmonthBTN;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *doublebackgYearBTN;
    QToolButton *backgYearBTN;
    QLabel *engyearlbl;
    QToolButton *nextgYearBTN;
    QToolButton *doublenextgYearBTN;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *dayandlocationlbl;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLabel *aloslabel;
    QLabel *label;
    QLabel *sunriselabel;
    QLabel *label_3;
    QLabel *shmamgalbl;
    QLabel *label_5;
    QLabel *shmagralbl;
    QLabel *label_6;
    QLabel *tfilamgalbl;
    QLabel *label_7;
    QLabel *tfilagralbl;
    QLabel *label_8;
    QLabel *hatzotlbl;
    QLabel *label_9;
    QLabel *minchagdolalbl;
    QLabel *label_10;
    QLabel *minchaktanalbl;
    QLabel *label_11;
    QLabel *plaglbl;
    QLabel *label_12;
    QLabel *skialbl;
    QLabel *label_21;
    QLabel *tzitslbl;
    QLabel *label_22;
    QLabel *tzits72lbl;
    QSpacerItem *verticalSpacer_2;
    QLabel *clllbllbl;
    QLabel *candellightinglbl;
    QSpacerItem *verticalSpacer;
    QLabel *dafyomislbllbl;
    QLabel *dafyomilbl;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1296, 532);
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
        QBrush brush6(QColor(252, 252, 252, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
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
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
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
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setAutoFillBackground(false);
        changelocationaction = new QAction(MainWindow);
        changelocationaction->setObjectName(QString::fromUtf8("changelocationaction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/location.png"), QSize(), QIcon::Normal, QIcon::Off);
        changelocationaction->setIcon(icon);
        exitaction = new QAction(MainWindow);
        exitaction->setObjectName(QString::fromUtf8("exitaction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitaction->setIcon(icon1);
        gdateaction = new QAction(MainWindow);
        gdateaction->setObjectName(QString::fromUtf8("gdateaction"));
        gdateaction->setCheckable(true);
        gdateaction->setChecked(true);
        zmanimpanelaction = new QAction(MainWindow);
        zmanimpanelaction->setObjectName(QString::fromUtf8("zmanimpanelaction"));
        zmanimpanelaction->setCheckable(true);
        zmanimpanelaction->setChecked(true);
        aboutaction = new QAction(MainWindow);
        aboutaction->setObjectName(QString::fromUtf8("aboutaction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutaction->setIcon(icon2);
        printaction = new QAction(MainWindow);
        printaction->setObjectName(QString::fromUtf8("printaction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/document-print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printaction->setIcon(icon3);
        timeformat = new QAction(MainWindow);
        timeformat->setObjectName(QString::fromUtf8("timeformat"));
        timeformat->setCheckable(true);
        timeformat->setChecked(false);
        viewsettings_2 = new QAction(MainWindow);
        viewsettings_2->setObjectName(QString::fromUtf8("viewsettings_2"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewsettings_2->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(20);
        gridLayout_2->setVerticalSpacing(-1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        backDayBTN = new QToolButton(centralWidget);
        backDayBTN->setObjectName(QString::fromUtf8("backDayBTN"));
        backDayBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/arrow-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        backDayBTN->setIcon(icon5);
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/arrow-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextDayBTN->setIcon(icon6);
        nextDayBTN->setAutoRaise(true);

        horizontalLayout_4->addWidget(nextDayBTN);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        backMonthBTN = new QToolButton(centralWidget);
        backMonthBTN->setObjectName(QString::fromUtf8("backMonthBTN"));
        backMonthBTN->setFocusPolicy(Qt::NoFocus);
        backMonthBTN->setIcon(icon5);
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
        nextMonthBTN->setIcon(icon6);
        nextMonthBTN->setCheckable(false);
        nextMonthBTN->setAutoRaise(true);

        horizontalLayout_3->addWidget(nextMonthBTN);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        doublebackYearBTN = new QToolButton(centralWidget);
        doublebackYearBTN->setObjectName(QString::fromUtf8("doublebackYearBTN"));
        doublebackYearBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/arrow-right-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        doublebackYearBTN->setIcon(icon7);
        doublebackYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(doublebackYearBTN);

        backYearBTN = new QToolButton(centralWidget);
        backYearBTN->setObjectName(QString::fromUtf8("backYearBTN"));
        backYearBTN->setFocusPolicy(Qt::NoFocus);
        backYearBTN->setIcon(icon5);
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
        nextYearBTN->setIcon(icon6);
        nextYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(nextYearBTN);

        doublenextYearBTN = new QToolButton(centralWidget);
        doublenextYearBTN->setObjectName(QString::fromUtf8("doublenextYearBTN"));
        doublenextYearBTN->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/arrow-left-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        doublenextYearBTN->setIcon(icon8);
        doublenextYearBTN->setAutoRaise(true);

        horizontalLayout_2->addWidget(doublenextYearBTN);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 2, 1, 1);

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


        gridLayout_2->addLayout(verticalLayout_2, 0, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backgdayBTN = new QToolButton(centralWidget);
        backgdayBTN->setObjectName(QString::fromUtf8("backgdayBTN"));
        backgdayBTN->setFocusPolicy(Qt::NoFocus);
        backgdayBTN->setIcon(icon5);
        backgdayBTN->setAutoRaise(true);

        horizontalLayout->addWidget(backgdayBTN);

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

        nextgdayBTN = new QToolButton(centralWidget);
        nextgdayBTN->setObjectName(QString::fromUtf8("nextgdayBTN"));
        nextgdayBTN->setFocusPolicy(Qt::NoFocus);
        nextgdayBTN->setIcon(icon6);
        nextgdayBTN->setAutoRaise(true);

        horizontalLayout->addWidget(nextgdayBTN);


        gridLayout_2->addLayout(horizontalLayout, 0, 4, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, -1, -1);
        backgmonthBTN = new QToolButton(centralWidget);
        backgmonthBTN->setObjectName(QString::fromUtf8("backgmonthBTN"));
        backgmonthBTN->setFocusPolicy(Qt::NoFocus);
        backgmonthBTN->setIcon(icon5);
        backgmonthBTN->setAutoRaise(true);

        horizontalLayout_5->addWidget(backgmonthBTN);

        engmonthlbl = new QLabel(centralWidget);
        engmonthlbl->setObjectName(QString::fromUtf8("engmonthlbl"));
        sizePolicy.setHeightForWidth(engmonthlbl->sizePolicy().hasHeightForWidth());
        engmonthlbl->setSizePolicy(sizePolicy);
        engmonthlbl->setFont(font3);
        engmonthlbl->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_5->addWidget(engmonthlbl);

        nextgmonthBTN = new QToolButton(centralWidget);
        nextgmonthBTN->setObjectName(QString::fromUtf8("nextgmonthBTN"));
        nextgmonthBTN->setFocusPolicy(Qt::NoFocus);
        nextgmonthBTN->setIcon(icon6);
        nextgmonthBTN->setAutoRaise(true);

        horizontalLayout_5->addWidget(nextgmonthBTN);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 5, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, -1);
        doublebackgYearBTN = new QToolButton(centralWidget);
        doublebackgYearBTN->setObjectName(QString::fromUtf8("doublebackgYearBTN"));
        doublebackgYearBTN->setFocusPolicy(Qt::NoFocus);
        doublebackgYearBTN->setIcon(icon7);
        doublebackgYearBTN->setAutoRaise(true);

        horizontalLayout_6->addWidget(doublebackgYearBTN);

        backgYearBTN = new QToolButton(centralWidget);
        backgYearBTN->setObjectName(QString::fromUtf8("backgYearBTN"));
        backgYearBTN->setFocusPolicy(Qt::NoFocus);
        backgYearBTN->setIcon(icon5);
        backgYearBTN->setAutoRaise(true);

        horizontalLayout_6->addWidget(backgYearBTN);

        engyearlbl = new QLabel(centralWidget);
        engyearlbl->setObjectName(QString::fromUtf8("engyearlbl"));
        sizePolicy.setHeightForWidth(engyearlbl->sizePolicy().hasHeightForWidth());
        engyearlbl->setSizePolicy(sizePolicy);
        engyearlbl->setFont(font3);
        engyearlbl->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_6->addWidget(engyearlbl);

        nextgYearBTN = new QToolButton(centralWidget);
        nextgYearBTN->setObjectName(QString::fromUtf8("nextgYearBTN"));
        nextgYearBTN->setFocusPolicy(Qt::NoFocus);
        nextgYearBTN->setIcon(icon6);
        nextgYearBTN->setAutoRaise(true);

        horizontalLayout_6->addWidget(nextgYearBTN);

        doublenextgYearBTN = new QToolButton(centralWidget);
        doublenextgYearBTN->setObjectName(QString::fromUtf8("doublenextgYearBTN"));
        doublenextgYearBTN->setFocusPolicy(Qt::NoFocus);
        doublenextgYearBTN->setIcon(icon8);
        doublenextgYearBTN->setAutoRaise(true);

        horizontalLayout_6->addWidget(doublenextgYearBTN);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 6, 1, 1);

        gridLayout_2->setColumnStretch(0, 100);
        gridLayout_2->setColumnStretch(1, 100);
        gridLayout_2->setColumnStretch(2, 100);
        gridLayout_2->setColumnStretch(3, 100);
        gridLayout_2->setColumnStretch(4, 100);
        gridLayout_2->setColumnStretch(5, 100);
        gridLayout_2->setColumnStretch(6, 100);

        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, -1);

        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1296, 29));
        menuBar->setLayoutDirection(Qt::RightToLeft);
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setLayoutDirection(Qt::RightToLeft);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setLayoutDirection(Qt::RightToLeft);
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_3->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy2);
        dockWidget->setLayoutDirection(Qt::RightToLeft);
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        sizePolicy2.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(8);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_4);

        dayandlocationlbl = new QLabel(dockWidgetContents);
        dayandlocationlbl->setObjectName(QString::fromUtf8("dayandlocationlbl"));
        QFont font5;
        font5.setPointSize(8);
        dayandlocationlbl->setFont(font5);

        verticalLayout_3->addWidget(dayandlocationlbl);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setHorizontalSpacing(10);
        formLayout_3->setContentsMargins(0, 0, -1, -1);
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(false);
        font6.setWeight(50);
        label_2->setFont(font6);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        aloslabel = new QLabel(dockWidgetContents);
        aloslabel->setObjectName(QString::fromUtf8("aloslabel"));
        sizePolicy.setHeightForWidth(aloslabel->sizePolicy().hasHeightForWidth());
        aloslabel->setSizePolicy(sizePolicy);
        aloslabel->setFont(font6);
        aloslabel->setLayoutDirection(Qt::RightToLeft);
        aloslabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        aloslabel->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, aloslabel);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font6);
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label);

        sunriselabel = new QLabel(dockWidgetContents);
        sunriselabel->setObjectName(QString::fromUtf8("sunriselabel"));
        sizePolicy.setHeightForWidth(sunriselabel->sizePolicy().hasHeightForWidth());
        sunriselabel->setSizePolicy(sizePolicy);
        sunriselabel->setFont(font6);
        sunriselabel->setLayoutDirection(Qt::RightToLeft);
        sunriselabel->setLineWidth(1);
        sunriselabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        sunriselabel->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, sunriselabel);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font6);
        label_3->setLayoutDirection(Qt::RightToLeft);
        label_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_3->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_3);

        shmamgalbl = new QLabel(dockWidgetContents);
        shmamgalbl->setObjectName(QString::fromUtf8("shmamgalbl"));
        sizePolicy.setHeightForWidth(shmamgalbl->sizePolicy().hasHeightForWidth());
        shmamgalbl->setSizePolicy(sizePolicy);
        shmamgalbl->setFont(font6);
        shmamgalbl->setLayoutDirection(Qt::RightToLeft);
        shmamgalbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        shmamgalbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, shmamgalbl);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font6);
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_5->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_5);

        shmagralbl = new QLabel(dockWidgetContents);
        shmagralbl->setObjectName(QString::fromUtf8("shmagralbl"));
        sizePolicy.setHeightForWidth(shmagralbl->sizePolicy().hasHeightForWidth());
        shmagralbl->setSizePolicy(sizePolicy);
        shmagralbl->setFont(font6);
        shmagralbl->setLayoutDirection(Qt::RightToLeft);
        shmagralbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        shmagralbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, shmagralbl);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font6);
        label_6->setLayoutDirection(Qt::RightToLeft);
        label_6->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_6->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_6);

        tfilamgalbl = new QLabel(dockWidgetContents);
        tfilamgalbl->setObjectName(QString::fromUtf8("tfilamgalbl"));
        sizePolicy.setHeightForWidth(tfilamgalbl->sizePolicy().hasHeightForWidth());
        tfilamgalbl->setSizePolicy(sizePolicy);
        tfilamgalbl->setFont(font6);
        tfilamgalbl->setLayoutDirection(Qt::RightToLeft);
        tfilamgalbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tfilamgalbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, tfilamgalbl);

        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font6);
        label_7->setLayoutDirection(Qt::RightToLeft);
        label_7->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_7->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_7);

        tfilagralbl = new QLabel(dockWidgetContents);
        tfilagralbl->setObjectName(QString::fromUtf8("tfilagralbl"));
        sizePolicy.setHeightForWidth(tfilagralbl->sizePolicy().hasHeightForWidth());
        tfilagralbl->setSizePolicy(sizePolicy);
        tfilagralbl->setFont(font6);
        tfilagralbl->setLayoutDirection(Qt::RightToLeft);
        tfilagralbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tfilagralbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, tfilagralbl);

        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font6);
        label_8->setLayoutDirection(Qt::RightToLeft);
        label_8->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_8->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_8);

        hatzotlbl = new QLabel(dockWidgetContents);
        hatzotlbl->setObjectName(QString::fromUtf8("hatzotlbl"));
        sizePolicy.setHeightForWidth(hatzotlbl->sizePolicy().hasHeightForWidth());
        hatzotlbl->setSizePolicy(sizePolicy);
        hatzotlbl->setFont(font6);
        hatzotlbl->setLayoutDirection(Qt::RightToLeft);
        hatzotlbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        hatzotlbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, hatzotlbl);

        label_9 = new QLabel(dockWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font6);
        label_9->setLayoutDirection(Qt::RightToLeft);
        label_9->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_9->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_9);

        minchagdolalbl = new QLabel(dockWidgetContents);
        minchagdolalbl->setObjectName(QString::fromUtf8("minchagdolalbl"));
        sizePolicy.setHeightForWidth(minchagdolalbl->sizePolicy().hasHeightForWidth());
        minchagdolalbl->setSizePolicy(sizePolicy);
        minchagdolalbl->setFont(font6);
        minchagdolalbl->setLayoutDirection(Qt::RightToLeft);
        minchagdolalbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        minchagdolalbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(7, QFormLayout::FieldRole, minchagdolalbl);

        label_10 = new QLabel(dockWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font6);
        label_10->setLayoutDirection(Qt::RightToLeft);
        label_10->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_10->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_10);

        minchaktanalbl = new QLabel(dockWidgetContents);
        minchaktanalbl->setObjectName(QString::fromUtf8("minchaktanalbl"));
        sizePolicy.setHeightForWidth(minchaktanalbl->sizePolicy().hasHeightForWidth());
        minchaktanalbl->setSizePolicy(sizePolicy);
        minchaktanalbl->setFont(font6);
        minchaktanalbl->setLayoutDirection(Qt::RightToLeft);
        minchaktanalbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        minchaktanalbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, minchaktanalbl);

        label_11 = new QLabel(dockWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setFont(font6);
        label_11->setLayoutDirection(Qt::RightToLeft);
        label_11->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_11->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(9, QFormLayout::LabelRole, label_11);

        plaglbl = new QLabel(dockWidgetContents);
        plaglbl->setObjectName(QString::fromUtf8("plaglbl"));
        sizePolicy.setHeightForWidth(plaglbl->sizePolicy().hasHeightForWidth());
        plaglbl->setSizePolicy(sizePolicy);
        plaglbl->setFont(font6);
        plaglbl->setLayoutDirection(Qt::RightToLeft);
        plaglbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        plaglbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(9, QFormLayout::FieldRole, plaglbl);

        label_12 = new QLabel(dockWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setFont(font6);
        label_12->setLayoutDirection(Qt::RightToLeft);
        label_12->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_12->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(10, QFormLayout::LabelRole, label_12);

        skialbl = new QLabel(dockWidgetContents);
        skialbl->setObjectName(QString::fromUtf8("skialbl"));
        sizePolicy.setHeightForWidth(skialbl->sizePolicy().hasHeightForWidth());
        skialbl->setSizePolicy(sizePolicy);
        skialbl->setFont(font6);
        skialbl->setLayoutDirection(Qt::RightToLeft);
        skialbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        skialbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(10, QFormLayout::FieldRole, skialbl);

        label_21 = new QLabel(dockWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setFont(font6);
        label_21->setLayoutDirection(Qt::RightToLeft);
        label_21->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_21->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(11, QFormLayout::LabelRole, label_21);

        tzitslbl = new QLabel(dockWidgetContents);
        tzitslbl->setObjectName(QString::fromUtf8("tzitslbl"));
        sizePolicy.setHeightForWidth(tzitslbl->sizePolicy().hasHeightForWidth());
        tzitslbl->setSizePolicy(sizePolicy);
        tzitslbl->setFont(font6);
        tzitslbl->setLayoutDirection(Qt::RightToLeft);
        tzitslbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tzitslbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(11, QFormLayout::FieldRole, tzitslbl);

        label_22 = new QLabel(dockWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setFont(font6);
        label_22->setLayoutDirection(Qt::RightToLeft);
        label_22->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_22->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(12, QFormLayout::LabelRole, label_22);

        tzits72lbl = new QLabel(dockWidgetContents);
        tzits72lbl->setObjectName(QString::fromUtf8("tzits72lbl"));
        sizePolicy.setHeightForWidth(tzits72lbl->sizePolicy().hasHeightForWidth());
        tzits72lbl->setSizePolicy(sizePolicy);
        tzits72lbl->setFont(font6);
        tzits72lbl->setLayoutDirection(Qt::RightToLeft);
        tzits72lbl->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        tzits72lbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(12, QFormLayout::FieldRole, tzits72lbl);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(13, QFormLayout::FieldRole, verticalSpacer_2);

        clllbllbl = new QLabel(dockWidgetContents);
        clllbllbl->setObjectName(QString::fromUtf8("clllbllbl"));
        clllbllbl->setFont(font6);

        formLayout_3->setWidget(14, QFormLayout::LabelRole, clllbllbl);

        candellightinglbl = new QLabel(dockWidgetContents);
        candellightinglbl->setObjectName(QString::fromUtf8("candellightinglbl"));
        candellightinglbl->setFont(font6);

        formLayout_3->setWidget(14, QFormLayout::FieldRole, candellightinglbl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_3->setItem(15, QFormLayout::FieldRole, verticalSpacer);

        dafyomislbllbl = new QLabel(dockWidgetContents);
        dafyomislbllbl->setObjectName(QString::fromUtf8("dafyomislbllbl"));
        dafyomislbllbl->setFont(font6);
        dafyomislbllbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(16, QFormLayout::LabelRole, dafyomislbllbl);

        dafyomilbl = new QLabel(dockWidgetContents);
        dafyomilbl->setObjectName(QString::fromUtf8("dafyomilbl"));
        dafyomilbl->setFont(font6);
        dafyomilbl->setFrameShape(QFrame::NoFrame);
        dafyomilbl->setFrameShadow(QFrame::Plain);
        dafyomilbl->setLineWidth(1);
        dafyomilbl->setMidLineWidth(0);
        dafyomilbl->setScaledContents(false);
        dafyomilbl->setAlignment(Qt::AlignCenter);
        dafyomilbl->setWordWrap(true);
        dafyomilbl->setMargin(0);
        dafyomilbl->setIndent(0);
        dafyomilbl->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout_3->setWidget(16, QFormLayout::FieldRole, dafyomilbl);


        verticalLayout_3->addLayout(formLayout_3);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(changelocationaction);
        menu_2->addAction(aboutaction);
        menu_2->addAction(printaction);
        menu_2->addSeparator();
        menu_2->addAction(exitaction);
        menu_3->addAction(gdateaction);
        menu_3->addAction(zmanimpanelaction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        MainWindow->setStyleSheet(QString());
        changelocationaction->setText(QApplication::translate("MainWindow", "\327\251\327\231\327\240\327\225\327\231 \327\236\327\231\327\247\327\225\327\235", 0, QApplication::UnicodeUTF8));
        exitaction->setText(QApplication::translate("MainWindow", "\327\231\327\246\327\231\327\220\327\224", 0, QApplication::UnicodeUTF8));
        gdateaction->setText(QApplication::translate("MainWindow", "\327\224\327\246\327\222 \327\252\327\220\327\250\327\231\327\232 \327\234\327\225\327\242\327\226\327\231", 0, QApplication::UnicodeUTF8));
        zmanimpanelaction->setText(QApplication::translate("MainWindow", "\327\224\327\246\327\222 \327\250\327\251\327\231\327\236\327\252 \327\226\327\236\327\240\327\231\327\235", 0, QApplication::UnicodeUTF8));
        aboutaction->setText(QApplication::translate("MainWindow", "\327\220\327\225\327\223\327\225\327\252", 0, QApplication::UnicodeUTF8));
        printaction->setText(QApplication::translate("MainWindow", "\327\224\327\223\327\244\327\241 \327\234\327\225\327\227", 0, QApplication::UnicodeUTF8));
        timeformat->setText(QApplication::translate("MainWindow", "\327\224\327\246\327\222 \327\251\327\242\327\225\327\252 \327\221\327\246\327\225\327\250\327\252 AM/PM", 0, QApplication::UnicodeUTF8));
        viewsettings_2->setText(QApplication::translate("MainWindow", "\327\224\327\222\327\223\327\250\327\225\327\252 \327\252\327\246\327\225\327\222\327\224", 0, QApplication::UnicodeUTF8));
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
        backgdayBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        engdaylbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        nextgdayBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        backgmonthBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        engmonthlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        nextgmonthBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        doublebackgYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        backgYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        engyearlbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        nextgYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        doublenextgYearBTN->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\327\224\327\222\327\223\327\250\327\225\327\252", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\327\247\327\225\327\221\327\245", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\327\252\327\246\327\225\327\222\327\224", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "\327\226\327\236\327\240\327\231 \327\224\327\231\327\225\327\235", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\327\226\327\236\327\240\327\231 \327\224\327\231\327\225\327\235:", 0, QApplication::UnicodeUTF8));
        dayandlocationlbl->setText(QApplication::translate("MainWindow", "\327\252\327\220\327\250\327\231\327\232, \327\236\327\231\327\247\327\225\327\235", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\327\242\327\234\327\225\327\252 \327\224\327\251\327\227\327\250", 0, QApplication::UnicodeUTF8));
        aloslabel->setText(QApplication::translate("MainWindow", "\327\242\327\234\327\225\327\224\"\327\251", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\327\226\327\250\327\231\327\227\327\224", 0, QApplication::UnicodeUTF8));
        sunriselabel->setText(QApplication::translate("MainWindow", "\327\226\327\250\327\231\327\227\327\224", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\327\241\327\225\327\243 \327\226\327\236\327\237 \327\247\"\327\251 \327\236\327\222\"\327\220", 0, QApplication::UnicodeUTF8));
        shmamgalbl->setText(QApplication::translate("MainWindow", "\327\247\"\327\251 \327\236\327\222\"\327\220", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\327\241\327\225\327\243 \327\226\327\236\327\237 \327\247\"\327\251 \327\222\327\250\"\327\220", 0, QApplication::UnicodeUTF8));
        shmagralbl->setText(QApplication::translate("MainWindow", "\327\247\"\327\251 \327\222\327\250\"\327\220", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\327\241\327\225\327\243 \327\226\327\236\327\237 \327\252\327\244\327\231\327\234\327\224 \327\236\327\222\"\327\220", 0, QApplication::UnicodeUTF8));
        tfilamgalbl->setText(QApplication::translate("MainWindow", "\327\252\327\244\327\231\327\234\327\224 \327\236\327\222\"\327\220", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\327\241\327\225\327\243 \327\226\327\236\327\237 \327\252\327\244\327\231\327\234\327\224 \327\222\327\250\"\327\220", 0, QApplication::UnicodeUTF8));
        tfilagralbl->setText(QApplication::translate("MainWindow", "\327\252\327\244\327\231\327\234\327\224 \327\222\327\250\"\327\220", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\327\227\327\246\327\225\327\252", 0, QApplication::UnicodeUTF8));
        hatzotlbl->setText(QApplication::translate("MainWindow", "\327\227\327\246\327\225\327\252", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\327\236\327\240\327\227\327\224 \327\222\327\223\327\225\327\234\327\224", 0, QApplication::UnicodeUTF8));
        minchagdolalbl->setText(QApplication::translate("MainWindow", "\327\236\327\240\327\227\327\224 \327\222\327\223\327\225\327\234\327\224", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\327\236\327\240\327\227\327\224 \327\247\327\230\327\240\327\224", 0, QApplication::UnicodeUTF8));
        minchaktanalbl->setText(QApplication::translate("MainWindow", "\327\236\327\240\327\227\327\224 \327\247\327\230\327\240\327\224", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\327\244\327\234\327\222 \327\224\327\236\327\240\327\227\327\224", 0, QApplication::UnicodeUTF8));
        plaglbl->setText(QApplication::translate("MainWindow", "\327\244\327\234\327\222 \327\224\327\236\327\240\327\227\327\224", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\327\251\327\247\327\231\327\242\327\224", 0, QApplication::UnicodeUTF8));
        skialbl->setText(QApplication::translate("MainWindow", "\327\251\327\247\327\231\327\242\327\224", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "\327\246\327\220\327\252 \327\224\327\233\327\225\327\233\327\221\327\231\327\235", 0, QApplication::UnicodeUTF8));
        tzitslbl->setText(QApplication::translate("MainWindow", "\327\246\327\224\"\327\233", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "\327\246\327\220\327\252 \327\224\327\233\327\225\327\233\327\221\327\231\327\235 \327\250\"\327\252", 0, QApplication::UnicodeUTF8));
        tzits72lbl->setText(QApplication::translate("MainWindow", "\327\246\327\224\"\327\233 \327\250\"\327\252", 0, QApplication::UnicodeUTF8));
        clllbllbl->setText(QApplication::translate("MainWindow", "\327\224\327\223\327\234\327\247\327\252 \327\240\327\250\327\225\327\252", 0, QApplication::UnicodeUTF8));
        candellightinglbl->setText(QApplication::translate("MainWindow", "\327\224\327\223\327\224\"\327\240", 0, QApplication::UnicodeUTF8));
        dafyomislbllbl->setText(QApplication::translate("MainWindow", "\327\223\327\243 \327\231\327\225\327\236\327\231", 0, QApplication::UnicodeUTF8));
        dafyomilbl->setText(QApplication::translate("MainWindow", "\327\223\327\243", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
