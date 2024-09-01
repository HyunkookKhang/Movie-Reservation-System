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

    Rectangle {
        anchors.fill: parent
        color: "#353638"
    }

    StackView {
        id: stack

        initialItem: movieSelector
        anchors.fill: parent
    }

    Button {
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        visible: (stack.depth > 1) ? true : false

        text: "<"
        font.bold: true
        font.pixelSize: 20

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
    }
}
