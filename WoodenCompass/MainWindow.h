/*
 * MainWindow.h
 *
 *  Created on: Jul 26, 2015
 *      Author: pavel
 */

#ifndef WOODENCOMPASS_MAINWINDOW_H_
#define WOODENCOMPASS_MAINWINDOW_H_

#include <memory>

#include "ui_MainWindow.h"

class QApplication;

class MainWindow: public QWidget {
Q_OBJECT
public:
    MainWindow(QApplication*, QWidget* parent = nullptr, Qt::WindowFlags = 0);
    virtual ~MainWindow();

private:
    QApplication* _app = nullptr;
    std::unique_ptr<Ui_MainWindow> _ui;
};

#endif /* WOODENCOMPASS_MAINWINDOW_H_ */
