import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Pane {
    id: root

    implicitWidth: 1920
    implicitHeight: 100

    property string appTitle: "Movie Reservation System"

    property int stackIndex
    property string movieTitle
    property string theaterName

    Column {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20

        spacing: 5

        Label {
            text: root.appTitle
            font.pixelSize: 36
            font.bold: true
        }

        Row {
            spacing: 20

            Label {
                id: currentPageText

                width: 250

                font.pixelSize: 28
                font.bold: true
            }

            Label {
                id: reservationSummaryText

                font.pixelSize: 28
            }
        }
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
