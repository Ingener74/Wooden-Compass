#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;

Scene* HelloWorld::scene() {
    auto scene = Scene::create();

    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init() {
    if (!Layer::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto pahan = LabelTTF::create("Pavel", "Arial", 12);
    this->addChild(pahan);

    auto label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);

    // position the label on the center of the screen
    label->setPosition(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height);

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize / 2) + origin);

    // add the sprite as a child to this layer
    this->addChild(sprite);

    return true;
}

void HelloWorld::menuCloseCallback(Ref* sender) {
    Director::getInstance()->end();
}
