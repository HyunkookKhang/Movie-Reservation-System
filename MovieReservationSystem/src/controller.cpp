#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    init();
}

Controller* Controller::instance()
{
    static Controller instance;
    return &instance;
}

void Controller::init()
{
    m_movieModel = new MovieModel;
    m_movieModel->addMovie(Movie("Alien: Romulus", "qrc:/assets/images/thumbnails/Alien.jpg"));
    m_movieModel->addMovie(Movie("Blink Twice", "qrc:/assets/images/thumbnails/Blink_Twice.jpg"));
    m_movieModel->addMovie(Movie("Deadpool & Wolverine", "qrc:/assets/images/thumbnails/Deadpool.jpg"));
    m_movieModel->addMovie(Movie("It ends with us", "qrc:/assets/images/thumbnails/It_ends_with_us.jpg"));
    m_movieModel->addMovie(Movie("The Forge", "qrc:/assets/images/thumbnails/The_Forge.jpg"));

    m_theaterModel = new TheaterModel;
    m_theaterModel->addTheater(Theater("Movie Theater 1", "Theater 1 address"));
    m_theaterModel->addTheater(Theater("Movie Theater 2", "Theater 2 address"));
    m_theaterModel->addTheater(Theater("Movie Theater 3", "Theater 3 address"));
    m_theaterModel->addTheater(Theater("Movie Theater 4", "Theater 4 address"));
    m_theaterModel->addTheater(Theater("Movie Theater 5", "Theater 5 address"));
    m_theaterModel->addTheater(Theater("Movie Theater 6", "Theater 6 address"));

    for (int i = 0; i < m_movieModel->rowCount(); i++) {
        QModelIndex movieIndex = m_movieModel->index(i, 0);

        for (int j = 0; j < m_theaterModel->rowCount(); j++) {
            QModelIndex theaterIndex = m_theaterModel->index(j, 0);

            QString movieTitle = m_movieModel->data(movieIndex, MovieModel::TitleRole).toString();
            QString theaterName = m_theaterModel->data(theaterIndex, TheaterModel::NameRole).toString();

            QList<bool> seatList(20, false);
            m_seatMap[movieTitle][theaterName] = seatList;
        }
    }
}

MovieModel *Controller::getMovieModel() const
{
    return m_movieModel;
}

TheaterModel *Controller::getTheaterModel() const
{
    return m_theaterModel;
}

QList<bool> Controller::getSeatsStatus(QString movieTitle, QString theaterName)
{
    return m_seatMap[movieTitle][theaterName];
}

void Controller::setSeat(QString movieTitle, QString theaterName, int seatNumber, bool occupied)
{
    m_seatMap[movieTitle][theaterName][seatNumber] = occupied;
}
