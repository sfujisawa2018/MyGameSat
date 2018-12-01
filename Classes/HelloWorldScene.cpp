/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
// 初期化（一度しかやらないこと）
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ここにコードを書く
	Sprite* spr = Sprite::create("mario.jpg");
	this->addChild(spr);
	spr->setPosition(Vec2(600, 300));
	spr->setScale(0.1f);

	// アクションの作成　　　　　　　秒数　　　X座標 Y座標
	//ScaleBy* action1 = ScaleBy::create(1.0f, 2.0f);
	//MoveBy* action1 = MoveBy::create(1.0f, Vec2(200, 100));
	JumpTo* action1 = JumpTo::create(2.0f, Vec2(900, 200), 300.0f, 2);
	//Blink* action1 = Blink::create(5.0f, 5);
	//SkewTo* action1 = SkewTo::create(1.0f, 0, 30);
	//TintTo* action1 = TintTo::create(2.0f, Color3B(255, 0, 0));
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(600, 600);
	//conf.controlPoint_2 = Vec2(900, 600);
	//conf.endPosition = Vec2(900, 300);
	//BezierTo* action1 = BezierTo::create(3.0f, conf);
	
	//MoveBy* action1 = MoveBy::create(2.0f, Vec2(600, 300));
	//EaseIn* action2 = EaseIn::create(action1, 2.0f);
	//EaseExponentialIn* action2 = EaseExponentialIn::create(action1);
	//EaseSineIn* action2 = EaseSineIn::create(action1);
	//EaseElasticIn* action2 = EaseElasticIn::create(action1, 2.0f);
	EaseBounceIn* action2 = EaseBounceIn::create(action1);
	//EaseBackIn* action2 = EaseBackIn::create(action1);

	// ノードに対してアクションを実行する
	spr->runAction(action2);

    return true;
}

// 毎フレーム更新処理（継続的に何かさせること）
void HelloWorld::update(float delta)
{
	
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
