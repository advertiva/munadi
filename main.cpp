#include "globals.h"
#include <QtWidgets/QApplication>


#ifdef Q_WS_MAEMO_5
#include <QtDBus/QtDBus>
#endif

#ifdef Q_WS_MAEMO_5
#include "maemo_mainwindow.h"
#else
#include "mainwindow.h"
#endif

#ifdef Q_OS_WIN
#include <windows.h>
#endif

int main(int argc, char *argv[])
{

#ifdef  Q_OS_WIN
    CreateMutex(0, true, L"99da0a5f-1f0d-4e14-97f6-b0919b9ec9cd");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        MessageBox(
            NULL,
            (LPCWSTR)L"Can't start more than one instance of Munadi.",
            (LPCWSTR)L"Munadi running",
            MB_ICONWARNING | MB_DEFBUTTON2
        );
        exit(0);
    }
#endif

    QApplication a(argc, argv);
    a.setApplicationName("Munadi");
    a.setApplicationVersion(APP_VERSION);
    a.setOrganizationName("Munadi.org");

    MainWindow w;

    if(argc == 2 && strcmp(argv[1], "-startup") == 0)
        return a.exec();
    else
    {
        w.show();
        return a.exec();
    }

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


}
