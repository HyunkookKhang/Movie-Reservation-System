import QtQuick
import MovieReservationSystem

Item {
    id: root

    visible: false

    signal movieSelected(movieTitle: string)

    ListView {
        width: parent.width
        height: 800

        model: movieData.getMovieModel()
        orientation: ListView.Horizontal

        delegate: Item {
            width: 400
            height: 800

            Column {
                spacing: 10

                Image {
                    source: model.thumbnailUri

                    MouseArea {
                        anchors.fill: parent

                        onPressed: {
                            parent.opacity = 0.7
                        }

                        onReleased: {
                            parent.opacity = 1
                            root.movieSelected(model.title)
                        }
                    }
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: model.title
                    font.pixelSize: 20
                    font.bold: true
                    color: "#ffffff"
                }
            }
        }
    }

    MovieData {
        id: movieData
    }
}
