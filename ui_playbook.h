/********************************************************************************
** Form generated from reading UI file 'playbook.ui'
**
** Created: Sun Jan 20 00:12:08 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYBOOK_H
#define UI_PLAYBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Playbook
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *Playbook)
    {
        if (Playbook->objectName().isEmpty())
            Playbook->setObjectName(QString::fromUtf8("Playbook"));
        Playbook->resize(1280, 768);
        Playbook->setStyleSheet(QString::fromUtf8("QWidget#Playbook { background-image: url(/home/haqman/Development/Playbook/munadi/images/mmm.png) }"));
        label = new QLabel(Playbook);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 130, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Purisa"));
        font.setPointSize(14);
        font.setItalic(true);
        font.setKerning(true);
        label->setFont(font);
        label->setScaledContents(false);
        label_2 = new QLabel(Playbook);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 180, 101, 41));
        label_2->setFont(font);
        label_2->setScaledContents(false);
        label_3 = new QLabel(Playbook);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 240, 111, 41));
        label_3->setFont(font);
        label_3->setScaledContents(false);
        label_4 = new QLabel(Playbook);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 300, 101, 41));
        label_4->setFont(font);
        label_4->setScaledContents(false);
        label_5 = new QLabel(Playbook);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 360, 101, 41));
        label_5->setFont(font);
        label_5->setScaledContents(false);
        label_6 = new QLabel(Playbook);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 430, 91, 41));
        label_6->setFont(font);
        label_6->setScaledContents(false);

        retranslateUi(Playbook);

        QMetaObject::connectSlotsByName(Playbook);
    } // setupUi

    void retranslateUi(QWidget *Playbook)
    {
        Playbook->setWindowTitle(QApplication::translate("Playbook", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Playbook", "05:55 AM", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Playbook", "07:05 AM", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Playbook", "12:22 AM", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Playbook", "15:45 AM", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Playbook", "17:01 AM", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Playbook", "18:19 AM", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Playbook: public Ui_Playbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYBOOK_H
