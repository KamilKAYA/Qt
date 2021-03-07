import QtQuick 2.4
import QtQuick.Window 2.4

Window {
    id: window
    width: 1920
    height: 1080
    visible: true
    property alias benimTopumY: benimTopum.y
    property alias benimTopumX: benimTopum.x
    title: qsTr("Hello World")

    MouseArea{
        id: mouseArea;
        anchors.fill: parent;
        onContainsMouseChanged:{
            benimTopum.x=mouseX;
            benimTopum.y=mouseY;
        }
    }



    Rectangle {
        id: benimTopum
        x: 53
        y: 28
        width: 200
        height: 200
        color: "#b40303"
        radius: 100

    }
}
