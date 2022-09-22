#pragma once

#include <string>
#include "Player.h"
#include "Monster.h"
#include "StaticObject.h"
#include "Item.h"
#include "Skill.h"
#include "AABB.h"
#include "Sound.h"
#include "Textures.h"
#include "Yeti.h"
#include "Bat.h"
#include "Interactable.h"

////////////////////////////////////////////////////////////////////////////////////////
//Structeture of monster parameters	
//
//\brief   Struct that hold data about the object that is about to be created
////////////////////////////////////////////////////////////////////////////////////////
struct MonsterParameters
{
	AABB range;
	std::shared_ptr<sf::RenderWindow> window;
	double hp;
	double mhp;
	double ad;
	double speed;
};


struct YetiParameters
{
	std::shared_ptr<sf::Texture> texture;
	double speed = 1;
};

struct BatParameters
{
	double optimalhight;
	std::shared_ptr<sf::Texture> texture;
	double speed = 1;
};

////////////////////////////////////////////////////////////////////////////////////////
//Structeture of Player parameters	
//
//\brief   Struct that hold data about the object that is about to be created
////////////////////////////////////////////////////////////////////////////////////////
struct PlayerParameters
{
	AABB range;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> texture;
	double hp;
	double mhp;
	double ad;
	double speed;
};


////////////////////////////////////////////////////////////////////////////////////////
//Structeture of Static Objects parameters	
//
//\brief   Struct that hold data about the object that is about to be created
////////////////////////////////////////////////////////////////////////////////////////
struct StaticParameters
{
	AABB range;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> texture;
};

////////////////////////////////////////////////////////////////////////////////////////
//Structeture of Skill Objects parameters	
//
//\brief   Struct that hold data about the object that is about to be created
////////////////////////////////////////////////////////////////////////////////////////
struct SkillParameters
{
	AABB range;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<Object> ownr;
};


////////////////////////////////////////////////////////////////////////////////////////
//Structeture of Item parameters	
//
//\brief   Struct that hold data about the object that is about to be created
////////////////////////////////////////////////////////////////////////////////////////
struct ItemParameters
{
	AABB range;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<sf::Texture> texture;
};


class Factory
{
private:
	static std::vector<std::shared_ptr<Object>> list;
	static MonsterParameters mparam;
	static YetiParameters yetiparam;
	static PlayerParameters pparam;
	static StaticParameters sparam;
	static ItemParameters iparam;
	static SkillParameters skparam;
	static BatParameters btparam;
public:
	static std::vector<std::shared_ptr<Object>>* callobjectList();
	static void destorylist();
	static void destoryObject(int i);
	////////////////////////////////////////////////////////////////////////////////////////
	//Monster Creater 			
	//
	//\brief   Creates an objects using parameters defined in mparam
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Monster> CreateMonster(std::string mname);

	////////////////////////////////////////////////////////////////////////////////////////
	//Player Creater 			
	//
	//\brief   Creates an objects using parameters defined in pparam
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Player> CreatePlayer();

	////////////////////////////////////////////////////////////////////////////////////////
	//Static object Creater 			
	//
	//\brief   Creates an objects using parameters defined in soparam
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<StaticObject> CreatestaticObject();

	////////////////////////////////////////////////////////////////////////////////////////
	//Static object Creater 			
	//
	//\brief   Creates an objects using parameters defined in soparam
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Item> CreateItem();

	////////////////////////////////////////////////////////////////////////////////////////
	//Static object Creater 			
	//
	//\brief   Creates an objects using parameters defined in soparam
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Skill> CreateSkill();

	////////////////////////////////////////////////////////////////////////////////////////
	//Sound singelton Creater 			
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Sound> CreateSound();

	////////////////////////////////////////////////////////////////////////////////////////
	//Sound singelton Creater 			
	////////////////////////////////////////////////////////////////////////////////////////
	static std::shared_ptr<Textures> CreatGameAssets();

	////////////////////////////////////////////////////////////////////////////////////////
	//Static object Creater 			
	//
	//\brief   Creates an objects using parameters defined in soparam
	////////////////////////////////////////////////////////////////////////////////////////
	/*static MovableObject *CreateMovableObject();*/

	////////////////////////////////////////////////////////////////////////////////////////
	//Set up parameters in param types			
	//
	//\brief   sets up all variables inside 'Parameters' types
	//
	//\param tlx,tly,brx,bry,TL,BR,range   position of the rectangle to be created by X and Y values or two points or an aabb range	
	//\param hp is max health points and 
	////////////////////////////////////////////////////////////////////////////////////////
	union SetUpMstr
	{
		static void SetUpMonster(double tlx = 0, double tly = 0, double brx = 0, double bry = 0, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr);
		static void SetUpMonster(Point* Tl = nullptr, Point* Br = nullptr, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr);
		static void SetUpMonster(AABB* range = nullptr, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr);
		static void SetUpYeti(double spd, std::string filename = "");
		static void SetUpBat(double optimalhight, double spd, std::string filename = "");
	};
	union SetUpPlyr
	{
		static void SetUpPlayer(double tlx = 0, double tly = 0, double brx = 0, double bry = 0, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpPlayer(Point* Tl = nullptr, Point* Br = nullptr, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpPlayer(AABB* range = nullptr, double hp = 0, double ad = 0, double spd = 5, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
	};
	union SetUpStatic
	{
		static void SetUpStaticObject(double tlx = 0, double tly = 0, double brx = 0, double bry = 0, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpStaticObject(Point* Tl = nullptr, Point* Br = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpStaticObject(AABB* range = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
	};
	union SetUpItm
	{
		static void SetUpItem(double tlx = 0, double tly = 0, double brx = 0, double bry = 0, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpItem(Point* Tl = nullptr, Point* Br = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
		static void SetUpItem(AABB* range = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "");
	};
	union SetUpsk
	{
		static void SetUpSkill(double tlx = 0, double tly = 0, double brx = 0, double bry = 0, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "", std::shared_ptr<Object> o = nullptr);
		static void SetUpSkill(Point* Tl = nullptr, Point* Br = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "", std::shared_ptr<Object> o = nullptr);
		static void SetUpSkill(AABB* range = nullptr, std::shared_ptr<sf::RenderWindow> window = nullptr, std::string filename = "", std::shared_ptr<Object> o = nullptr);
	};
};