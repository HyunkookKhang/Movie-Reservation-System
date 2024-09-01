import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane {
    id: root

    implicitWidth: 1920
    implicitHeight: 100

    Label {
        id: ltTimer
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 10

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
