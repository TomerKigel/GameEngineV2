#pragma once

#include "Movable.h"
#include "Graphics.h"
#include "Living.h"
#include "Mat.h"
#include <memory>
#include "Sound.h"
#include "PState.h"
#include <math.h> 


class Player : public Living, public Movable, public std::enable_shared_from_this<Player>
{
private:
	std::shared_ptr<Graphics> mdisp;
	Cooldown animantioncooldown, invulnerable, attspd, dashcooldown, jumpcooldown;
	Cooldown djump;
	sf::View playerview;
	sf::Sound attacksound, jumpsound;

	inputstatus inp;
	int zm;

	Player();

	////////////////////////////////////////////////////////////////////////////////////////
	//Movement managment			
	//
	//\brief   moves the object
	//
	//\param spdx   movement value - pixels in the x axis
	//\param spdy   movement value - pixels in the y axis
	////////////////////////////////////////////////////////////////////////////////////////
	void Move(double xspd, double yspd);
public:
	states ps;


	////////////////////////////////////////////////////////////////////////////////////////
	//Default constructor			
	//
	//\brief   sets the objects different parameters
	//
	//\param range   AABB  
	//\param hp      Health Points
	//\param ad      Attack Damage
	//\param window  window handle pointer
	////////////////////////////////////////////////////////////////////////////////////////
	Player(AABB range, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<sf::Texture> txt);


	////////////////////////////////////////////////////////////////////////////////////////
	//Tester			
	//
	//\brief   Tests if Health below 0 and destories object if it is													
	////////////////////////////////////////////////////////////////////////////////////////
	void amidead();

	////////////////////////////////////////////////////////////////////////////////////////
	//Graphical draw			
	//
	//\brief   Draws the object	to the window						
	////////////////////////////////////////////////////////////////////////////////////////
	void draw();

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   returns the object type											
	////////////////////////////////////////////////////////////////////////////////////////
	virtual short reType();

	////////////////////////////////////////////////////////////////////////////////////////
	//Graphics updater		
	//
	//\brief   updates the graphical position of the object and any other graphical changes									
	////////////////////////////////////////////////////////////////////////////////////////
	void refreshgraphics(sf::Vector2f pos);

	////////////////////////////////////////////////////////////////////////////////////////
	//User input loop		
	//
	//\brief   gets keyboard hits and reacts acordingly									
	////////////////////////////////////////////////////////////////////////////////////////
	void Controls();


	////////////////////////////////////////////////////////////////////////////////////////
	//collision resolution		
	//
	//\brief   resolves intersection with different object types								
	////////////////////////////////////////////////////////////////////////////////////////
	bool InteractWith(Interactable* obj,short type);


	void PViewAdjustLoop(double xspd, double yspd);

	void HealthToSpd();

	void GotHit();

	void ZoomOut();

	void ZoomIn();

	states reState();

	void action();

	////////////////////////////////////////////////////////////////////////////////////////
	//Default destructor		
	//
	//\brief  destroys the object							
	////////////////////////////////////////////////////////////////////////////////////////
	~Player();



};