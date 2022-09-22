#pragma once
#include "Mat.h"
#include "AABB.h"
#include "Drawable.h"
#include "Actionable.h"
#include "Interactable.h"

class Object : public Interactable , public Drawable , public Actionable
{
protected:
	AABB space;
	Object() {}
	bool destruct = false;
	void destroy() { destruct = true; }
public:
	virtual short reType() { return Obj; }
	bool isUpForDestruction() { return destruct; }
	virtual void draw() {};
	~Object() {}

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   returns the AABB of the object										
	////////////////////////////////////////////////////////////////////////////////////////
	virtual AABB* getAABB()
	{
		return &space;
	}

	////////////////////////////////////////////////////////////////////////////////////////
	//accessor			
	//
	//\brief   returns the AABB of the object										
	////////////////////////////////////////////////////////////////////////////////////////
	virtual Point getCenter()
	{
		return space.getCenter();
	}


	virtual void setAABB(AABB &aabb)
	{
		space = aabb;
	}
};