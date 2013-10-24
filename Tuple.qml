import QtQuick 2.1
import QtQuick.Layouts 1.0

Rectangle {
    //color: "red"
    width: 1; height: 1
    Layout.fillWidth: true
    Layout.fillHeight: true

    property alias text: label.text
    property alias italic: label.font.italic

    Text {
        id: label
        //width: parent.width
        //height: parent.height
        //anchors.leftMargin: 10
        anchors.centerIn: parent
        font.pixelSize: parent.height / 2
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }
}
