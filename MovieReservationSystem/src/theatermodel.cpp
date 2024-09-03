#include "theatermodel.h"


/**
 * @brief Constructs a Theater object.
 * @param name The name of the theater.
 * @param address The address of the theater.
 */
Theater::Theater(const QString &name, const QString &address)
    : m_name(name), m_address(address)
{
}


/**
 * @brief Gets the name of the theater.
 * @return The name of the theater as a QString.
 */
QString Theater::name() const
{
    return m_name;
}


/**
 * @brief Gets the address of the theater.
 * @return The address of the theater as a QString.
 */
QString Theater::address() const
{
    return m_address;
}


/**
 * @brief Constructs a TheaterModel object.
 * @param parent The parent QObject, or nullptr if no parent.
 */
TheaterModel::TheaterModel(QObject *parent)
    : QAbstractListModel(parent)
{
    Q_UNUSED(parent);
}


/**
 * @brief Adds a theater to the model.
 * @param theater The theater to add to the model.
 *
 * This method begins a row insertion operation, adds the theater to the internal list,
 * and then ends the row insertion operation to notify views of the change.
 */
void TheaterModel::addTheater(const Theater &movie)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_theaters << movie;
    endInsertRows();
}


/**
 * @brief Gets the number of rows in the model.
 * @param parent The parent index (default is an invalid index).
 * @return The number of rows in the model as an integer.
 *
 * This method returns the total number of theaters in the model, ignoring the parent index.
 */
int TheaterModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_theaters.count();
}


/**
 * @brief Provides data for a specific index and role.
 * @param index The index for which data is requested.
 * @param role The role of the data requested (default is Qt::DisplayRole).
 * @return The data for the specified index and role as a QVariant.
 *
 * This method returns the data associated with the given index and role. It retrieves
 * the theater's name or address based on the requested role.
 */
QVariant TheaterModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_theaters.count())
        return QVariant();

    const Theater &theater = m_theaters[index.row()];
    if (role == NameRole)
        return theater.name();
    else if (role == AddressRole)
        return theater.address();
    return QVariant();
}


/**
 * @brief Provides role names for the model.
 * @return A hash mapping roles to their names as QByteArray.
 *
 * This method returns a hash that maps custom roles (e.g., NameRole, AddressRole)
 * to their string names, allowing views to access the data associated with these roles.
 */
QHash<int, QByteArray> TheaterModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AddressRole] = "address";
    return roles;
}

