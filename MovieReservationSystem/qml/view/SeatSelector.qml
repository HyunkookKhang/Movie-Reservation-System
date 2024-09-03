import QtQuick
import QtQuick.Controls

import MovieReservationSystem

Pane {
    id: root

    property int num_total_seat: 20
    property string movieTitle
    property string theaterName

    visible: false

    signal movieReserved()

    Frame {
        anchors.fill: parent

        Rectangle {
            id: screen

            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            border.width: 2
            border.color: "#dc143c"

            width: 800
            height: 200

            Label {
                anchors.centerIn: parent
                text: "SCREEN"
                font.pixelSize: 40
                font.letterSpacing: 10
            }
        }

        GridView {
            anchors.horizontalCenter: parent.horizontalCenter

            anchors.top: screen.bottom
            anchors.topMargin: 50

            width: 800
            height: 300

            cellWidth: 160
            cellHeight: 100

            model: seatModel

            delegate: Item {
                width: 130
                height: 150

                Column {
                    anchors.fill: parent

                    spacing: 5

                    Image {
                        anchors.horizontalCenter: parent.horizontalCenter

                        source: occupied ? "qrc:/assets/images/icons/seat_occ.png" : "qrc:/assets/images/icons/seat_nor.png"

                        MouseArea {
                            anchors.fill: parent

                            onPressed: {
                                parent.opacity = 0.7
                            }

                            onReleased: {
                                parent.opacity = 1
                                occupied = !occupied
                            }
                        }
                    }

                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter

                        text: getSeatNumber(index)
                        font.pixelSize: 20
                        font.bold: true
                    }
                }
            }
        }

        Button {
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10

            width: 150
            height: 50

            text: "Reserve"
            font.bold: true
            font.pixelSize: 15

            onClicked: {
                summaryPopup.movieTitle = root.movieTitle
                summaryPopup.theaterName = root.theaterName

                let reservedSeats = ""
                for (let i = 0; i < seatModel.count; i++) {
                    if (seatModel.get(i).occupied) {
                        reservedSeats += getSeatNumber(i) + " "
                    }
                }
                summaryPopup.reservedSeats = reservedSeats

                summaryPopup.open()
            }
        }
    }

    SummaryPopup {
        id: summaryPopup

        anchors.centerIn: parent

        width: 450
        height: 300

        onMovieReserved: {
            let seats = convertModelToList(seatModel)
            seatData.syncSeats(movieTitle, theaterName, seats)
            root.movieReserved()
        }

        function convertModelToList(model) {
            let list = []
            for (let i = 0; i < model.count; i++) {
                let item = model.get(i)
                list.push(item.occupied)  // Extract the "value" field
            }
            return list
        }
    }

    function getSeatNumber(index: int) {
        let numberOfSeatsEachLine = 5

        let lineCount = Math.floor((index) / numberOfSeatsEachLine) + 1
        let seatNumber = ((index) % numberOfSeatsEachLine) + 1

        let ret = ""

        switch (lineCount) {
        case 1:
            ret += "A"
            break
        case 2:
            ret += "B"
            break
        case 3:
            ret += "C"
            break
        case 4:
            ret += "D"
            break
        }

        ret += seatNumber

        return ret
    }

    ListModel {
        id: seatModel

        Component.onCompleted: {
            for (let i = 0; i < root.num_total_seat; i++) {
                append({
                           number: i,
                           occupied: false
                       })
            }
        }
    }

    SeatData {
        id: seatData
    }

    onVisibleChanged: {
        if (visible) {
            let seats = seatData.getSeatsStatus(movieTitle, theaterName)
            for (let i = 0; i < seats.length; i++) {
                seatModel.get(i).occupied = seats[i]
            }
        }
    }
}
