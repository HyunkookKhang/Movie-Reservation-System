#ifndef SEATDATA_H
#define SEATDATA_H

#include <QObject>
#include <QQmlEngine>


/**
 * @class SeatData
 * @brief Manages seat status and synchronization for movies and theaters.
 *
 * This class provides methods to retrieve and update the status of seats for a given movie
 * and theater. It is designed to be used in conjunction with QML to interact with seat data.
 */
class SeatData : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit SeatData(QObject *parent = nullptr);

    Q_INVOKABLE QList<bool> getSeatsStatus(QString movieTitle, QString theaterName);
    Q_INVOKABLE void syncSeats(QString movieTitle, QString theaterName, QList<bool> seats);

signals:
};

#endif // SEATDATA_H
