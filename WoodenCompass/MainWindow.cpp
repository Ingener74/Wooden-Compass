/*
 * MainWindow.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#include <QtWidgets/QPushButton>

#include "MainWindow.h"

MainWindow::MainWindow(QApplication* app, QWidget* parent, Qt::WindowFlags flags) :
        QWidget(parent, flags), _app(app), _ui(new Ui_MainWindow) {
    _ui->setupUi(this);

    QObject::connect(_ui->goButton, &QPushButton::clicked, _app, &QApplication::quit);
}

MainWindow::~MainWindow() {
}

