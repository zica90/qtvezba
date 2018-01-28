import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Server")

    MainForm {
        anchors.fill: parent

        Button {
            id: buttonServer
            x: 8
            y: 312
            text: qsTr("Start Server")
            onClicked: {
                backEnd.startServer()
                buttonServer.visible=false
            }
        }

        Button {
            visible: false
            id: buttonInsertFood
            x: 260
            y: 160
            text: qsTr("Insert")
            onClicked: {
                backEnd.insertFoodinDB(textEditID.text,textEditName.text,textEditPrice.text)
            }
        }

        Button {
            visible: false
            objectName: "buttonSendData"
            id: buttonSendData
            x: 252
            y: 312
            text: qsTr("Send Data")
            onClicked: backEnd.sendBill()
        }

        TextEdit {
            visible: false
            id: textEditID
            x: 272
            y: 20
            width: 80
            height: 20
            text: qsTr("enter ID")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1

            }
        }

        TextEdit {
            visible: false
            id: textEditName
            x: 272
            y: 70
            width: 80
            height: 20
            text: qsTr("Text Edit")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }

        TextEdit {
            visible: false
            id: textEditPrice
            x: 272
            y: 120
            width: 80
            height: 20
            text: qsTr("Text Edit")
            font.pixelSize: 12
            Rectangle {
                anchors.fill: parent
                anchors.margins: -10
                color: "transparent"
                border.width: 1
            }
        }

        Button {
            id: buttonInsert
            x: 130
            y: 312
            text: qsTr("Insert")
            onClicked: {
                buttonInsertFood.visible=true
                textEditID.visible=true;
                textEditName.visible=true;
                textEditPrice.visible=true;
            }
        }
        ListView {
            id: listViewBill
            x: 8
            y: 8
            width: 110
            height: 160
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    Rectangle {
                        width: 40
                        height: 40
                    }

                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
            model: ListModel {
                objectName: "listModelBill"
                id:listModelBill
                function showBill(data){
                    listModelBill.append({name:data})
                }

            }
        }

    }

}
