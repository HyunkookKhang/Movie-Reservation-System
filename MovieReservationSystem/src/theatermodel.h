#ifndef THEATERMODEL_H
#define THEATERMODEL_H

#include <QAbstractListModel>
#include <QStringList>


/**
 * @class Theater
 * @brief Represents a theater with a name and a address.
 *
 * This class stores information about a theater, including its name and address.
 */
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


/**
 * @class TheaterModel
 * @brief A model for managing a list of theaters.
 *
 * This class provides a model for use with views in Qt, allowing the display and interaction
 * with a list of theaters. It extends QAbstractListModel to integrate with Qt's model/view architecture.
 */
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
