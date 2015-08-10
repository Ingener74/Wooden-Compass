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
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::initializeGL() {
    QGLWidget::initializeGL();

    auto result = glewInit();
    if (result != GLEW_OK) {
        throw runtime_error("error");
    }

    emit ready();
}

void OpenGLWidget::resizeGL(int w, int h) {
//    QGLWidget::resize(w, h);



    updateGL();
}

const Size& OpenGLWidget::getFrameSize() const {
    return Size(width(), height());
}

void OpenGLWidget::setFrameSize(float width, float height) {
    resize(width, height);
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
