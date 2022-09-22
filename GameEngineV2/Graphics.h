#pragma once
#include "SFML\Graphics.hpp"
#include "AABB.h"

typedef struct
{
	std::shared_ptr<sf::Texture> localtx;
	std::string name;
	short framesintxt, rows;
	short currframe, currrow;
	AABB* taf;
}TexBuf;

class Graphics
{
private:
	enum drawables { BOX, SPR };
	sf::RectangleShape gbox;
	sf::Sprite spr;
	std::vector<TexBuf> TB;
	int CurrentTB;
	short wtod;
	std::shared_ptr<sf::RenderWindow> window;
	short direction;

	Graphics() {
		CurrentTB = 0;
		direction = 0;
		wtod = 0;
	}
public:
	////////////////////////////////////////////////////////////////////////////////////////
	//Default constructor			
	//
	//\brief   sets a rectangle
	//
	//\param tlc   position of the rect	
	//\param size  size of the rectangle
	////////////////////////////////////////////////////////////////////////////////////////
	Graphics(sf::Vector2f tlc, sf::Vector2f size, std::shared_ptr<sf::RenderWindow> win, AABB* sizeofobj = nullptr);

	////////////////////////////////////////////////////////////////////////////////////////
	//Default constructor			
	//
	//\brief   sets a sprite
	//
	//\param spr  sprite													
	////////////////////////////////////////////////////////////////////////////////////////
	Graphics(sf::Vector2f tlc, std::shared_ptr<sf::Texture> texture, std::shared_ptr<sf::RenderWindow> win, AABB* sizeofobj = nullptr);

	////////////////////////////////////////////////////////////////////////////////////////
	//Default constructor			
	//
	//\brief   sets a sprite
	//
	//\param spr  sprite													
	////////////////////////////////////////////////////////////////////////////////////////
	Graphics(sf::Vector2f tlc, std::string filename, std::shared_ptr<sf::RenderWindow> win, AABB* sizeofobj = nullptr);

	////////////////////////////////////////////////////////////////////////////////////////
	//Draw function			
	//
	//\brief   draws the object
	//
	//\param win  window handle to draw in												
	////////////////////////////////////////////////////////////////////////////////////////
	void Draw();

	void AddResource(std::shared_ptr<sf::Texture> texture, std::string name, AABB* sizeofobj);

	void ChangeResourceTo(std::string name);

	std::string GetCurrResourceName();

	std::shared_ptr<sf::RenderWindow> rewin();

	void refreshPosition(sf::Vector2f pos);

	void changeColor(bool c);

	void changeColor(sf::Uint8 g, sf::Uint8 b, sf::Uint8 r, sf::Uint8 alpha);

	void switchToNextFrame();

	void FlipHorizontali();

	short reDir();

	void setView(sf::View viewtoset);

	~Graphics();
};