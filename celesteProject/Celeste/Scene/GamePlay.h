#pragma once
#include "Scene.h"
#include "../Utils/TextureHolder.h"
#include "../Utils/InputMgr.h"
#include "../SceneMgr/SceneMgr.h"
#include "../Bat.h"
#include "../Wall.h"
#include "../Player/Player.h"
using namespace sf;
using namespace std;

class GamePlay : public Scene
{
private:

	Player player;
	Bat bat;
	Wall wall;

	FloatRect bats;
	std::vector <Wall*> walls;

	SceneID currScene;

public:

	GamePlay();
	//~GamePlay();

	void CreateWalls();

	virtual void Init(Vector2i resolution);
	virtual void Update(Time dt, RenderWindow& window);
	virtual void Draw(RenderWindow& window);
	virtual void Release();

};

