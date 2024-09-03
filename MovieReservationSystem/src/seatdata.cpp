#include "seatdata.h"

#include "controller.h"


/**
 * @brief Constructs a SeatData object.
 * @param parent The parent QObject, or nullptr if no parent.
 *
 * This constructor initializes the `SeatData` class, which is exposed to QML.
 */
SeatData::SeatData(QObject *parent)
    : QObject{parent}
{
    Q_UNUSED(parent);
}


/**
 * @brief Retrieves the list of seat statuses for a given movie and theater.
 * @param movieTitle The title of the movie for which seat statuses are requested.
 * @param theaterName The name of the theater where the movie is showing.
 * @return A QList<bool> containing the seat statuses. Each element in the list represents a seat, where `true` indicates an occupied seat and `false` indicates an available seat.
 *
 * @details
 * This method retrieves the current status of seats for a specified movie and theater from the `Controller` instance.
 * It is used to obtain the seat availability for a particular movie showing at a particular theater.
 *
 * Example QML usage:
 * @code
 * SeatData {
 *     id: seatData
 * }
 *
 * function foo() {
 *     let seats = seatData.getSeatsStatus("Alien: Romulus", "Crescent Moon Theater");
 *     for (let i = 0; i < seats.length; i++) {
 *         console.log(seats[i]);
 *     }
 * }
 * @endcode
 */
QList<bool> SeatData::getSeatsStatus(QString movieTitle, QString theaterName)
{
    return Controller::instance()->getSeatsStatus(movieTitle, theaterName);
}


/**
 * @brief Syncs the updated seat statuses for a given movie and theater.
 * @param movieTitle The title of the movie for which seat statuses are updated.
 * @param theaterName The name of the theater where the movie is showing.
 * @param seats A QList<bool> containing the updated seat statuses. Each element in the list represents a seat, where `true` indicates an occupied seat and `false` indicates an available seat.
 *
 * @details
 * This method updates the seat statuses for a specific movie and theater in the `Controller` instance.
 * It is used to synchronize the seat availability information with the `Controller`.
 *
 * Example QML usage:
 * @code
 * SeatData {
 *     id: seatData
 * }
 *
 * function bar() {
 *     let seats = [];
 *     for (let i = 0; i < 20; i++) {
 *         seats.push(false);
 *     }
 *     seats[2] = true;
 *     seatData.syncSeats("Alien: Romulus", "Crescent Moon Theater", seats);
 * }
 * @endcode
 */
void SeatData::syncSeats(QString movieTitle, QString theaterName, QList<bool> seats)
{
    Controller::instance()->syncSeats(movieTitle, theaterName, seats);
}
