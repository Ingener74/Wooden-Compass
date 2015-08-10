#include "AppDelegate.h"

#include <vector>
#include <string>

#include "HelloWorldScene.h"
#include "AppMacros.h"

#include "../tools.h"
#include "../MainWindow.h"
#include "../OpenGLWidget.h"

using namespace std;
using namespace cocos2d;

AppDelegate::AppDelegate(int argc, char* argv[]) :
    QApplication(argc, argv) {

    _mainWindow = make_unique<MainWindow>(this);
}

int AppDelegate::exec() {
    return QApplication::exec();
}

AppDelegate::~AppDelegate() {
}

//void AppDelegate::initGLContextAttrs() {
//    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
//
//    GLView::setGLContextAttrs(glContextAttrs);
//}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = _mainWindow->getGlWidget();

    director->setOpenGLView(glview);

    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height,
        ResolutionPolicy::NO_BORDER);
//
    Size frameSize = glview->getFrameSize();
    vector<string> searchPath;

    if (frameSize.height > mediumResource.size.height) {
        searchPath.push_back(largeResource.directory);

        director->setContentScaleFactor(
            MIN(largeResource.size.height / designResolutionSize.height,
                largeResource.size.width / designResolutionSize.width));
    }
// if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height) {
        searchPath.push_back(mediumResource.directory);

        director->setContentScaleFactor(
            MIN(mediumResource.size.height / designResolutionSize.height,
                mediumResource.size.width / designResolutionSize.width));
    }
// if the frame's height is smaller than the height of medium resource size, select small resource.
    else {
        searchPath.push_back(smallResource.directory);

        director->setContentScaleFactor(
            MIN(smallResource.size.height / designResolutionSize.height,
                smallResource.size.width / designResolutionSize.width));
    }

// set searching path
    FileUtils::getInstance()->setSearchPaths(searchPath);

// turn on display FPS
    director->setDisplayStats(true);

// set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

// create a scene. it's an autorelease object
    auto scene = HelloWorld::scene();

// run
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}

MainWindow* AppDelegate::getMainWindow() {
    return _mainWindow.get();
}
