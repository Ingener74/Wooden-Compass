cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core    REQUIRED)
find_package(Qt5OpenGL  REQUIRED)
find_package(OpenGL     REQUIRED)
find_package(Gettext    REQUIRED)

include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5OpenGL_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
)

add_definitions(
    -std=c++11 -fPIC
)

add_subdirectory(WoodenCompass)
