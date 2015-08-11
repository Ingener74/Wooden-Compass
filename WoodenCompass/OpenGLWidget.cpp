/*
 * OpenGLWidget.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#include "OpenGLWidget.h"

#include <QtCore/QTimer>

#include "tools.h"

using namespace std;
using namespace cocos2d;

OpenGLWidget::OpenGLWidget(QWidget* parent) :
        QGLWidget(parent), GLView(), _timer(new QTimer) {
    connect(_timer.get(), &QTimer::timeout, this, &OpenGLWidget::onTimer);
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::swapBuffers() {
    QGLWidget::swapBuffers();
}

void OpenGLWidget::onTimer() {
    update();
}

void OpenGLWidget::initializeGL() {
    QGLWidget::initializeGL();

    auto result = glewInit();
    if (result != GLEW_OK) {
        throw runtime_error("error");
    }

    setFrameSize(width(), height());

    emit ready();

    _timer->start(1000.f / 60.f);
}

void OpenGLWidget::resizeGL(int w, int h) {
    setFrameSize(w, h);
    updateGL();
}

void OpenGLWidget::paintGL() {
    CCDirector::getInstance()->getInstance()->mainLoop();
    pollEvents();
}
