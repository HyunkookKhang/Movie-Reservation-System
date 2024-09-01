#include "theatermodel.h"

Theater::Theater(const QString &name, const QString &address)
    : m_name(name), m_address(address)
{
}

QString Theater::name() const
{
    return m_name;
}

QString Theater::address() const
{
    return m_address;
}

TheaterModel::TheaterModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void TheaterModel::addTheater(const Theater &movie)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_theaters << movie;
    endInsertRows();
}

int TheaterModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_theaters.count();
}

QVariant TheaterModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_theaters.count())
        return QVariant();

    const Theater &theater = m_theaters[index.row()];
    if (role == NameRole)
        return theater.name();
    else if (role == AddressRole)
        return theater.address();
    return QVariant();
}

QHash<int, QByteArray> TheaterModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AddressRole] = "address";
    return roles;
}

