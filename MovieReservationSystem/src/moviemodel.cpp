#include "moviemodel.h"

Movie::Movie(const QString &title, const QString &thumbnailUri)
    : m_title(title), m_thumbnailUri(thumbnailUri)
{
}

QString Movie::title() const
{
    return m_title;
}

QString Movie::thumbnailUri() const
{
    return m_thumbnailUri;
}

MovieModel::MovieModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void MovieModel::addMovie(const Movie &movie)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_movies << movie;
    endInsertRows();
}

int MovieModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_movies.count();
}

QVariant MovieModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_movies.count())
        return QVariant();

    const Movie &movie = m_movies[index.row()];
    if (role == TitleRole)
        return movie.title();
    else if (role == ThumbnailUriRole)
        return movie.thumbnailUri();
    return QVariant();
}

QHash<int, QByteArray> MovieModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ThumbnailUriRole] = "thumbnailUri";
    return roles;
}

