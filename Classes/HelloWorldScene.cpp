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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}

	// テクスチャファイル名を指定して、スプライトを作成
	sprite = Sprite::create("sample01.png");
	// シーングラフにつなぐ
	this->addChild(sprite);
	// 表示座標を指定
	sprite->setPosition(Vec2(600.0f, 320.0f));

	// テクスチャの範囲指定
	sprite->setTextureRect(
		//                            X   Y  幅　高さ
		CC_RECT_PIXELS_TO_POINTS(Rect(0, 32, 32, 32))
	);
	sprite->getTexture()->setAliasTexParameters();
	//sprite->setTextureRect(Rect(0, 32, 32, 32));
	//// 回転角を指定
	//sprite->setRotation(45.0f);
	// スケールを指定
	sprite->setScale(5.0f);
	//// 左右反転
	//sprite->setFlippedX(true);
	//// 上下反転
	//sprite->setFlippedY(true);
	// 非表示にする
	//sprite->setVisible(false);
	// 色合いを設定          Red   Green Blue
	//sprite->setColor(Color3B(0xff, 0x80, 0x80));
	//sprite->setColor(Color3B(255, 255, 255));
	// 不透明度を設定
	//sprite->setOpacity(128);

	// updateが呼び出されるようにする
	this->scheduleUpdate();

	//// ０秒経過から始める
	//elapsedTime = 0.0f;
	//// 左移動から始める
	//dir = Left;

	// 画像のど真ん中が回転やスケーリングの中心
	//sprite->setAnchorPoint(Vec2(0.5f, 0.5f));

	// 歩きパターン0から始める
	pattern = 0;
	// 15フレーム後に切り替える設定
	timer = 15;

    return true;
}

// 毎フレーム更新処理（継続的に何かさせること）
void HelloWorld::update(float delta)
{
	// 経過時間を加算
	elapsedTime += delta;

	// タイマーが0になったら
	if (--timer <= 0)
	{
		switch (pattern)
		{
		case 0:
			// 歩きパターン２に切り替え
			pattern = 2;
			break;
		case 2:
			// 歩きパターン０に切り替え
			pattern = 0;
			break;
		}
		// 15フレーム後にタイマーを再設定
		timer = 15;
	}

	// パターン番号から、テクスチャの切り出し位置を決定
	sprite->setTextureRect(
		//                            X   Y  幅　高さ
		CC_RECT_PIXELS_TO_POINTS(Rect(32*pattern, 64, 32, 32))
	);

	//// 最大値を制限
	//if (elapsedTime > 5.0f) elapsedTime = 5.0f;

	//switch(dir)
	//{ // 移動処理
	//	// 左移動
	//case Left:
	//	{
	//		// スプライトの現在位置を取得
	//		Vec2 pos = sprite->getPosition();
	//		// 位置を移動させる
	//		pos += Vec2(-10.0f, 0.0f);
	//		// 移動後の座標を反映
	//		sprite->setPosition(pos);
	//		if (pos.x <= 80/2.0f)
	//		{
	//			dir = Down;
	//		}
	//		break;
	//	}
	//	
	//case Down:
	//	{// 下移動
	//		// スプライトの現在位置を取得
	//		Vec2 pos = sprite->getPosition();
	//		// 位置を移動させる
	//		pos += Vec2(0.0f, -10.0f);
	//		// 移動後の座標を反映
	//		sprite->setPosition(pos);
	//		if (pos.y <= 80 / 2.0f)
	//		{
	//			dir = Right;
	//		}
	//		break;
	//	}
	//}

	//{// ５秒で透明になる
	//	////              最大値                 秒数
	//	//float opacity = 255.0f * elapsedTime / 5.0f;
	//	//// 大小関係を逆転
	//	//opacity = 255 - opacity;
	//	//sprite->setOpacity(opacity);
	//}
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
