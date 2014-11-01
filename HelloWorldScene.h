#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


class HelloWorld;

class HelloWorldHud : public cocos2d::Layer
{
public:
	void numCollectedChanged(int numCollected);
	virtual bool init();
	CREATE_FUNC(HelloWorldHud);

	cocos2d::LabelTTF *label;
	void projectileButtonTapped(cocos2d::Object *pSender);
	CC_SYNTHESIZE(HelloWorld *, _gameLayer, GameLayer);
};

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void enemyMoveFinished(cocos2d::Object *pSender);
	void projectileMoveFinished(cocos2d::Object *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void setViewPointCenter(cocos2d::Point position);
	void setPlayerPosition(cocos2d::Point position);
	cocos2d::Point tileCoordForPosition(cocos2d::Point position);
	void addEnemyAtPos(cocos2d::Point pos);
	void animateEnemy(cocos2d::Sprite *enemy);
	void testCollisions(float dt);
	void win();
	void lose();
	CC_SYNTHESIZE(int, _mode, Mode);
private:
	cocos2d::TMXTiledMap *_tileMap;
	cocos2d::TMXLayer *_background;
	cocos2d::TMXLayer *_foreground;
	cocos2d::Sprite *_player;
	cocos2d::TMXLayer *_meta;
	int _numCollected;
	static HelloWorldHud *_hud;
	cocos2d::Vector<cocos2d::Sprite *> _enemies;
	cocos2d::Vector<cocos2d::Sprite *> _projectiles;
};


#endif // __HELLOWORLD_SCENE_H__
