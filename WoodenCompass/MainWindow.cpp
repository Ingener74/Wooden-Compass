/*
 * MainWindow.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#include <QtWidgets/QPushButton>

#include "tools.h"
#include "OpenGLWidget.h"

#include "MainWindow.h"

MainWindow::MainWindow(QApplication* app, QWidget* parent, Qt::WindowFlags flags) :
    QWidget(parent, flags), _app(app), _ui(new Ui_MainWindow) {
    _ui->setupUi(this);

    _glWidget = make_unique<OpenGLWidget>(this);
    _ui->verticalLayout->insertWidget(1, _glWidget.get());

    QObject::connect(_ui->goButton, &QPushButton::clicked, _app, &QApplication::quit);
}

MainWindow::~MainWindow() {
}

OpenGLWidget* MainWindow::getGlWidget() {
    return _glWidget.get();
}
