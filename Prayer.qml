import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

GridLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    columnSpacing: 1

    property alias prayerName: prayer.text
    property alias prayerTime: time.text

    Tuple {
        id: prayer
        Layout.column: main.mirror === true ? 1 : 0
    }

    Tuple {
        id: time
        Layout.column: main.mirror === true ? 0 : 1
    }
}
