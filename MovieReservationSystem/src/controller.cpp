#include "controller.h"


/**
 * @brief Constructs a Controller object.
 * @param parent The parent QObject, or nullptr if no parent.
 *
 * This constructor initializes the `Controller` class by calling the `init` method,
 * which sets up the Movie and Theater models and initializes seat data.
 */
Controller::Controller(QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
    init();
}


/**
 * @brief Retrieves the singleton instance of the Controller class.
 * @return A pointer to the singleton instance of the Controller class.
 *
 * This static method provides access to the single instance of the Controller,
 * implementing the Singleton pattern.
 */
Controller* Controller::instance()
{
    static Controller instance;
    return &instance;
}


/**
 * @brief Initializes Movie and Theater models and seat data.
 *
 * This private method sets up the Movie and Theater models with predefined data and
 * initializes the seat status for each movie and theater combination. Each movie is
 * associated with each theater, and a default seat status list (20 seats, all false) is created.
 */
void Controller::init()
{
    m_movieModel = new MovieModel;
    m_movieModel->addMovie(Movie("Alien: Romulus", "qrc:/assets/images/thumbnails/Alien.jpg"));
    m_movieModel->addMovie(Movie("Blink Twice", "qrc:/assets/images/thumbnails/Blink_Twice.jpg"));
    m_movieModel->addMovie(Movie("Deadpool & Wolverine", "qrc:/assets/images/thumbnails/Deadpool.jpg"));
    m_movieModel->addMovie(Movie("It ends with us", "qrc:/assets/images/thumbnails/It_ends_with_us.jpg"));
    m_movieModel->addMovie(Movie("The Forge", "qrc:/assets/images/thumbnails/The_Forge.jpg"));

    m_theaterModel = new TheaterModel;
    m_theaterModel->addTheater(Theater("Crescent Moon Theater", "123 Starry Lane, New York, NY 10001"));
    m_theaterModel->addTheater(Theater("Sunset Boulevard Playhouse", "456 Sunset Blvd, Los Angeles, CA 90028"));
    m_theaterModel->addTheater(Theater("Riverbend Arts Center", "789 Riverside Dr, Chicago, IL 60611"));
    m_theaterModel->addTheater(Theater("Blue Horizon Theater", "101 Ocean View Ave, Miami, FL 33139"));
    m_theaterModel->addTheater(Theater("Golden Gate Stage", "234 Bay Street, San Francisco, CA 94133"));
    m_theaterModel->addTheater(Theater("The Grand Auditorium", "567 Elm Street, Boston, MA 02108"));

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


/**
 * @brief Retrieves the MovieModel instance.
 * @return A pointer to the MovieModel instance.
 *
 * This method provides access to the `MovieModel` instance managed by the `Controller`.
 * The `MovieModel` contains a list of movies along with their thumbnail images.
 *
 * @details
 * The MovieModel is initialized with the following movies:
 * 1. Alien: Romulus
 * 2. Blink Twice
 * 3. Deadpool & Wolverine
 * 4. It Ends with Us
 * 5. The Forge
 *
 * Thumbnail images are needed to display.
 */
MovieModel *Controller::getMovieModel() const
{
    return m_movieModel;
}


/**
 * @brief Retrieves the TheaterModel instance.
 * @return A pointer to the TheaterModel instance.
 *
 * This method provides access to the `TheaterModel` instance managed by the `Controller`.
 * The `TheaterModel` contains a list of theaters with their names and addresses.
 *
 * @details
 * The TheaterModel is initialized with the following theaters:
 * 1. Crescent Moon Theater - 123 Starry Lane, New York, NY 10001
 * 2. Sunset Boulevard Playhouse - 456 Sunset Blvd, Los Angeles, CA 90028
 * 3. Riverbend Arts Center - 789 Riverside Dr, Chicago, IL 60611
 * 4. Blue Horizon Theater - 101 Ocean View Ave, Miami, FL 33139
 * 5. Golden Gate Stage - 234 Bay Street, San Francisco, CA 94133
 * 6. The Grand Auditorium - 567 Elm Street, Boston, MA 02108
 */
TheaterModel *Controller::getTheaterModel() const
{
    return m_theaterModel;
}


/**
 * @brief Retrieves the seat status for a specific movie and theater.
 * @param movieTitle The title of the movie.
 * @param theaterName The name of the theater.
 * @return A QList<bool> representing the seat status.
 *
 * This method returns the status of seats for a given movie and theater. Each item in
 * the list indicates whether a seat is occupied (true) or available (false).
 *
 * Example usage:
 * @code
 * QList<bool> seats = Controller::instance()->getSeatsStatus("Alien: Romulus", "Crescent Moon Theater");
 * @endcode
 */
QList<bool> Controller::getSeatsStatus(QString movieTitle, QString theaterName)
{
    return m_seatMap[movieTitle][theaterName];
}


/**
 * @brief Updates the seat status for a specific movie and theater.
 * @param movieTitle The title of the movie.
 * @param theaterName The name of the theater.
 * @param seats A QList<bool> containing the updated seat status.
 *
 * This method updates the seat status for a given movie and theater. The provided list
 * represents the new seat status where each item indicates whether a seat is occupied
 * (true) or available (false).
 *
 * Example usage:
 * @code
 * QList<bool> seats(20, false);
 * seats[2] = true;
 * seats[3] = true;
 * Controller::instance()->syncSeats(movieTitle, theaterName, seats);
 * @endcode
 */
void Controller::syncSeats(QString movieTitle, QString theaterName, QList<bool> seats)
{
    m_seatMap[movieTitle][theaterName] = seats;
}
