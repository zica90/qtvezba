import QtQuick 2.6
import QtQuick.Window 2.2



Window {
    id:mainWindow
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("Client")

    MainForm {
        id:mainF
        function waitBill(){
            mainF.button.visible=false;
            mainF.button1.visible=false;
            mainF.button2.visible=false;
            mainF.button3.visible=false;
            listModel.clear()
            listModel.append({name:"waiting for bill"})
        }
        button3.onClicked: {
            backEnd.sendData("RSD")
            waitBill()

        }
        button2.onClicked: {
            backEnd.sendData("EU")
            waitBill()
        }
        button1.onClicked: {
            var str=backEnd.getName();
            var xxx=str.split('|');
            for(var i=0;i<xxx.length-1;i++)
                listModel.append({name: xxx[i]})
        }

        button.onClicked: {
            backEnd.connectToServer()

        }
        anchors.fill: parent
    }


    ListView {
        id: listView
        x: 0
        y: 0
        width: 110
        height: 160
        model: ListModel {
            id: listModel
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

    function checkDuplicate(data){
        for(var i=0;i<listModelBasket.count;i++)
        {
            if(data == listModelBasket.get(i).name) return 1;
        }
        return 0;
    }
    ListView {
        id: basketListView
        x: 250
        y: 0
        width: 110
        height: 160
        model: ListModel {
            objectName: "listModelBasket"
            id: listModelBasket
            function showBill(x)
            {
                listModelBasket.clear();
                listModelBasket.append({name: x})
                listModel.clear()
            }


        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: rowBasket

                Text {
                    text: name
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea {
                        anchors.fill: parent
                        onClicked: console.log(parent.text)
                    }
                }
                spacing: 10
            }
        }
    }

}
