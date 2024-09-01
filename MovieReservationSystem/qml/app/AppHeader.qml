import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root

    implicitWidth: 1920
    implicitHeight: 100

    color: "#353638"

    property string appTitle: "Movie Reservation System"

    property int stackIndex
    property string movieTitle
    property string theaterName

    Column {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20

        spacing: 5

        Text {
            text: root.appTitle
            color: "#FFFFFF"
            font.pixelSize: 36
            font.bold: true
        }

        Row {
            spacing: 20

            Text {
                id: currentPageText

                width: 250

                color: "#a9a9a9"
                font.pixelSize: 28
                font.bold: true
            }

            Text {
                id: reservationSummaryText

                color: "#a9a9a9"
                font.pixelSize: 28
            }
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom

        width: parent.width
        height: 1
        color: "#ffffff"
    }

    onStackIndexChanged: {
        switch (stackIndex) {
        case 1:
            currentPageText.text = "[Select Movie]"
            reservationSummaryText.text = ""
            break
        case 2:
            currentPageText.text = "[Select Theater]"
            reservationSummaryText.text = movieTitle
            break
        case 3:
            currentPageText.text = "[Select Seats]"
            reservationSummaryText.text = movieTitle + " > " + theaterName
            break
        }
    }
}
