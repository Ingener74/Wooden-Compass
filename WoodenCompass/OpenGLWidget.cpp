/*
 * OpenGLWidget.cpp
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent) :
        QGLWidget(parent) {
    setMinimumWidth(OPENGL_WIDTH);
    setMinimumHeight(OPENGL_HEIGHT);
}

OpenGLWidget::~OpenGLWidget() {
}

void OpenGLWidget::initializeGL() {
    resize(OPENGL_WIDTH, OPENGL_HEIGHT);
}

void OpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void OpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.1f, .3f, .1f, 1.f);
}
