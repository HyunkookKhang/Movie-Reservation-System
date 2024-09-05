import QtQuick
import QtQuick.Controls

import MovieReservationSystem

Pane {
    id: root

    signal theaterSelected(theaterName: string)

    Frame {
        anchors.fill: parent

        ListView {
            width: parent.width
            height: 800

            model: theaterData.getTheaterModel()

            clip: true

            delegate: Item {
                width: root.width
                height: 100

                Rectangle {
                    id: delegateBg
                    anchors.fill: parent
                    border.width: 1
                    radius: 10
                }

                Column {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 10

                    spacing: 5

                    Label {
                        text: model.name
                        font.pixelSize: 20
                        font.bold: true
                    }

                    Label {
                        text: model.address
                        font.pixelSize: 16
                        font.bold: true
                    }
                }

                MouseArea {
                    anchors.fill: parent

                    onPressed: {
                        delegateBg.opacity = 0.7
                    }

                    onReleased: {
                        delegateBg.opacity = 1
                        root.theaterSelected(model.name)
                    }
                }
            }
        }
    }

    TheaterData {
        id: theaterData
    }
}
