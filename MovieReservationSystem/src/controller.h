#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QHash>

#include "moviemodel.h"
#include "theatermodel.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    static Controller* instance();

    void init();

    MovieModel *getMovieModel() const;
    TheaterModel *getTheaterModel() const;
    QList<bool> getSeatsStatus(QString movieTitle, QString theaterName);
    void syncSeats(QString movieTitle, QString theaterName, QList<bool> seats);

signals:

private:
    MovieModel *m_movieModel;
    TheaterModel *m_theaterModel;
    QHash<QString, QHash<QString, QList<bool>>> m_seatMap;
};

#endif // CONTROLLER_H
