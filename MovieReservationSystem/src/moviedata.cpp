#include "moviedata.h"

#include "controller.h"

/**
 * @brief Constructs a MovieData object.
 * @param parent The parent QObject, or nullptr if no parent.
 *
 * This constructor initializes the `MovieData` class, which is exposed to QML.
 */
MovieData::MovieData(QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
}


/**
 * @brief Retrieves the MovieModel instance.
 * @return A pointer to the MovieModel instance managed by the Controller.
 *
 * This method provides access to the `MovieModel` through the `Controller` instance.
 * It allows QML components to interact with the `MovieModel` data.
 *
 * @details
 * The `MovieData` class is intended for use within QML to access movie-related data.
 * For example, a QML ListView can use this method to set its model to the `MovieModel`
 * instance returned by the `Controller`.
 *
 * Example QML usage:
 * @code
 * MovieData {
 *     id: movieData
 * }
 *
 * ListView {
 *     model: movieData.getMovieModel()
 *     // Other ListView properties and delegates
 * }
 * @endcode
 */

MovieModel *MovieData::getMovieModel() const
{
    return Controller::instance()->getMovieModel();
}
