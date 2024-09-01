import QtQuick
import QtQuick.Controls

Popup {
    id: root

    implicitWidth: 450
    implicitHeight: 300

    property string movieTitle
    property string theaterName
    property string reservedSeats

    modal: true
    focus: true
    closePolicy: Popup.NoAutoClose

    signal movieReserved()

    Overlay.modal: Rectangle {
        color: "#2f4f4fe7"
    }

    Column {
        anchors.fill: parent

        topPadding: 20
        spacing: 10

        Label {
            anchors.horizontalCenter: parent.horizontalCenter

            height: 40
            text: "Reservation Summary"
            font.pixelSize: 25
            font.bold: true
        }

        SummaryItem {
            desc: "Title"
            value: movieTitle
        }

        SummaryItem {
            desc: "Theater"
            value: theaterName
        }

        SummaryItem {
            desc: "Seats"
            value: reservedSeats
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            height: 60

            topPadding: 15
            spacing: 30

            Button {
                width: 160
                height: 60

                text: "Okay"
                font.pixelSize: 20
                font.bold: true

                onClicked: {
                    root.close()
                    root.movieReserved()
                }
            }

            Button {
                width: 160
                height: 60

                text: "Cancel"
                font.pixelSize: 20
                font.bold: true

                onClicked: {
                    root.close()
                }
            }
        }
    }

    component SummaryItem: Item {
        width: 400
        height: 30

        property string desc
        property string value

        Row {
            anchors.left: parent.left
            anchors.leftMargin: 40
            spacing: 10

            Label {
                width: 100

                text: desc + ":"
                font.pixelSize: 25
            }

            Label {
                width: 250

                text: value
                font.pixelSize: 25
                font.bold: true
                elide: Text.ElideRight
            }
        }
    }
}


