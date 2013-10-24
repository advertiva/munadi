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

    ColumnLayout {
        anchors.margins: 3
        anchors.fill: parent
        spacing: 1

//        Tuple {
//            text: qsTr("Birmingham, UK, lol, lol2, .lol3, lol4")
//            italic: true
//        }

        Prayer {
            prayerName: qsTr("Fajr")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Prayer {
            prayerName: qsTr("Sunrise")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Prayer {
            prayerName: qsTr("Duhr")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Prayer {
            prayerName: qsTr("Asr")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Prayer {
            prayerName: qsTr("Magrib")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Prayer {
            prayerName: qsTr("Ishaa")
            prayerTime: Qt.formatTime(new Date(), "h:mm AP")
        }

        Rectangle {
            width: 1; height: 1
            Layout.fillWidth: true
            Layout.fillHeight: true

            Text {
                anchors.centerIn: parent
                font.pixelSize: parent.height / 3
                font.italic: true
                text: qsTr("Fajr in 22 hours, 22 minutes ...")
            }
        }
    }
}
