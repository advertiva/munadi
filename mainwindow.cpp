#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "updater.h"

#include <QTime>
#include <QtWidgets/QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    :
      QMainWindow(parent, Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint),
      ui(new Ui::MainWindow),
      closeWindow(false),
      addCity(0)
{
    ui->setupUi(this);
    ui->QiblaDirection->installEventFilter(this);                    // Capture events pertaining to the Qibla Direction Widget (We're just interested in the painter event to draw the compass)
    munadi = new MunadiEngine(this);
    setGeometry(munadi->settings->screenGeo);

    if(munadi->settings->showOnAthan)
    {
        ui->actionShow_On_Athan->setChecked(true);
        connect(munadi, SIGNAL(athanTriggered()), this, SLOT(show()));
    }

    if(munadi->settings->checkForUpdates)
    {
        ui->actionCheck_for_updates->setChecked(true);
        Updater * up = new Updater(this);
    }

    if(munadi->settings->compactMode)
    {
        on_actionCompact_mode_triggered(true);
        ui->actionCompact_mode->setChecked(true);
    }
    else
    {
        on_actionCompact_mode_triggered(false);
    }

#ifdef Q_OS_WIN
    QSettings startup("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                      QSettings::NativeFormat);
    QString ret = startup.value(QApplication::applicationName(), "0").toString();
    if(ret.toUpper() != "0")
    {
        ui->actionStart_with_PC->setChecked(true);
    }
#endif

#ifdef Q_OS_MAC
    ui->actionStart_with_PC->setVisible(false);
#endif

    connect(munadi, SIGNAL(stateChanged()), this, SLOT(updateDisplay()));
    updateDisplay();

    trayMenu = new QMenu("trayMenu", this);
    createTrayMenu();

    tray = new QSystemTrayIcon(QIcon(":/icons/app"), this);
    tray->setContextMenu(trayMenu);
    tray->show();

#ifdef Q_OS_WIN
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
#endif
}

MainWindow::~MainWindow()
{
    munadi->settings->screenGeo = this->geometry();

    if(munadi)  delete munadi;
    if(ui)      delete ui;
}

void MainWindow::createTrayMenu()
{
    trayMenu->addAction(QIcon(":/icons/play"), "Play Athan", munadi, SLOT(playAthan()));
    trayMenu->addAction(QIcon(":/icons/stop"), "Stop Athan", munadi, SLOT(stopAthan()));
    trayMenu->addSeparator();
    trayMenu->addAction("Hide/Show Window", this, SLOT(toggleView()));
    trayMenu->addAction(QIcon(":/icons/exit"), "Close Munadi", this, SLOT(on_actionE_xit_triggered()));
}

//************************************************
//                       SLOTS                   *
//************************************************

void MainWindow::updateDisplay()
{
    //if(this->isVisible() == false)  return;

    QString format = "hh:mm ap";
    ui->lblFajr->setText(munadi->getFajr().toString(format));
    ui->lblSunrise->setText(munadi->getSunrise().toString(format));
    ui->lblDuhr->setText(munadi->getDuhr().toString(format));
    ui->lblAsr->setText(munadi->getAsr().toString(format));
    ui->lblMagrib->setText(munadi->getMagrib().toString(format));
    ui->lblIsha->setText(munadi->getIsha().toString(format));
    ui->lblCity->setText(munadi->settings->getCity().name);

    ui->lblHijriDate->setText(munadi->getHijriDate());
    ui->lblHijriEvent->setText(munadi->getHijriEvent());

    update();

    if(munadi->isAthanPlaying())
        ui->lblInfo->setText(munadi->getCurrPrayerLabel() + " prayer time ...");
    else
        ui->lblInfo->setText(munadi->getNextPrayerLabel() + " in " + munadi->getTimeDifference());

    dout << "Display updated.";
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Trigger :
        case QSystemTrayIcon::DoubleClick:
        case QSystemTrayIcon::MiddleClick:
        if(isVisible() == true)
        {
            hide();
        }
        else
        {
            //setWindowState(Qt::WindowNoState | Qt::WindowActive);
            //show();

            setWindowState( (windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
            show();
            raise();  // for MacOS
            activateWindow(); // for Windows
        }
        break;
    }
}

void MainWindow::showEvent(QShowEvent * event)
{
    updateDisplay();
    event->accept();
}
void MainWindow::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);
        if (event->type() == QEvent::WindowStateChange)
        {
            QWindowStateChangeEvent *e = (QWindowStateChangeEvent*)event;
            // make sure we only do this for minimize events
            if ((e->oldState() != Qt::WindowMinimized) && isMinimized())
            {
                QTimer::singleShot(0, this, SLOT(hide()));
                event->ignore();
            }
        }
}

void MainWindow::on_actionE_xit_triggered()
{
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
        addCity->showNormal();// ->show();
    }
    else
    {
        addCity->show();
    }
}

void MainWindow::on_actionAbout_Munadi_triggered()
{
    QMessageBox::information(this, "About Munadi",
                             "<h3>About Munadi</h3>"
                             "<p>Munadi - Simple Athan Program.<br/>"
                             "For more info, visit <a href=\"http://munadi.org\">Munadi.org</a></p>"
                             "<br/>"
                             "Version: "
                             APP_VERSION
                             "<br/>", QMessageBox::Ok);
}

void MainWindow::on_actionPlay_Stop_Athan_triggered()
{
    if(munadi->isAthanPlaying())
        munadi->stopAthan();
    else
        munadi->playAthan();
}

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

void MainWindow::on_actionCheck_for_updates_triggered(bool checked)
{
    if(checked)
    {
        munadi->settings->checkForUpdates = true;
    }
    else
    {
        munadi->settings->checkForUpdates = false;
    }
}

void MainWindow::on_actionCompact_mode_triggered(bool checked)
{
#ifdef Q_OS_MAC
    static int height = 480;
#else
    static int height = 500;
#endif

    if(checked)
    {
        setFixedSize(375, height);
        munadi->settings->compactMode = true;
    }
    else
    {
        setFixedSize(640, height);
        munadi->settings->compactMode = false;
    }
}

void MainWindow::on_actionStart_with_PC_triggered(bool checked)
{
#ifdef Q_OS_WIN
    if(checked)
    {
        QSettings startup("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                          QSettings::NativeFormat);
        startup.setValue(QApplication::applicationName(), "\"" + QApplication::applicationFilePath().replace('/','\\') + "\"" + " -startup");
    }
    else
    {
        QSettings startup("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
                          QSettings::NativeFormat);
        startup.remove(QApplication::applicationName());
    }
#endif
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)                                           // This function catches events and filters out the paint event
{                                                                                                   // of the QiblaDirection widget to draw the compass and the qibla direction
        if (obj==ui->QiblaDirection)
        {
            dout << "event filter (QiblaDirection)...";

            if (event->type()==QEvent::Paint)
            {
                dout << "event filter (QiblaDirection- paint event)...";

                int side;
                int factor = 10;
                side = qMin(ui->QiblaDirection->height(),ui->QiblaDirection->width());
                QPoint arrow[3] =
                {
                    QPoint(0,-side/2.5+side/factor),
                    QPoint(-side/(5*factor),-side/10+side/(3*factor)+side/factor),
                    QPoint(side/(5*factor),-side/10+side/(3*factor)+side/factor)
                };
                QPainter painter(ui->QiblaDirection);

                painter.setRenderHint(QPainter::Antialiasing);
                painter.setPen(Qt::lightGray);
                painter.setFont(QFont("Arial", side/factor));
                //painter.drawText(side/2-side/(2*factor), side/factor, "N");
                //painter.drawText(side/2-side/(2*factor),side, "S");
                //painter.drawText(0, side/2+side/(2*factor), "W");
                //painter.drawText(side-(side/factor),side/2+side/(2*factor), "E");
                //painter.setBrush();
                painter.setBrush(Qt::white);
                //painter.drawEllipse(side/2-side/(6*factor),side/2-side/(6*factor),side/(3*factor),side/(3*factor));
                painter.setBrushOrigin(side/2,side/2);

                painter.translate(side/2,side/2);
                painter.save();
                painter.rotate(-munadi->settings->qiblaAngle);
                //painter.drawLine(0,0,0,-side/2+side/factor);
                painter.drawConvexPolygon(arrow,3);

                painter.restore();

                //painter.setBrush(Qt::white);
                //painter.drawEllipse(-side/2, -side/2, side, side);
                //painter.drawEllipse(-side/2+side/(factor),-side/2+side/(factor),side-2*side/factor, side-2*side/factor);

    //            painter.setFont(QFont("Arial", side/(2*factor)));
    //            if (munadi->settings->qiblaAngle > -90 && munadi->settings->qiblaAngle < 90)
    //            {
    //                painter.drawText(-2*side/factor,side/factor,QString::number(munadi->settings->qiblaAngle) + trUtf8("° wrt N"));
    //            }
    //            else
    //            {
    //                painter.drawText(-2*side/factor,-side/factor,QString::number(munadi->settings->qiblaAngle) + trUtf8("° wrt N"));
    //            }

                return true;
            }
            else
            {
                return false;
            }
        }
        else return QMainWindow::eventFilter(obj,event);
}

