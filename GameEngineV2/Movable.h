#pragma once

#include "SFML\Graphics.hpp"
#include "Mat.h"
#include "Object.h"
#include "Physics.h"


class Movable : public Object
{
private:
	////////////////////////////////////////////////////////////////////////////////////////
	//virtual mutator function			
	//
	//\brief   moves the object in a direction
	//
	//\param xspd   pixels to move on the x axis		
	//\param yspd   pixels to move on the y axis	
	////////////////////////////////////////////////////////////////////////////////////////
	void setToMove(PhysicsStats ph);

protected:
	AABB Lastspace;

	Physics ph;
	////////////////////////////////////////////////////////////////////////////////////////
	//Default Constructor		
	////////////////////////////////////////////////////////////////////////////////////////
	Movable() { Lastspace = space; }

public:
	////////////////////////////////////////////////////////////////////////////////////////
	//virtual mutator function			
	//
	//\brief   moves the object in a direction
	//
	//\param xspd   pixels to move on the x axis		
	//\param yspd   pixels to move on the y axis	
	////////////////////////////////////////////////////////////////////////////////////////
	virtual void Move(double xspd, double yspd) = 0;

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   returns the object type											
	////////////////////////////////////////////////////////////////////////////////////////
	virtual short reType();

	

	////////////////////////////////////////////////////////////////////////////////////////
	//updater			
	//
	//\brief   updates the last place indicator the object has been to the current place											
	////////////////////////////////////////////////////////////////////////////////////////
	void refreshLastSpace();

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   returns the last place AABB of the object												
	////////////////////////////////////////////////////////////////////////////////////////
	AABB* getLastSpace();

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   sets the AABB to the last space it has been												
	////////////////////////////////////////////////////////////////////////////////////////
	void SpaceBack();

	////////////////////////////////////////////////////////////////////////////////////////
	//Initialize Physics state;			
	//
	//\brief   Moves object according to physics											
	////////////////////////////////////////////////////////////////////////////////////////
	void PhysicsInit();

	////////////////////////////////////////////////////////////////////////////////////////
	//Initialize Physics state;			
	//
	//\brief   Moves object according to physics											
	////////////////////////////////////////////////////////////////////////////////////////
	void PhysicsIntersection(short direction, double overlap);

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor		
	//
	//\brief   sets the AABB to the last space it has been												
	////////////////////////////////////////////////////////////////////////////////////////
	void Accelerate(double x, double y);

	////////////////////////////////////////////////////////////////////////////////////////
	//Default destructor			
	//
	//\brief   destroys the object													
	////////////////////////////////////////////////////////////////////////////////////////
	~Movable() {}
};

