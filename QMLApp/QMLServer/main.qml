import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id:mainWindow
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    MainForm {
        Button {
            id: sendBill
            objectName: "sendBill"
            x: 150
            y: 210
            text: qsTr("sendBill")
            visible: false
            onClicked:{
                be.sendBill()
                sendBill.visible=false
                listModel.clear()
            }
        }
        ListView {

            id: listView
            x: 0
            y: 300
            width: 110
            height: 160

            model: ListModel {
                id: listModel
                objectName: "listModel"
                function showBill(x){
                    listModel.append({name: x})
                }
            }
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    Text {

                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                        MouseArea {
                            anchors.fill: parent
                            onClicked:{
                                var txt=parent.text.split(";");
                                if(checkDuplicate(parent.text)==0){
                                    listModelBasket.append({name: txt[1]+"   "+txt[2]})}
                                var str=parent.text.substring(0,1)
                                backEnd.addItemToBasket(str)

                            }
                        }
                    }
                    spacing: 10
                }
            }
        }



        button.onClicked: {

            //   db.insertComicBook(id.text,name.text,price.text,stock.text)
            // be.startServer();
            be.startServer();
            button.visible=false;
        }
        insertButton.onClicked:{
            db.insertComicBook(id.text,name.text,price.text,stock.text)
        }

        anchors.fill: parent
        /*     mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }*/
    }
}
