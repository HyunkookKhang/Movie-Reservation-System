#include "theaterdata.h"

#include "controller.h"

/**
 * @brief Constructs a TheaterData object.
 * @param parent The parent QObject, or nullptr if no parent.
 *
 * This constructor initializes the `TheaterData` class, which is exposed to QML.
 */
TheaterData::TheaterData(QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
}


/**
 * @brief Retrieves the TheaterModel instance.
 * @return A pointer to the TheaterModel instance managed by the Controller.
 *
 * This method provides access to the `TheaterModel` through the `Controller` instance.
 * It allows QML components to interact with the `TheaterModel` data.
 *
 * @details
 * The `TheaterData` class is designed for use within QML to access theater-related data.
 * For example, a QML ListView can use this method to set its model to the `TheaterModel`
 * instance returned by the `Controller`.
 *
 * Example QML usage:
 * @code
 * TheaterData {
 *     id: theaterData
 * }
 *
 * ListView {
 *     model: theaterData.getTheaterModel()
 *     // Other ListView properties and delegates
 * }
 * @endcode
 */
TheaterModel *TheaterData::getTheaterModel() const
{
    return Controller::instance()->getTheaterModel();
}
