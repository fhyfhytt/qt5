cmake_minimum_required(VERSION 3.10)
project(qt5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#boost库所在的根目录
set(BOOST_ROOT D:/c++/boost/boost_1_73_0/boost_1_73_0)
find_package(BOOST 1.73.0 COMPONENTS thread)
if (Boost_FOUND)
    message(Boost_INCLUDE_DIRS " ${Boost_INCLUDE_DIRS}")
    message(Boost_LIBRARY_DIRS " ${Boost_LIBRARY_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif ()
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
add_executable(${PROJECT_NAME} main.cpp MyMainWindow.h MyMainWindow.cpp MyView.h MyView.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
