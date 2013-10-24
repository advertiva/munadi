import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

Rectangle {
    color: "black"
    //border.width: 3
    //border.color: "black"
    width: 1; height: 1

    Layout.fillWidth: true
    Layout.fillHeight: true

    Rectangle {
        id: eItem
        width: parent.width - 6
        anchors.top: parent.top
        anchors.bottom: buttons.top
        anchors.margins: 3
        anchors.horizontalCenter: parent.horizontalCenter

        //color: "yellow"
    }

    Rectangle {
        id: buttons
        anchors.bottom: parent.bottom
        anchors.margins: 3
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 6
        height: 60
    }
}
