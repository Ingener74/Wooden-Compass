cmake_minimum_required(VERSION 3.0)

qt5_add_resources(WOODEN_COMPASS_RESOURCES Resources/MainWindow.qrc)

qt5_wrap_ui(WOODEN_COMPASS_UI Resources/MainWindow.ui)

add_executable(WoodenCompass main.cpp MainWindow.cpp ${WOODEN_COMPASS_RESOURCES} ${WOODEN_COMPASS_UI})
target_link_libraries(WoodenCompass Qt5::Widgets Qt5::Core)