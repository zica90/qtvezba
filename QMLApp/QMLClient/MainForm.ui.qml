import QtQuick 2.6
import QtQuick.Controls 2.2

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    property alias button3: button3
    property alias button2: button2
    property alias button1: button1
    property alias button: button

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Button {
            id: button
            x: 8
            y: 312
            width: 53
            height: 40
            text: qsTr("Konekt")
        }

        Button {
            id: button1
            x: 67
            y: 312
            width: 73
            height: 40
            text: qsTr("Show Menu")
        }

        Button {
            id: button2
            x: 146
            y: 312
            width: 96
            height: 40
            text: qsTr("pay with EUR")
        }

        Button {
            id: button3
            x: 252
            y: 312
            text: qsTr("pay wit RSD")
        }
    }
}
