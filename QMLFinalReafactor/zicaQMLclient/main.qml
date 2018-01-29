import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    function checkDuplicate(data){
        for(var i=0;i<listModelBasket.count;i++)
        {
            if(data == listModelBasket.get(i).name) return 1;
        }
        return 0;
    }
    function setVisibility()
    {
        listModelBasket.clear()
        listModelMenu.clear()
        listModelBasket.append({name:"waiting for bill..."})
        buttonEU.visible=false
        buttonRSD.visible=false

    }

    MainForm {
        anchors.fill: parent
        Button {
            id: connectToServer
            x: 8
            y: 312
            text: qsTr("connectToServer")
            onClicked:{
                backEnd.connectToServer()
                connectToServer.visible=false
            }

        }

        Button {
            id: buttonEU
            x: 130
            y: 312
            text: qsTr("Pay With EU")
            onClicked: {
                setVisibility()
                backEnd.sendData("EU")
            }
        }

        Button {
            id: buttonRSD
            x: 252
            y: 312
            text: qsTr("Pay With RSD")
            onClicked: {
                setVisibility()
                backEnd.sendData("RSD")
            }
        }

        ListView {
            id: listViewMenu
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
                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                        MouseArea{
                            anchors.fill: parent
                            onClicked:{
                                var txt=parent.text.split(";");
                                if(checkDuplicate(parent.text)==0)
                                {
                                    listModelBasket.append({name: txt[1]+"   "+txt[2]})
                                }
                                var str=parent.text.substring(0,4)
                                backEnd.addToBasket(str)

                            }
                        }

                    }
                    spacing: 10
                }

            }
            model: ListModel {
                id:listModelMenu
                objectName: "listModelMenu"
                function listModelAppend(item)
                {
                    listModelMenu.append({name: item})
                }
            }
        }

        ListView {
            id: listViewBasket
            x: 183
            y: 8
            width: 110
            height: 160
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row2
                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
            model: ListModel {
                id:listModelBasket
                objectName: "listModelBasket"
                function showBill(data){
                    console.log("x");
                    listModelBasket.clear()
                    listModelBasket.append({name:data})
                }
            }
        }

    }
}
