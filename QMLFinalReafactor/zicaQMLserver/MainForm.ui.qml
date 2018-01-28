import QtQuick 2.6
import QtQuick.Controls 2.2

Rectangle {
    property alias mouseArea: mouseArea
  //  property alias buttonInsert: buttonInsert
  //  property alias buttonInsertFood: buttonInsertFood
    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent


    }

}
