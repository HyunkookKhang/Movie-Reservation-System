#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QQmlEngine>

#include "moviemodel.h"
#include "theatermodel.h"

class DataReader : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit DataReader(QObject *parent = nullptr);

    Q_INVOKABLE MovieModel *getMovieModel() const;
    Q_INVOKABLE TheaterModel *getTheaterModel() const;
    Q_INVOKABLE QList<bool> getSeatsStatus(QString movieTitle, QString theaterName);
    Q_INVOKABLE void setSeat(QString movieTitle, QString theaterName, int seatNumber, bool occupied);

signals:
};

#endif // DATAREADER_H
