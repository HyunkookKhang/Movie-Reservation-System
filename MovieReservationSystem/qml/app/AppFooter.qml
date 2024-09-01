import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root

    implicitWidth: 1920
    implicitHeight: 100

    property string appTitle: "Movie Reservation System"

    color: "#353638"

    Text {
        id: ltTimer
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 10

        color: "#FFFFFF"
        font.pixelSize: 20
    }

    QtObject {
        id: inner

        function updateClock() {
            ltTimer.text = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss")
        }
    }

    Timer {
        repeat: true
        running: true
        interval: 1000
        onTriggered: inner.updateClock()
    }

    Component.onCompleted: {
        inner.updateClock()
    }
}
