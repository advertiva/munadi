import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Rectangle {
    id: main
    width: 640
    height: 480
    color: "#F7F7EB"

    property bool mirror: false

    GridLayout {
        anchors.fill: parent
        rowSpacing: 10
        anchors.margins: 15

        Table {
            id: table
            Layout.column: main.mirror === true ? 1 : 0
        }

        Extras {
            id: utils
            Layout.column: main.mirror === true ? 0 : 1
        }
    }
}
