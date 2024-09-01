#include "moviedata.h"

#include "controller.h"

MovieData::MovieData(QObject *parent)
    : QObject{parent}
{}

MovieModel *MovieData::getMovieModel() const
{
    return Controller::instance()->getMovieModel();
}
