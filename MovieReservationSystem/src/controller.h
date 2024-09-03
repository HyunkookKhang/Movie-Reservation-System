#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QHash>

#include "moviemodel.h"
#include "theatermodel.h"


/**
 * @class Controller
 * @brief Manages application-wide tasks and data access.
 *
 * The `Controller` class is responsible for handling various tasks such as database operations,
 * socket communication, and providing access to models for movies, theaters, and seat status.
 * It serves as a central point of interaction for managing and synchronizing movie and theater data
 * within the application.
 *
 * @details
 * This class provides methods to access the `MovieModel`, `TheaterModel`, and manage seat
 * status through the `getSeatsStatus` and `syncSeats` methods. It maintains a mapping of seat
 * statuses using a `QHash` to facilitate efficient retrieval and updates.
 */
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    static Controller* instance();

    MovieModel *getMovieModel() const;
    TheaterModel *getTheaterModel() const;
    QList<bool> getSeatsStatus(QString movieTitle, QString theaterName);
    void syncSeats(QString movieTitle, QString theaterName, QList<bool> seats);

signals:

private:
    void init();

    MovieModel *m_movieModel;
    TheaterModel *m_theaterModel;
    QHash<QString, QHash<QString, QList<bool>>> m_seatMap;
};

#endif // CONTROLLER_H
