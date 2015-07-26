#include <iostream>
#include <stdexcept>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>

#include "tools.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app { argc, argv };
    try {
        auto mainWindow = make_unique<MainWindow>(&app);
        mainWindow->show();
        return app.exec();
    } catch (exception const& e) {
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}
