cmake_minimum_required(VERSION 3.0)

qt5_add_resources(WOODEN_COMPASS_RESOURCES Resources/MainWindow.qrc)

qt5_wrap_ui(WOODEN_COMPASS_UI Resources/MainWindow.ui)

set(COCOS2D_INCLUDE_DIR "" CACHE STRING "cocos2d-x include dir")

option(TEST1 "" OFF)

add_definitions(-DLINUX)
include_directories(${COCOS2D_INCLUDE_DIR})

add_executable(WoodenCompass ${WOODEN_COMPASS_RESOURCES} ${WOODEN_COMPASS_UI} 
    main.cpp 
    MainWindow.cpp
    OpenGLWidget.cpp
    
    Classes/Application-linux.cpp
)
target_link_libraries(WoodenCompass 
    Qt5::Widgets 
    Qt5::Core 
    Qt5::OpenGL
    ${OPENGL_LIBRARIES}
)