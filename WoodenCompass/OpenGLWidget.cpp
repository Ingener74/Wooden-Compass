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
    QGLWidget(parent) {
    setMinimumWidth(OPENGL_WIDTH);
    setMinimumHeight(OPENGL_HEIGHT);
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::initializeGL() {
    QGLWidget::initializeGL();
//    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
//    setGLContextAttrs(glContextAttrs);
}

void OpenGLWidget::resizeGL(int w, int h) {
    setFrameSize(w, h);
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
