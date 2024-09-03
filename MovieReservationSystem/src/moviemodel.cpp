#include "moviemodel.h"


/**
 * @brief Constructs a Movie object.
 * @param title The title of the movie.
 * @param thumbnailUri The URI of the movie's thumbnail image.
 */
Movie::Movie(const QString &title, const QString &thumbnailUri)
    : m_title(title), m_thumbnailUri(thumbnailUri)
{
}


/**
 * @brief Gets the title of the movie.
 * @return The title of the movie as a QString.
 */
QString Movie::title() const
{
    return m_title;
}


/**
 * @brief Gets the thumbnail URI of the movie.
 * @return The URI of the movie's thumbnail image as a QString.
 */
QString Movie::thumbnailUri() const
{
    return m_thumbnailUri;
}


/**
 * @brief Constructs a MovieModel object.
 * @param parent The parent QObject, or nullptr if no parent.
 */
MovieModel::MovieModel(QObject *parent)
    : QAbstractListModel(parent)
{
    Q_UNUSED(parent);
}


/**
 * @brief Adds a movie to the model.
 * @param movie The movie to add to the model.
 *
 * This method begins a row insertion operation, adds the movie to the internal list,
 * and then ends the row insertion operation to notify views of the change.
 */
void MovieModel::addMovie(const Movie &movie)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_movies << movie;
    endInsertRows();
}


/**
 * @brief Gets the number of rows in the model.
 * @param parent The parent index (default is an invalid index).
 * @return The number of rows in the model as an integer.
 *
 * This method returns the total number of movies in the model, ignoring the parent index.
 */
int MovieModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_movies.count();
}


/**
 * @brief Provides data for a specific index and role.
 * @param index The index for which data is requested.
 * @param role The role of the data requested (default is Qt::DisplayRole).
 * @return The data for the specified index and role as a QVariant.
 *
 * This method returns the data associated with the given index and role. It retrieves
 * the movie's title or thumbnail URI based on the requested role.
 */
QVariant MovieModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_movies.count())
        return QVariant();

    const Movie &movie = m_movies[index.row()];
    if (role == TitleRole)
        return movie.title();
    else if (role == ThumbnailUriRole)
        return movie.thumbnailUri();
    return QVariant();
}


/**
 * @brief Provides role names for the model.
 * @return A hash mapping roles to their names as QByteArray.
 *
 * This method returns a hash that maps custom roles (e.g., TitleRole, ThumbnailUriRole)
 * to their string names, allowing views to access the data associated with these roles.
 */
QHash<int, QByteArray> MovieModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ThumbnailUriRole] = "thumbnailUri";
    return roles;
}

