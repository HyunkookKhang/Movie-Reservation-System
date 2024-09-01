cmake_minimum_required(VERSION 3.16)

project(MovieReservationSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMovieReservationSystem
    main.cpp
)

qt_add_qml_module(appMovieReservationSystem
    URI MovieReservationSystem
    VERSION 1.0
    QML_FILES
        Main.qml
        qml/app/AppHeader.qml
        qml/app/AppContent.qml
        qml/app/AppFooter.qml
        qml/view/MovieSelector.qml
        qml/view/TheaterSelector.qml
        qml/view/SeatSelector.qml
    RESOURCES
        assets.qrc
    SOURCES
        src/controller.h src/controller.cpp
        src/moviemodel.h src/moviemodel.cpp
        src/theatermodel.h src/theatermodel.cpp
        src/moviedata.h src/moviedata.cpp
        src/theaterdata.h src/theaterdata.cpp
        src/seatdata.h src/seatdata.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMovieReservationSystem PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMovieReservationSystem
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMovieReservationSystem
    PRIVATE Qt6::Quick
)

target_include_directories(appMovieReservationSystem
    PRIVATE src
)

include(GNUInstallDirs)
install(TARGETS appMovieReservationSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
