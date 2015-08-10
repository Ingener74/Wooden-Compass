cmake_minimum_required(VERSION 3.0)

qt5_add_resources(WOODEN_COMPASS_RESOURCES Resources/MainWindow.qrc)

qt5_wrap_ui(WOODEN_COMPASS_UI Resources/MainWindow.ui)

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
    ${OPENGL_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    cocos2d
)
