#include <iostream>
#include <stdexcept>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>

#include "Classes/AppDelegate.h"
#include "tools.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char **argv) {
    AppDelegate app { argc, argv };
    try {
        app.getMainWindow()->show();
        return app.exec();
    } catch (exception const& e) {
        QMessageBox::critical(nullptr, "Error", e.what());
    }
}
