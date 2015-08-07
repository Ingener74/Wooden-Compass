/*
 * OpenGLWidget.h
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#ifndef WOODENCOMPASS_OPENGLWIDGET_H_
#define WOODENCOMPASS_OPENGLWIDGET_H_

#include <cocos2d.h>
#include <QtOpenGL/qgl.h>

class OpenGLWidget: public QGLWidget, public cocos2d::GLView {
Q_OBJECT
public:
    static const int OPENGL_WIDTH = 800;
    static const int OPENGL_HEIGHT = 600;

    OpenGLWidget(QWidget* parent = nullptr);
    virtual ~OpenGLWidget();

    virtual void end();
    virtual bool isOpenGLReady();
    virtual void swapBuffers();
    virtual void setIMEKeyboardState(bool open);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
};

#endif /* WOODENCOMPASS_OPENGLWIDGET_H_ */
