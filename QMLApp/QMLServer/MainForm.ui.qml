import QtQuick 2.6
import QtQuick.Controls 2.2

Rectangle {
    property alias mouseArea: mouseArea
    property alias id: textEdit
    property alias name: textEdit1
    property alias price: textEdit2
    property alias stock: textEdit3
    property alias insertButton: insertButton

    // property alias sendBill: sendBill
    width: 360
    height: 360
    property alias button: button

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        TextEdit {
            id: textEdit1
            x: 18
            y: 60
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }

        TextEdit {
            id: textEdit2
            x: 18
            y: 110
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }

        TextEdit {
            id: textEdit3
            x: 18
            y: 160
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }

        Button {
            id: button
            x: 18
            y: 210
            text: qsTr("Start Server")
        }
        Button {
            id: insertButton
            x: 180
            y: 210
            text: qsTr("Insert")
        }
    }

    TextEdit {
        id: textEdit
        x: 18
        y: 10
        width: 80
        height: 20
        text: qsTr("")
        font.pixelSize: 12
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
