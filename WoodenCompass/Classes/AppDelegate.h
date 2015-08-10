#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

#include <QtWidgets/qapplication.h>

class MainWindow;

class AppDelegate: public QApplication, public cocos2d::Application {
public:
    AppDelegate(int argc, char* argv[]);
    virtual ~AppDelegate();

    virtual int exec();

    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();

    MainWindow* getMainWindow();

private:
    std::unique_ptr<MainWindow> _mainWindow;
};

#endif // _APP_DELEGATE_H_

