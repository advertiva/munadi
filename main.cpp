#include <QApplication>
#include <
//#include <QtDBus/QtDBus>

#include "globals.h"

//#ifdef Q_WS_MAEMO_5
//#include "maemo_mainwindow.h"
//#else
#include "mainwindow.h"
//#endif

//#include "playbook.h"

int main(int argc, char *argv[])
{

    //QCoreApplication::addLibraryPath("app/native/lib");
    QApplication a(argc, argv);
    a.setApplicationName("munadi");
    a.setApplicationVersion(APP_VERSION);
    a.setOrganizationName("HaqMan");

    //a.setStyle("plastique");

    MainWindow w;
    //Playbook w;

#ifdef Q_WS_MAEMO_5

    if (!QDBusConnection::sessionBus().isConnected()) {
        qWarning("Cannot connect to the D-Bus session bus.");
        exit(1);
    }

    if (!QDBusConnection::sessionBus().registerService("org.indt.munadi")) {
        qWarning("%s", qPrintable(QDBusConnection::sessionBus().lastError().
            message()));
        exit(2);
    }

    if (!QDBusConnection::sessionBus().registerObject("/org/indt/munadi", &w,
            QDBusConnection::ExportScriptableSlots)) {
        qWarning("%s", qPrintable(QDBusConnection::sessionBus().lastError().
            message()));
        exit(3);
    }

#endif

    w.showFullScreen();

    return a.exec();
}
