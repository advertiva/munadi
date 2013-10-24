#include "maemo_mainwindow.h"
#include "ui_maemo_mainwindow.h"
#include "settings.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    :
      QMainWindow(parent),
      ui(new Ui::MainWindow),
      closeWindow(false),
      addCity(0)
{
    ui->setupUi(this);
    ui->QiblaDirection->installEventFilter(this);                    // Capture events pertaining to the Qibla Direction Widget (We're just interested in the painter event to draw the compass)
    //setAttribute(Qt::WA_Maemo5AutoOrientation, true);

    munadi = new MunadiEngine(this);
    this->setGeometry(0,0,1024,600);

//    if(munadi->settings->showOnAthan)
//    {
//        ui->actionShow_On_Athan->setChecked(true);
//        connect(munadi, SIGNAL(athanTriggered()), this, SLOT(show()));
//    }

    connect(munadi, SIGNAL(stateChanged()), this, SLOT(updateDisplay()));
//    connect(QApplication::desktop(), SIGNAL(resized(int)), this, SLOT(orientationChanged()));
    updateDisplay();

//    QPixmap pixmap;
//    pixmap.fromImage("/home/haqman/Development/Playbook/munadi/images/mmm.png");


}

MainWindow::~MainWindow()
{
    if(munadi)  delete munadi;
    if(ui)      delete ui;
}

//************************************************
//                       SLOTS                   *
//************************************************

void MainWindow::updateDisplay()
{
    QString format = "hh:mm ap";
    ui->lblFajr->setText(munadi->getFajr().toString(format));
    ui->lblSunrise->setText(munadi->getSunrise().toString(format));
    ui->lblDuhr->setText(munadi->getDuhr().toString(format));
    ui->lblAsr->setText(munadi->getAsr().toString(format));
    ui->lblMagrib->setText(munadi->getMagrib().toString(format));
    ui->lblIsha->setText(munadi->getIsha().toString(format));
    ui->lblCity->setText(munadi->settings->getCity().name);

    if(munadi->isAthanPlaying())
        ui->lblInfo->setText(munadi->getCurrPrayerLabel() + " prayer time ...");
    else if(munadi->getNextPrayerLabel() == "none")
        ui->lblInfo->setText("");   // All athan disabled
    else
        ui->lblInfo->setText(munadi->getNextPrayerLabel() + " in " + munadi->getTimeDifference());

    update();
    dout << "Display updated.";
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if(closeWindow)
    {
        event->accept();
    }
    else
    {
        event->ignore();
        hide();
    }
}

void MainWindow::on_actionE_xit_triggered()
{
    closeWindow = true;
    close();
}

int MainWindow::top_application()
{
    show();
    return 0;
}

void MainWindow::on_actionNew_City_triggered()
{
    if(addCity == 0)
    {
        addCity = new settingsDialog(munadi, this);
        addCity->show();
    }
    else
    {
        addCity->show();
    }
}

void MainWindow::on_actionAbout_Munadi_triggered()
{
    QMessageBox::information(this,
                             "About Munadi",
                             "<h3>About Munadi</h3>"
                             "<p>"
                             "Munadi is a cross-platform Athan program"
                             "<br/>"
                             "For more info, visit <a href=\"http://www.sourceforge.net/projects/munadi\">Project page</a></p>"
                             "Author: "
                             "<a href=\"mailto:haqman@gmail.com\">A.Abbad</a>"
                             "<br/>"
                             "Contributers: "
                             "<a href=\"mailto:abuelmagd@gmail.com\">A.Abu-El-Magd</a>, "
                             "<a href=\"http://talk.maemo.org/showthread.php?t=67572\">Memo.org users</a>"
                             "<br/>"
                             "Translators: "
                             "<a href=\"mailto:halitbal@gmail.com\">HtheB</a>"
                             "<br/>"
                             "Version:  "
                             APP_VERSION
                             "<br/>",
                             QMessageBox::Ok);
}

void MainWindow::on_actionPlay_Stop_Athan_triggered()
{
    if(munadi->isAthanPlaying())
        munadi->stopAthan();
    else
        munadi->playAthan();
}
#ifdef TESTING
void MainWindow::on_actionTEST_PRAYER_triggered()
{
    munadi->testTime.setHMS(QTime::currentTime().hour(), QTime::currentTime().minute()+1, 0);
    updateDisplay();
}
#endif

void MainWindow::on_actionShow_On_Athan_triggered()
{
    if(ui->actionShow_On_Athan->isChecked())
    {
        munadi->settings->showOnAthan = true;
        connect(munadi, SIGNAL(athanTriggered()), this, SLOT(show()));
    }
    else
    {
        munadi->settings->showOnAthan = false;
        disconnect(munadi, SIGNAL(athanTriggered()), this, SLOT(show()));
    }
}

void MainWindow::orientationChanged()
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    if (screenGeometry.width() > screenGeometry.height()){
        ui->horizontalLayout_2->setDirection(QBoxLayout::LeftToRight);
    } else {
        ui->horizontalLayout_2->setDirection(QBoxLayout::TopToBottom);
    }
    update();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)                                           // This function catches events and filters out the paint event
{                                                                                                   // of the QiblaDirection widget to draw the compass and the qibla direction
    if (obj==ui->QiblaDirection)
    {
        if (event->type()==QEvent::Paint)
        {
            int side;
            int factor = 10;
            side = qMin(ui->QiblaDirection->height(),ui->QiblaDirection->width());
            QPoint arrow[3] =
            {
                QPoint(0,-side/2+side/factor),
                QPoint(-side/(3*factor),-side/2+side/(3*factor)+side/factor),
                QPoint(side/(3*factor),-side/2+side/(3*factor)+side/factor)
            };
            QPainter painter(ui->QiblaDirection);

            //painter.setPen(Qt::white);
            painter.setFont(QFont("Arial", side/factor));
            painter.drawText(side/2-side/(2*factor), side/factor, "N");
            painter.drawText(side/2-side/(2*factor),side, "S");
            painter.drawText(0, side/2+side/(2*factor), "W");
            painter.drawText(side-(side/factor),side/2+side/(2*factor), "E");
            painter.setBrush(Qt::white);
            painter.drawEllipse(side/2-side/(6*factor),side/2-side/(6*factor),side/(3*factor),side/(3*factor));
            painter.setBrushOrigin(side/2,side/2);

            painter.translate(side/2,side/2);
            painter.save();
            painter.rotate(-munadi->settings->qiblaAngle);
            painter.drawLine(0,0,0,-side/2+side/factor);
            painter.drawConvexPolygon(arrow,3);

            painter.restore();

            painter.setBrush(Qt::NoBrush);
            painter.drawEllipse(-side/2, -side/2, side, side);
            painter.drawEllipse(-side/2+side/(factor),-side/2+side/(factor),side-2*side/factor, side-2*side/factor);

            painter.setFont(QFont("Arial", side/(2*factor)));
            if (munadi->settings->qiblaAngle > -90 && munadi->settings->qiblaAngle < 90)
            {
                painter.drawText(-2*side/factor,side/factor,QString::number(munadi->settings->qiblaAngle) + trUtf8("° wrt N"));
            }
            else
            {
                painter.drawText(-2*side/factor,-side/factor,QString::number(munadi->settings->qiblaAngle) + trUtf8("° wrt N"));
            }

            return true;
        }
        else
        {
            return false;
        }
    }
    else return QMainWindow::eventFilter(obj,event);
}
