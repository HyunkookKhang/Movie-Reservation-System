import QtQuick
import QtQuick.Controls

import "../view"
// import MovieReservationSystem

Item {
    id: root

    property string currentPage
    property string selectedMovieTitle
    property string selectedTheaterName
    property int currentPageDepth: stack.depth

    Pane {
        anchors.fill: parent
    }

    StackView {
        id: stack

        initialItem: movieSelector
        anchors.fill: parent
    }

    Button {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10

        width: 100
        height: 50

        visible: (stack.depth > 1) ? true : false

        text: "< Back"
        font.bold: true
        font.pixelSize: 15

        onClicked: {
            stack.pop()
        }
    }

    MovieSelector {
        id: movieSelector

        onMovieSelected: (movieTitle) => {
            selectedMovieTitle = movieTitle

            stack.push(theaterSelector)
        }
    }

    TheaterSelector {
        id: theaterSelector

        onTheaterSelected: (theaterName) => {
            selectedTheaterName = theaterName

            seatSelector.movieTitle = selectedMovieTitle
            seatSelector.theaterName = selectedTheaterName
            stack.push(seatSelector)
        }
    }

    SeatSelector {
        id: seatSelector

        onMovieReserved: {
            stack.clear()
            stack.push(movieSelector)
        }
    }
}
