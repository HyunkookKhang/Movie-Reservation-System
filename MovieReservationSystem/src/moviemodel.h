#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QAbstractListModel>
#include <QStringList>


/**
 * @class Movie
 * @brief Represents a movie with a title and a thumbnail URI.
 *
 * This class stores information about a movie, including its title and thumbnail URI.
 */
class Movie
{
public:
    Movie(const QString &title, const QString &thumbnailUri);

    QString title() const;
    QString thumbnailUri() const;

private:
    QString m_title;
    QString m_thumbnailUri;
};


/**
 * @class MovieModel
 * @brief A model for managing a list of movies.
 *
 * This class provides a model for use with views in Qt, allowing the display and interaction
 * with a list of movies. It extends QAbstractListModel to integrate with Qt's model/view architecture.
 */
class MovieModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MovieRoles {
        TitleRole = Qt::UserRole + 1,
        ThumbnailUriRole
    };

    MovieModel(QObject *parent = nullptr);

    void addMovie(const Movie &movie);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Movie> m_movies;
};

#endif // MOVIEMODEL_H
