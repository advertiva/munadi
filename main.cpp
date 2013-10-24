#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
