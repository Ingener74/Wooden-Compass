cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

add_definitions(
    -std=c++11 -fPIC
)

add_definitions(-DLINUX)
add_subdirectory(cocos2d-x)
include_directories(
    cocos2d-x/cocos
    cocos2d-x/external/glfw3/include/mac
)

add_subdirectory(gmock-1.7.0)
enable_testing()
include_directories(
    gmock-1.7.0/include
    gmock-1.7.0/gtest/include
)

include_directories(
    mvc/include
)
add_subdirectory(mvc)

find_package(OpenGL     REQUIRED)
find_package(Gettext    REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core    REQUIRED)
find_package(Qt5OpenGL  REQUIRED)
include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5OpenGL_INCLUDE_DIRS}
    
    ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}
    ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR}
)

add_subdirectory(WoodenCompass)
