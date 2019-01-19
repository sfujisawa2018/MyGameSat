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
#include <stdlib.h>

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
	// 乱数の初期化
	srand(time(0));

	//// スプライトの生成
	//Sprite* spr = Sprite::create("mario.jpg");
	////           描画優先
	//addChild(spr, 50);
	//spr->setScale(0.1f);
	//// 初期位置の設定
	//spr->setPosition(Vec2(200.0f, 200.0f));

	//MoveTo* actionMove = MoveTo::create(3.0f, Vec2(500,500));

	//// 関数呼び出しアクションの作成
	//CallFunc* action = CallFunc::create(
	//	CC_CALLBACK_0(HelloWorld::MyFunction, this));

	//Sequence* actionSeq = Sequence::create(actionMove, action, nullptr);

	//spr->runAction(actionSeq);

	// 1/19
	// イベントリスナーを作成する
	EventListenerTouchOneByOne * listner = EventListenerTouchOneByOne::create();
	// イベントリスナーに各コールバックをセットする
	listner->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listner->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listner->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listner->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	// イベントリスナーを登録する
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listner, this);

	// 画像の生成
	spr = Sprite::create("mario.jpg");
	spr->setScale(0.05f);
	spr->setPosition(Vec2(500,500));
	this->addChild(spr);

    return true;
}

// 自作メンバ関数
void HelloWorld::MyFunction()
{
	//log("Hello, MyFunction!!");

	Sprite* spr = Sprite::create("HelloWorld.png");
	addChild(spr);

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

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	// タッチ座標を取得
	Vec2 touch_pos = touch->getLocation();

	// スプライトが空でなければ
	if (spr != nullptr)
	{
		// スプライトのAABBを取得
		Rect rect_spr = spr->getBoundingBox();

		// スプライトにタッチ座標が含まれるかどうか
		bool hit = rect_spr.containsPoint(touch_pos);

		if (hit)
		{
			// タッチした時に実行したい処理
			log("touch sprite!!");
			// スプライトを削除
			spr->removeFromParent();
			spr = nullptr; // スプライトは空です
		}
	}

	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* unused_event)
{
	// タッチ座標を取得
	Vec2 touch_pos = touch->getLocation();
}

void HelloWorld::onTouchEnded(Touch* touch, Event* unused_event)
{
	// タッチ座標を取得
	Vec2 touch_pos = touch->getLocation();
}

void HelloWorld::onTouchCancelled(Touch* touch, Event* unused_event)
{
	// タッチ座標を取得
	Vec2 touch_pos = touch->getLocation();
}