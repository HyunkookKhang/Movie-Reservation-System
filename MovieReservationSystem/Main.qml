import QtQuick

import "qml/app"

Window {
    id: root

    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hello World")

    AppHeader {
        id: header

        width: root.width
        height: 100
    }

    AppContent {
        id: content

        anchors.top: header.bottom
        anchors.left: header.left

        width: header.width
        height: root.height - header.height - footer.height

        onSelectedMovieTitleChanged: {
            header.movieTitle = selectedMovieTitle
        }

        onSelectedTheaterNameChanged: {
            header.theaterName = selectedTheaterName
        }

        onCurrentPageDepthChanged: {
            header.stackIndex = currentPageDepth
        }
    }

    AppFooter {
        id: footer

        anchors.top: content.bottom
        anchors.left: header.left

        width: header.width
        height: 50
    }
}
