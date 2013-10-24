/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jan 20 14:45:54 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionE_xit;
    QAction *actionNew_City;
    QAction *actionAbout_Munadi;
    QAction *actionPlay_Stop_Athan;
    QAction *actionShow_Hadith;
    QAction *actionTEST_PRAYER;
    QAction *actionShow_On_Athan;
    QWidget *centralWidget;
    QLabel *lblIsha;
    QLabel *lblMagrib;
    QLabel *lblAsr;
    QLabel *lblDuhr;
    QLabel *lblSunrise;
    QLabel *lblFajr;
    QPushButton *hiddenSettingsButton;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_5;
    QLabel *lblCity;
    QLabel *lblInfo;
    QWidget *QiblaDirection;
    QPushButton *pbSettings;
    QPushButton *pbStop;
    QPushButton *pbPlay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(762, 1280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/app"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralWidget\n"
"{background-image: url(/home/hex/Dev/BBNDK/BB_Munadi/res/BB10.png);\n"
"}\n"
""));
        actionE_xit = new QAction(MainWindow);
        actionE_xit->setObjectName(QString::fromUtf8("actionE_xit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionE_xit->setIcon(icon1);
        actionNew_City = new QAction(MainWindow);
        actionNew_City->setObjectName(QString::fromUtf8("actionNew_City"));
        actionNew_City->setEnabled(true);
        actionAbout_Munadi = new QAction(MainWindow);
        actionAbout_Munadi->setObjectName(QString::fromUtf8("actionAbout_Munadi"));
        actionAbout_Munadi->setEnabled(true);
        actionPlay_Stop_Athan = new QAction(MainWindow);
        actionPlay_Stop_Athan->setObjectName(QString::fromUtf8("actionPlay_Stop_Athan"));
        actionShow_Hadith = new QAction(MainWindow);
        actionShow_Hadith->setObjectName(QString::fromUtf8("actionShow_Hadith"));
        actionShow_Hadith->setCheckable(true);
        actionTEST_PRAYER = new QAction(MainWindow);
        actionTEST_PRAYER->setObjectName(QString::fromUtf8("actionTEST_PRAYER"));
        actionTEST_PRAYER->setEnabled(false);
        actionTEST_PRAYER->setVisible(false);
        actionShow_On_Athan = new QAction(MainWindow);
        actionShow_On_Athan->setObjectName(QString::fromUtf8("actionShow_On_Athan"));
        actionShow_On_Athan->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        lblIsha = new QLabel(centralWidget);
        lblIsha->setObjectName(QString::fromUtf8("lblIsha"));
        lblIsha->setGeometry(QRect(420, 840, 241, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Purisa"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        lblIsha->setFont(font);
        lblIsha->setFrameShape(QFrame::NoFrame);
        lblIsha->setFrameShadow(QFrame::Plain);
        lblIsha->setLineWidth(1);
        lblMagrib = new QLabel(centralWidget);
        lblMagrib->setObjectName(QString::fromUtf8("lblMagrib"));
        lblMagrib->setGeometry(QRect(420, 700, 241, 101));
        lblMagrib->setFont(font);
        lblMagrib->setFrameShape(QFrame::NoFrame);
        lblMagrib->setFrameShadow(QFrame::Plain);
        lblMagrib->setLineWidth(1);
        lblAsr = new QLabel(centralWidget);
        lblAsr->setObjectName(QString::fromUtf8("lblAsr"));
        lblAsr->setGeometry(QRect(420, 590, 241, 81));
        lblAsr->setFont(font);
        lblAsr->setFrameShape(QFrame::NoFrame);
        lblAsr->setFrameShadow(QFrame::Plain);
        lblAsr->setLineWidth(1);
        lblDuhr = new QLabel(centralWidget);
        lblDuhr->setObjectName(QString::fromUtf8("lblDuhr"));
        lblDuhr->setGeometry(QRect(420, 480, 241, 81));
        lblDuhr->setFont(font);
        lblDuhr->setFrameShape(QFrame::NoFrame);
        lblDuhr->setFrameShadow(QFrame::Plain);
        lblDuhr->setLineWidth(1);
        lblSunrise = new QLabel(centralWidget);
        lblSunrise->setObjectName(QString::fromUtf8("lblSunrise"));
        lblSunrise->setGeometry(QRect(420, 360, 251, 91));
        lblSunrise->setFont(font);
        lblSunrise->setFrameShape(QFrame::NoFrame);
        lblSunrise->setFrameShadow(QFrame::Plain);
        lblSunrise->setLineWidth(1);
        lblFajr = new QLabel(centralWidget);
        lblFajr->setObjectName(QString::fromUtf8("lblFajr"));
        lblFajr->setGeometry(QRect(420, 260, 251, 81));
        lblFajr->setFont(font);
        lblFajr->setFrameShape(QFrame::NoFrame);
        lblFajr->setFrameShadow(QFrame::Plain);
        lblFajr->setLineWidth(1);
        hiddenSettingsButton = new QPushButton(centralWidget);
        hiddenSettingsButton->setObjectName(QString::fromUtf8("hiddenSettingsButton"));
        hiddenSettingsButton->setGeometry(QRect(660, 10, 95, 95));
        hiddenSettingsButton->setStyleSheet(QString::fromUtf8("QPushButton {background: transparent; border: none }"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 480, 191, 81));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::NoFrame);
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setLineWidth(1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 370, 181, 71));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setLineWidth(1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 590, 191, 81));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setLineWidth(1);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 840, 191, 91));
        label_6->setFont(font);
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setFrameShadow(QFrame::Plain);
        label_6->setLineWidth(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 260, 201, 71));
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 700, 191, 101));
        label_5->setFont(font);
        label_5->setFrameShape(QFrame::NoFrame);
        label_5->setFrameShadow(QFrame::Plain);
        label_5->setLineWidth(1);
        lblCity = new QLabel(centralWidget);
        lblCity->setObjectName(QString::fromUtf8("lblCity"));
        lblCity->setGeometry(QRect(80, 130, 601, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Purisa"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setKerning(true);
        lblCity->setFont(font1);
        lblCity->setFrameShape(QFrame::NoFrame);
        lblCity->setScaledContents(true);
        lblCity->setAlignment(Qt::AlignCenter);
        lblCity->setWordWrap(true);
        lblInfo = new QLabel(centralWidget);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));
        lblInfo->setGeometry(QRect(80, 980, 601, 121));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Purisa"));
        font2.setPointSize(10);
        font2.setItalic(true);
        lblInfo->setFont(font2);
        lblInfo->setFrameShape(QFrame::NoFrame);
        lblInfo->setAlignment(Qt::AlignCenter);
        QiblaDirection = new QWidget(centralWidget);
        QiblaDirection->setObjectName(QString::fromUtf8("QiblaDirection"));
        QiblaDirection->setGeometry(QRect(740, 75, 233, 235));
        pbSettings = new QPushButton(centralWidget);
        pbSettings->setObjectName(QString::fromUtf8("pbSettings"));
        pbSettings->setGeometry(QRect(575, 1168, 171, 101));
        pbStop = new QPushButton(centralWidget);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));
        pbStop->setGeometry(QRect(460, 1170, 101, 101));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("app/native/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbStop->setIcon(icon2);
        pbStop->setIconSize(QSize(48, 48));
        pbPlay = new QPushButton(centralWidget);
        pbPlay->setObjectName(QString::fromUtf8("pbPlay"));
        pbPlay->setGeometry(QRect(350, 1170, 101, 101));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("app/native/res/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPlay->setIcon(icon3);
        pbPlay->setIconSize(QSize(48, 48));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Munadi", 0, QApplication::UnicodeUTF8));
        actionE_xit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionNew_City->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionAbout_Munadi->setText(QApplication::translate("MainWindow", "About Munadi", 0, QApplication::UnicodeUTF8));
        actionPlay_Stop_Athan->setText(QApplication::translate("MainWindow", "Play/Stop Athan", 0, QApplication::UnicodeUTF8));
        actionShow_Hadith->setText(QApplication::translate("MainWindow", "Show Hadith", 0, QApplication::UnicodeUTF8));
        actionTEST_PRAYER->setText(QApplication::translate("MainWindow", "TEST_PRAYER", 0, QApplication::UnicodeUTF8));
        actionShow_On_Athan->setText(QApplication::translate("MainWindow", "Show On Athan", 0, QApplication::UnicodeUTF8));
        lblIsha->setText(QString());
        lblMagrib->setText(QString());
        lblAsr->setText(QString());
        lblDuhr->setText(QString());
        lblSunrise->setText(QString());
        lblFajr->setText(QString());
        hiddenSettingsButton->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Duhr", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Sunrise", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Asr", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Isha", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Fajr", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Magrib", 0, QApplication::UnicodeUTF8));
        lblCity->setText(QString());
        lblInfo->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        pbSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QString());
        pbPlay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
