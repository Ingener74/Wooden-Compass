/*
 * OpenGLWidget.h
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#ifndef WOODENCOMPASS_OPENGLWIDGET_H_
#define WOODENCOMPASS_OPENGLWIDGET_H_

#include <QtOpenGL/qgl.h>

class OpenGLWidget: public QGLWidget {
Q_OBJECT
public:
    OpenGLWidget(QWidget* parent = nullptr);
    virtual ~OpenGLWidget();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
};

#endif /* WOODENCOMPASS_OPENGLWIDGET_H_ */
