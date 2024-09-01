#ifndef SEATDATA_H
#define SEATDATA_H

#include <QObject>
#include <QQmlEngine>

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
