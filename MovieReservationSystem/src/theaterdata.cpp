#include "theaterdata.h"

#include "controller.h"

TheaterData::TheaterData(QObject *parent)
    : QObject{parent}
{}

TheaterModel *TheaterData::getTheaterModel() const
{
    return Controller::instance()->getTheaterModel();
}
