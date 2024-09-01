#ifndef THEATERMODEL_H
#define THEATERMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class Theater
{
public:
    Theater(const QString &name, const QString &address);

    QString name() const;
    QString address() const;

private:
    QString m_name;
    QString m_address;
};

class TheaterModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MovieRoles {
        NameRole = Qt::UserRole + 1,
        AddressRole
    };

    TheaterModel(QObject *parent = nullptr);

    void addTheater(const Theater &movie);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Theater> m_theaters;
};

#endif // THEATERMODEL_H
