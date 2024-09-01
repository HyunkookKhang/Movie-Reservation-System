#include "seatdata.h"

#include "controller.h"

SeatData::SeatData(QObject *parent)
    : QObject{parent}
{}

QList<bool> SeatData::getSeatsStatus(QString movieTitle, QString theaterName)
{
    return Controller::instance()->getSeatsStatus(movieTitle, theaterName);
}

void SeatData::setSeat(QString movieTitle, QString theaterName, int seatNumber, bool occupied)
{
    Controller::instance()->setSeat(movieTitle, theaterName, seatNumber, occupied);
}
