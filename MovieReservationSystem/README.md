# Movie Reservation System 

## Overview

- Target Platform: Windows
- Qt: Qt for Python 6.5.x, QML
- QtCreator: QtCreator 13.x.x


## Prerequisites
- Install Qt 6.5.x from Qt Maintenance Tool
- Install QtCreator 13.x.x from Qt Maintenance Tool


## Build
- Open "MovieReservationSystem" project from QtCreator
- Run the project


## Usages
- Page#1: Select a movie from the list (List can be dragged left-right)
- Page#2: Select a theater from the list (List can be dragged up-down)
- Page#3: Select one or more seats from the page by clicking the icon in the middle
  (black-white icon: availble, colorful icon: reserved) 
- Verification popup will be displayed by clicking "Reserve" button
- Reservation will be competed by clicking "Okay" on the Popup, and app shows initial page
- Can go to the previous page by clicking "Back" button
- In header, current page, selected movie and theater information will be displayed
- In footer, current time will be displayed


## Limitations
- Single user usages only
- Reservation data will not be saved; restarting the app will reset everything
