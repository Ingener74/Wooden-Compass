#include <iostream>
#include <stdexcept>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>

#include "MainWindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app { argc, argv };
    try {
        std::unique_ptr<MainWindow> mainWindow(new MainWindow(&app));
        mainWindow->show();
        return app.exec();
    } catch (exception const& e) {
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}
