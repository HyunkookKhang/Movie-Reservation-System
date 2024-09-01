#include "seatdata.h"

#include "controller.h"

SeatData::SeatData(QObject *parent)
    : QObject{parent}
{}

QList<bool> SeatData::getSeatsStatus(QString movieTitle, QString theaterName)
{
    return Controller::instance()->getSeatsStatus(movieTitle, theaterName);
}

void SeatData::syncSeats(QString movieTitle, QString theaterName, QList<bool> seats)
{
    Controller::instance()->syncSeats(movieTitle, theaterName, seats);
}
