#pragma once
#include "Sound.h"
#include "Graphics.h"
#include "Player.h"
#include "QuadTree.h"
#include <fstream>
#include <iterator>
#include "Interactable.h"
#include "Object.h"

class GameEngine
{
private:
	bool isPaused;
	bool GameOver = false;
	std::shared_ptr<Sound> sound_handle;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> menu_texture;
	std::shared_ptr<Graphics> menu;
	std::shared_ptr<sf::Texture> gameover_texture;
	std::shared_ptr<Graphics> gameover_menu;
	sf::Event event;
	sf::Sound theme;
	sf::Clock frameClock;
	int ElapsedTime;

	void EventLoop();
public:
	GameEngine(char* filename = nullptr);
	void UtilityAssetSetUp();
	void LoadingScreen();
	void SoundSetup();
	void GameLoop();

	void run(QuadTree* QT, std::vector<std::shared_ptr<Object>>* mst, Graphics* ls);
	void Running(QuadTree* QT, std::vector<std::shared_ptr<Object>>* mst);
	void Operate(std::vector<std::shared_ptr<Object>>* mst, QuadTree* QT, Graphics* ls);
	void ActivateObjects(std::vector<std::shared_ptr<Object>>* mst);
	void InsertObjectsToQuadTree(QuadTree* QT, std::vector<std::shared_ptr<Object>>* mst);
	void DrawAllObjects(std::vector<std::shared_ptr<Object>>* mst, Graphics* ls);
	void Musicfilestream(std::string filename);
	void Graphicsfilestream(std::string filename);
	void LoadFromFile(std::string filename);
	void EndOrDestory(std::vector<std::shared_ptr<Object>>* mst);
	~GameEngine();
};