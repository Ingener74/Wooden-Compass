cmake_minimum_required(VERSION 3.0)

qt5_add_resources(WOODEN_COMPASS_RESOURCES Resources/MainWindow.qrc)

qt5_wrap_ui(WOODEN_COMPASS_UI Resources/MainWindow.ui)

set(COCOS2D_INCLUDE_DIR "" CACHE STRING "cocos2d-x include dir")

add_definitions(-DLINUX)
include_directories(
    ${COCOS2D_INCLUDE_DIR}/cocos
    ${COCOS2D_INCLUDE_DIR}/external/glfw3/include/mac
)

add_executable(WoodenCompass ${WOODEN_COMPASS_RESOURCES} ${WOODEN_COMPASS_UI} 
    main.cpp 
    MainWindow.cpp
    OpenGLWidget.cpp
    Classes/AppDelegate.cpp
    Classes/HelloWorldScene.cpp
)
target_link_libraries(WoodenCompass 
    Qt5::Widgets 
    Qt5::Core 
    Qt5::OpenGL
    ${COCOS2D_INCLUDE_DIR}/build/lib/libcocos2d.a
    
    ${OPENGL_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    ${GLEW_LIBRARIES}
    ${X11_LIBRARIES}
)
