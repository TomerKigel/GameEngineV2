#pragma once
#pragma once
#include "Cooldown.h"
#include "Point.h"

// Global engine values
static double GForce = 0;
static double E_TopSpeed = 100;
static double E_TopAcceleration = 10;

typedef struct
{
	double xspeed;
	double yspeed;
	double topspeed;

	double accy;
	double accx;
	double topacc;

}PhysicsStats;

class Physics
{
private:
	bool unEffected;
	Cooldown phyTimer;
	PhysicsStats stats;
public:
	////////////////////////////////////////////////////////////////////////////////////////
	//Default constructor			
	//
	//\brief   sets the object's values such as speed and acceleration...
	////////////////////////////////////////////////////////////////////////////////////////
	Physics(double topspeed = 5, double topacc = 1, double startxspeed = 0, double startyspeed = 0, double startxacc = 0, double startyacc = 0);

	////////////////////////////////////////////////////////////////////////////////////////
	//Gravirty manipulators		
	//
	//\brief   changes gravity settings
	//
	//\names selfexplenatory
	////////////////////////////////////////////////////////////////////////////////////////
	static void GravityOn();
	static void GravityOff();
	static void GravityUpward();
	static void GravityFlip();

	////////////////////////////////////////////////////////////////////////////////////////
	//Object effectedness			
	//
	//\brief   decides if object affected by gravity or not
	////////////////////////////////////////////////////////////////////////////////////////
	void UnEffectedByGravity();
	void EffectedByGravity();

	////////////////////////////////////////////////////////////////////////////////////////
	//Mutators		
	//
	//\brief   set of mutators to change values with in the class
	////////////////////////////////////////////////////////////////////////////////////////
	void setObjectsParameters(PhysicsStats sts);
	void setTopSpeed(double topspeed = 5);
	void setTopAcc(double topacc);
	void AccelerateY(double i);
	void AccelerateX(double i);
	void intersection(bool isx, bool isy, short dir);


	////////////////////////////////////////////////////////////////////////////////////////
	//Accessors				
	//
	//\brief   set of accessors to get current state of speed and acceleration
	////////////////////////////////////////////////////////////////////////////////////////
	Point reSpeed();
	Point reAcc();


	////////////////////////////////////////////////////////////////////////////////////////
	//Main calculation function				
	//
	//\brief   makes all calculations, sets speed according to acceleration
	////////////////////////////////////////////////////////////////////////////////////////
	PhysicsStats calcSpeed();

	////////////////////////////////////////////////////////////////////////////////////////
	//Default destructor			
	//
	//\brief   destorys the object
	////////////////////////////////////////////////////////////////////////////////////////
	~Physics() {}
};