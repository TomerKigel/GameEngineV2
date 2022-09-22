#pragma once
#include "AABB.h"

class Interactable
{
public:
	virtual AABB* getAABB() = 0;
	virtual void setAABB(AABB &aabb) = 0;
	virtual std::shared_ptr<Point> getCenter() = 0 ;
	virtual bool InteractWith(Interactable* obj, short type) { return false; };
	virtual short reType() = 0;
};