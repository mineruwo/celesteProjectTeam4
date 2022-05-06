#pragma once
#include "Scene.h"
#include "../Utils/TextureHolder.h"
#include "../Utils/InputMgr.h"
#include "../SceneMgr/SceneMgr.h"

using namespace sf;
using namespace std;

class GamePlay : public Scene
{
private:



	SceneID currScene;

public:
	GamePlay();
	~GamePlay();

	virtual void Init(Vector2i resolution);
	virtual void Update(Time dt, RenderWindow& window);
	virtual void Draw(RenderWindow& window);
	virtual void Release();

};
