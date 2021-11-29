cmake_minimum_required(VERSION 2.8)

project(PCHEFitting)


add_subdirectory(dlib dlib_build)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# find_package(Qt5Widgets CONFIG
#    PATHS C:/Qt/5.8/mingw53_32/lib/cmake/Qt5Widgets
#    NO_DEFAULT_PATH)
find_package(Qt5PrintSupport)
find_package(Qt5Script)
find_package(Qt5 COMPONENTS Widgets REQUIRED)


list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core Qt5::PrintSupport Qt5::Script dlib::dlib)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.ui
                          aboutdialog.cpp aboutdialog.ui
                          addcorrelation.cpp addcorrelation.ui
                          addnewfluidwindow.cpp addnewfluidwindow.ui
                          correlation.cpp
                          pcheconfig.cpp pcheconfig.ui
                          ctkrangeslider.cpp
                          qcustomplot.cpp
                          images.qrc data.qrc)


qt5_wrap_ui(SOURCES_FILES mainwindow.ui)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
    Qt5::PrintSupport
    Qt5::Script
    dlib::dlib)
