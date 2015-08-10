/*
 * OpenGLWidget.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#include "OpenGLWidget.h"

using namespace std;
using namespace cocos2d;

OpenGLWidget::OpenGLWidget(QWidget* parent) :
        QGLWidget(parent), GLView() {

//    _timer = make_unique<QTimer>();
//    connect(_timer.get())
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::initializeGL() {
    QGLWidget::initializeGL();

    auto result = glewInit();
    if (result != GLEW_OK) {
        throw runtime_error("error");
    }

    setFrameSize(width(), height());

    emit ready();
}

void OpenGLWidget::resizeGL(int w, int h) {
//    glViewport(0, 0, w, h);
    setFrameSize(w, h);
    updateGL();
}

void OpenGLWidget::paintGL() {
    CCDirector::getInstance()->getInstance()->mainLoop();
    pollEvents();
}

void OpenGLWidget::end() {
}

bool OpenGLWidget::isOpenGLReady() {
    return true;
}

void OpenGLWidget::swapBuffers() {
    QGLWidget::swapBuffers();
}

void OpenGLWidget::setIMEKeyboardState(bool open) {
}
