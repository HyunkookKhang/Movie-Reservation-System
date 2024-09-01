#ifndef THEATERDATA_H
#define THEATERDATA_H

#include <QObject>
#include <QQmlEngine>

#include "theatermodel.h"

class TheaterData : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit TheaterData(QObject *parent = nullptr);

    Q_INVOKABLE TheaterModel *getTheaterModel() const;

signals:
};

#endif // THEATERDATA_H
