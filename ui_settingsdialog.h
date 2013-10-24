/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created: Sun Jan 20 14:30:01 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_4;
    QLabel *lblEDAthan;
    QLabel *lblAthanAdjustment;
    QCheckBox *cbFajrEnabled;
    QCheckBox *cbDuhrEnabled;
    QCheckBox *cbAsrEnabled;
    QCheckBox *cbMagribEnabled;
    QCheckBox *cbIshaEnabled;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *sbDuhrAdjustment;
    QPushButton *pbDuhrDown;
    QPushButton *pbDuhrUp;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *sbAsrAdjustment;
    QPushButton *pbAsrDown;
    QPushButton *pbAsrUp;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *sbMagribAdjustment;
    QPushButton *pbMagribDown;
    QPushButton *pbMagribUp;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *sbIshaAdjustment;
    QPushButton *pbIshaDown;
    QPushButton *pbIshaUp;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *sbFajrAdjustment;
    QPushButton *pbFajrDown;
    QPushButton *pbFajrUp;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QComboBox *cbMethod;
    QLabel *label_6;
    QComboBox *cbMathhab;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *cbCountries;
    QLabel *label;
    QComboBox *cbCities;
    QGridLayout *gridDetails;
    QLabel *lblLatitude;
    QLineEdit *tbLatitude;
    QLabel *lblLongitude;
    QLineEdit *tbLongitude;
    QLabel *label_2;
    QLineEdit *tbGmtOffset;
    QLabel *label_4;
    QLineEdit *tbLocation;
    QCheckBox *cbDaylightSaving;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *settingsDialog)
    {
        if (settingsDialog->objectName().isEmpty())
            settingsDialog->setObjectName(QString::fromUtf8("settingsDialog"));
        settingsDialog->resize(768, 1280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settingsDialog->sizePolicy().hasHeightForWidth());
        settingsDialog->setSizePolicy(sizePolicy);
        settingsDialog->setMaximumSize(QSize(16777215, 16777215));
        settingsDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(settingsDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(settingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setPointSize(8);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 720, 1167));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lblEDAthan = new QLabel(scrollAreaWidgetContents);
        lblEDAthan->setObjectName(QString::fromUtf8("lblEDAthan"));
        lblEDAthan->setFont(font);
        lblEDAthan->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lblEDAthan, 0, 0, 1, 1);

        lblAthanAdjustment = new QLabel(scrollAreaWidgetContents);
        lblAthanAdjustment->setObjectName(QString::fromUtf8("lblAthanAdjustment"));
        lblAthanAdjustment->setFont(font);
        lblAthanAdjustment->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lblAthanAdjustment, 0, 1, 1, 1);

        cbFajrEnabled = new QCheckBox(scrollAreaWidgetContents);
        cbFajrEnabled->setObjectName(QString::fromUtf8("cbFajrEnabled"));
        cbFajrEnabled->setFont(font);
        cbFajrEnabled->setChecked(true);

        gridLayout_4->addWidget(cbFajrEnabled, 1, 0, 1, 1);

        cbDuhrEnabled = new QCheckBox(scrollAreaWidgetContents);
        cbDuhrEnabled->setObjectName(QString::fromUtf8("cbDuhrEnabled"));
        cbDuhrEnabled->setFont(font);
        cbDuhrEnabled->setChecked(true);

        gridLayout_4->addWidget(cbDuhrEnabled, 2, 0, 1, 1);

        cbAsrEnabled = new QCheckBox(scrollAreaWidgetContents);
        cbAsrEnabled->setObjectName(QString::fromUtf8("cbAsrEnabled"));
        cbAsrEnabled->setFont(font);
        cbAsrEnabled->setChecked(true);

        gridLayout_4->addWidget(cbAsrEnabled, 3, 0, 1, 1);

        cbMagribEnabled = new QCheckBox(scrollAreaWidgetContents);
        cbMagribEnabled->setObjectName(QString::fromUtf8("cbMagribEnabled"));
        cbMagribEnabled->setFont(font);
        cbMagribEnabled->setChecked(true);

        gridLayout_4->addWidget(cbMagribEnabled, 4, 0, 1, 1);

        cbIshaEnabled = new QCheckBox(scrollAreaWidgetContents);
        cbIshaEnabled->setObjectName(QString::fromUtf8("cbIshaEnabled"));
        cbIshaEnabled->setFont(font);
        cbIshaEnabled->setChecked(true);

        gridLayout_4->addWidget(cbIshaEnabled, 5, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        sbDuhrAdjustment = new QSpinBox(scrollAreaWidgetContents);
        sbDuhrAdjustment->setObjectName(QString::fromUtf8("sbDuhrAdjustment"));
        sbDuhrAdjustment->setFont(font);
        sbDuhrAdjustment->setReadOnly(true);
        sbDuhrAdjustment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbDuhrAdjustment->setMinimum(-99);
        sbDuhrAdjustment->setMaximum(99);
        sbDuhrAdjustment->setValue(0);

        horizontalLayout_8->addWidget(sbDuhrAdjustment);

        pbDuhrDown = new QPushButton(scrollAreaWidgetContents);
        pbDuhrDown->setObjectName(QString::fromUtf8("pbDuhrDown"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbDuhrDown->sizePolicy().hasHeightForWidth());
        pbDuhrDown->setSizePolicy(sizePolicy1);
        pbDuhrDown->setMaximumSize(QSize(16777215, 16777215));
        pbDuhrDown->setFont(font);

        horizontalLayout_8->addWidget(pbDuhrDown);

        pbDuhrUp = new QPushButton(scrollAreaWidgetContents);
        pbDuhrUp->setObjectName(QString::fromUtf8("pbDuhrUp"));
        sizePolicy1.setHeightForWidth(pbDuhrUp->sizePolicy().hasHeightForWidth());
        pbDuhrUp->setSizePolicy(sizePolicy1);
        pbDuhrUp->setMaximumSize(QSize(16777215, 16777215));
        pbDuhrUp->setFont(font);

        horizontalLayout_8->addWidget(pbDuhrUp);


        gridLayout_4->addLayout(horizontalLayout_8, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        sbAsrAdjustment = new QSpinBox(scrollAreaWidgetContents);
        sbAsrAdjustment->setObjectName(QString::fromUtf8("sbAsrAdjustment"));
        sbAsrAdjustment->setFont(font);
        sbAsrAdjustment->setReadOnly(true);
        sbAsrAdjustment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbAsrAdjustment->setMinimum(-99);
        sbAsrAdjustment->setMaximum(99);
        sbAsrAdjustment->setValue(0);

        horizontalLayout_9->addWidget(sbAsrAdjustment);

        pbAsrDown = new QPushButton(scrollAreaWidgetContents);
        pbAsrDown->setObjectName(QString::fromUtf8("pbAsrDown"));
        sizePolicy1.setHeightForWidth(pbAsrDown->sizePolicy().hasHeightForWidth());
        pbAsrDown->setSizePolicy(sizePolicy1);
        pbAsrDown->setMaximumSize(QSize(16777215, 16777215));
        pbAsrDown->setFont(font);

        horizontalLayout_9->addWidget(pbAsrDown);

        pbAsrUp = new QPushButton(scrollAreaWidgetContents);
        pbAsrUp->setObjectName(QString::fromUtf8("pbAsrUp"));
        sizePolicy1.setHeightForWidth(pbAsrUp->sizePolicy().hasHeightForWidth());
        pbAsrUp->setSizePolicy(sizePolicy1);
        pbAsrUp->setMaximumSize(QSize(16777215, 16777215));
        pbAsrUp->setFont(font);

        horizontalLayout_9->addWidget(pbAsrUp);


        gridLayout_4->addLayout(horizontalLayout_9, 3, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        sbMagribAdjustment = new QSpinBox(scrollAreaWidgetContents);
        sbMagribAdjustment->setObjectName(QString::fromUtf8("sbMagribAdjustment"));
        sbMagribAdjustment->setFont(font);
        sbMagribAdjustment->setReadOnly(true);
        sbMagribAdjustment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbMagribAdjustment->setMinimum(-99);
        sbMagribAdjustment->setMaximum(99);
        sbMagribAdjustment->setValue(0);

        horizontalLayout_10->addWidget(sbMagribAdjustment);

        pbMagribDown = new QPushButton(scrollAreaWidgetContents);
        pbMagribDown->setObjectName(QString::fromUtf8("pbMagribDown"));
        sizePolicy1.setHeightForWidth(pbMagribDown->sizePolicy().hasHeightForWidth());
        pbMagribDown->setSizePolicy(sizePolicy1);
        pbMagribDown->setMaximumSize(QSize(16777215, 16777215));
        pbMagribDown->setFont(font);

        horizontalLayout_10->addWidget(pbMagribDown);

        pbMagribUp = new QPushButton(scrollAreaWidgetContents);
        pbMagribUp->setObjectName(QString::fromUtf8("pbMagribUp"));
        sizePolicy1.setHeightForWidth(pbMagribUp->sizePolicy().hasHeightForWidth());
        pbMagribUp->setSizePolicy(sizePolicy1);
        pbMagribUp->setMaximumSize(QSize(16777215, 16777215));
        pbMagribUp->setFont(font);

        horizontalLayout_10->addWidget(pbMagribUp);


        gridLayout_4->addLayout(horizontalLayout_10, 4, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        sbIshaAdjustment = new QSpinBox(scrollAreaWidgetContents);
        sbIshaAdjustment->setObjectName(QString::fromUtf8("sbIshaAdjustment"));
        sbIshaAdjustment->setFont(font);
        sbIshaAdjustment->setReadOnly(true);
        sbIshaAdjustment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbIshaAdjustment->setMinimum(-99);
        sbIshaAdjustment->setMaximum(99);
        sbIshaAdjustment->setValue(0);

        horizontalLayout_11->addWidget(sbIshaAdjustment);

        pbIshaDown = new QPushButton(scrollAreaWidgetContents);
        pbIshaDown->setObjectName(QString::fromUtf8("pbIshaDown"));
        sizePolicy1.setHeightForWidth(pbIshaDown->sizePolicy().hasHeightForWidth());
        pbIshaDown->setSizePolicy(sizePolicy1);
        pbIshaDown->setMaximumSize(QSize(16777215, 16777215));
        pbIshaDown->setFont(font);

        horizontalLayout_11->addWidget(pbIshaDown);

        pbIshaUp = new QPushButton(scrollAreaWidgetContents);
        pbIshaUp->setObjectName(QString::fromUtf8("pbIshaUp"));
        sizePolicy1.setHeightForWidth(pbIshaUp->sizePolicy().hasHeightForWidth());
        pbIshaUp->setSizePolicy(sizePolicy1);
        pbIshaUp->setMaximumSize(QSize(16777215, 16777215));
        pbIshaUp->setFont(font);

        horizontalLayout_11->addWidget(pbIshaUp);


        gridLayout_4->addLayout(horizontalLayout_11, 5, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        sbFajrAdjustment = new QSpinBox(scrollAreaWidgetContents);
        sbFajrAdjustment->setObjectName(QString::fromUtf8("sbFajrAdjustment"));
        sbFajrAdjustment->setFont(font);
        sbFajrAdjustment->setStyleSheet(QString::fromUtf8(""));
        sbFajrAdjustment->setFrame(true);
        sbFajrAdjustment->setReadOnly(true);
        sbFajrAdjustment->setButtonSymbols(QAbstractSpinBox::NoButtons);
        sbFajrAdjustment->setMinimum(-99);
        sbFajrAdjustment->setMaximum(99);
        sbFajrAdjustment->setValue(0);

        horizontalLayout_7->addWidget(sbFajrAdjustment);

        pbFajrDown = new QPushButton(scrollAreaWidgetContents);
        pbFajrDown->setObjectName(QString::fromUtf8("pbFajrDown"));
        sizePolicy1.setHeightForWidth(pbFajrDown->sizePolicy().hasHeightForWidth());
        pbFajrDown->setSizePolicy(sizePolicy1);
        pbFajrDown->setMinimumSize(QSize(0, 0));
        pbFajrDown->setMaximumSize(QSize(16777215, 16777215));
        pbFajrDown->setFont(font);

        horizontalLayout_7->addWidget(pbFajrDown);

        pbFajrUp = new QPushButton(scrollAreaWidgetContents);
        pbFajrUp->setObjectName(QString::fromUtf8("pbFajrUp"));
        sizePolicy1.setHeightForWidth(pbFajrUp->sizePolicy().hasHeightForWidth());
        pbFajrUp->setSizePolicy(sizePolicy1);
        pbFajrUp->setMinimumSize(QSize(0, 0));
        pbFajrUp->setMaximumSize(QSize(16777215, 16777215));
        pbFajrUp->setFont(font);

        horizontalLayout_7->addWidget(pbFajrUp);


        gridLayout_4->addLayout(horizontalLayout_7, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 3, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_2->addWidget(label_5);

        cbMethod = new QComboBox(tab_3);
        cbMethod->setObjectName(QString::fromUtf8("cbMethod"));
        cbMethod->setFont(font);

        verticalLayout_2->addWidget(cbMethod);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        cbMathhab = new QComboBox(tab_3);
        cbMathhab->setObjectName(QString::fromUtf8("cbMathhab"));
        cbMathhab->setFont(font);

        verticalLayout_2->addWidget(cbMathhab);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea_2 = new QScrollArea(tab_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 720, 580));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        cbCountries = new QComboBox(scrollAreaWidgetContents_2);
        cbCountries->setObjectName(QString::fromUtf8("cbCountries"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbCountries->sizePolicy().hasHeightForWidth());
        cbCountries->setSizePolicy(sizePolicy2);
        cbCountries->setFont(font);
        cbCountries->setStyleSheet(QString::fromUtf8(""));
        cbCountries->setInsertPolicy(QComboBox::InsertAlphabetically);
        cbCountries->setDuplicatesEnabled(false);

        verticalLayout_4->addWidget(cbCountries);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_4->addWidget(label);

        cbCities = new QComboBox(scrollAreaWidgetContents_2);
        cbCities->setObjectName(QString::fromUtf8("cbCities"));
        cbCities->setFont(font);
        cbCities->setInsertPolicy(QComboBox::InsertAlphabetically);
        cbCities->setDuplicatesEnabled(true);

        verticalLayout_4->addWidget(cbCities);


        verticalLayout->addLayout(verticalLayout_4);

        gridDetails = new QGridLayout();
        gridDetails->setObjectName(QString::fromUtf8("gridDetails"));
        lblLatitude = new QLabel(scrollAreaWidgetContents_2);
        lblLatitude->setObjectName(QString::fromUtf8("lblLatitude"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblLatitude->sizePolicy().hasHeightForWidth());
        lblLatitude->setSizePolicy(sizePolicy3);
        lblLatitude->setFont(font);

        gridDetails->addWidget(lblLatitude, 1, 0, 1, 1);

        tbLatitude = new QLineEdit(scrollAreaWidgetContents_2);
        tbLatitude->setObjectName(QString::fromUtf8("tbLatitude"));
        tbLatitude->setFont(font);

        gridDetails->addWidget(tbLatitude, 1, 1, 1, 1);

        lblLongitude = new QLabel(scrollAreaWidgetContents_2);
        lblLongitude->setObjectName(QString::fromUtf8("lblLongitude"));
        lblLongitude->setFont(font);

        gridDetails->addWidget(lblLongitude, 2, 0, 1, 1);

        tbLongitude = new QLineEdit(scrollAreaWidgetContents_2);
        tbLongitude->setObjectName(QString::fromUtf8("tbLongitude"));
        tbLongitude->setFont(font);

        gridDetails->addWidget(tbLongitude, 2, 1, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridDetails->addWidget(label_2, 3, 0, 1, 1);

        tbGmtOffset = new QLineEdit(scrollAreaWidgetContents_2);
        tbGmtOffset->setObjectName(QString::fromUtf8("tbGmtOffset"));
        tbGmtOffset->setFont(font);

        gridDetails->addWidget(tbGmtOffset, 3, 1, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridDetails->addWidget(label_4, 0, 0, 1, 1);

        tbLocation = new QLineEdit(scrollAreaWidgetContents_2);
        tbLocation->setObjectName(QString::fromUtf8("tbLocation"));
        tbLocation->setFont(font);

        gridDetails->addWidget(tbLocation, 0, 1, 1, 1);

        cbDaylightSaving = new QCheckBox(scrollAreaWidgetContents_2);
        cbDaylightSaving->setObjectName(QString::fromUtf8("cbDaylightSaving"));
        cbDaylightSaving->setFont(font);
        cbDaylightSaving->setLayoutDirection(Qt::LeftToRight);
        cbDaylightSaving->setChecked(false);
        cbDaylightSaving->setAutoRepeat(false);
        cbDaylightSaving->setAutoExclusive(false);
        cbDaylightSaving->setTristate(false);

        gridDetails->addWidget(cbDaylightSaving, 4, 0, 1, 2);


        verticalLayout->addLayout(gridDetails);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(scrollArea_2, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(settingsDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout->addWidget(cancelButton);

        saveButton = new QPushButton(settingsDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font);

        horizontalLayout->addWidget(saveButton);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(settingsDialog);

        tabWidget->setCurrentIndex(0);
        cbMethod->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(settingsDialog);
    } // setupUi

    void retranslateUi(QDialog *settingsDialog)
    {
        settingsDialog->setWindowTitle(QApplication::translate("settingsDialog", "Add location", 0, QApplication::UnicodeUTF8));
        lblEDAthan->setText(QApplication::translate("settingsDialog", "Athan On/Off", 0, QApplication::UnicodeUTF8));
        lblAthanAdjustment->setText(QApplication::translate("settingsDialog", "Adjustment", 0, QApplication::UnicodeUTF8));
        cbFajrEnabled->setText(QApplication::translate("settingsDialog", "Fajr", 0, QApplication::UnicodeUTF8));
        cbDuhrEnabled->setText(QApplication::translate("settingsDialog", "Duhr", 0, QApplication::UnicodeUTF8));
        cbAsrEnabled->setText(QApplication::translate("settingsDialog", "Asr", 0, QApplication::UnicodeUTF8));
        cbMagribEnabled->setText(QApplication::translate("settingsDialog", "Magrib", 0, QApplication::UnicodeUTF8));
        cbIshaEnabled->setText(QApplication::translate("settingsDialog", "Isha", 0, QApplication::UnicodeUTF8));
        sbDuhrAdjustment->setSuffix(QApplication::translate("settingsDialog", " Minutes", 0, QApplication::UnicodeUTF8));
        pbDuhrDown->setText(QApplication::translate("settingsDialog", "-", 0, QApplication::UnicodeUTF8));
        pbDuhrUp->setText(QApplication::translate("settingsDialog", "+", 0, QApplication::UnicodeUTF8));
        sbAsrAdjustment->setSuffix(QApplication::translate("settingsDialog", " Minutes", 0, QApplication::UnicodeUTF8));
        pbAsrDown->setText(QApplication::translate("settingsDialog", "-", 0, QApplication::UnicodeUTF8));
        pbAsrUp->setText(QApplication::translate("settingsDialog", "+", 0, QApplication::UnicodeUTF8));
        sbMagribAdjustment->setSuffix(QApplication::translate("settingsDialog", " Minutes", 0, QApplication::UnicodeUTF8));
        pbMagribDown->setText(QApplication::translate("settingsDialog", "-", 0, QApplication::UnicodeUTF8));
        pbMagribUp->setText(QApplication::translate("settingsDialog", "+", 0, QApplication::UnicodeUTF8));
        sbIshaAdjustment->setSuffix(QApplication::translate("settingsDialog", " Minutes", 0, QApplication::UnicodeUTF8));
        pbIshaDown->setText(QApplication::translate("settingsDialog", "-", 0, QApplication::UnicodeUTF8));
        pbIshaUp->setText(QApplication::translate("settingsDialog", "+", 0, QApplication::UnicodeUTF8));
        sbFajrAdjustment->setSpecialValueText(QString());
        sbFajrAdjustment->setSuffix(QApplication::translate("settingsDialog", " Minutes", 0, QApplication::UnicodeUTF8));
        sbFajrAdjustment->setPrefix(QString());
        pbFajrDown->setText(QApplication::translate("settingsDialog", "-", 0, QApplication::UnicodeUTF8));
        pbFajrUp->setText(QApplication::translate("settingsDialog", "+", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("settingsDialog", "Athan Options", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("settingsDialog", "Method", 0, QApplication::UnicodeUTF8));
        cbMethod->clear();
        cbMethod->insertItems(0, QStringList()
         << QApplication::translate("settingsDialog", "Egyptian General Authority of Survey", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "University of Islamic Sciences, Karachi (Shaf'i)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "University of Islamic Sciences, Karachi (Hanafi)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Islamic Society of North America", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Muslim World League", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Umm Al-Qurra (Saudi Arabia)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Fixed Ishaa Interval (Mahgrib to Ishaa 90min)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Egyptian General Authority of Survey (Egypt)", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("settingsDialog", "Asr Timing", 0, QApplication::UnicodeUTF8));
        cbMathhab->clear();
        cbMathhab->insertItems(0, QStringList()
         << QApplication::translate("settingsDialog", "Standard (Shaf'i, Maliki, Hanbali)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("settingsDialog", "Hanafi", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("settingsDialog", "         Method", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("settingsDialog", "Country", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("settingsDialog", "City", 0, QApplication::UnicodeUTF8));
        lblLatitude->setText(QApplication::translate("settingsDialog", "Latitude", 0, QApplication::UnicodeUTF8));
        lblLongitude->setText(QApplication::translate("settingsDialog", "Longitude", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("settingsDialog", "GMT Offset", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("settingsDialog", "Location", 0, QApplication::UnicodeUTF8));
        cbDaylightSaving->setText(QApplication::translate("settingsDialog", "Day Light Saving", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("settingsDialog", "         Location", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("settingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("settingsDialog", "Save Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class settingsDialog: public Ui_settingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
