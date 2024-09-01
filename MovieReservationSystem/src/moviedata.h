#ifndef MOVIEDATA_H
#define MOVIEDATA_H

#include <QObject>
#include <QQmlEngine>

#include "moviemodel.h"

class MovieData : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit MovieData(QObject *parent = nullptr);

    Q_INVOKABLE MovieModel *getMovieModel() const;

signals:
};

#endif // MOVIEDATA_H
