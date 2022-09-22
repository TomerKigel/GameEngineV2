#pragma once
#include "Factory.h"
#include <SFML\Graphics.hpp>

MonsterParameters Factory::Monster_Parameters;
BatParameters Factory::Bat_Parameters;
PlayerParameters Factory::Player_Parameters;
StaticParameters Factory::StaticObject_Parameters;
ItemParameters Factory::Item_Parameters;
SkillParameters Factory::Skill_Parameters;

std::vector<std::shared_ptr<Object>> Factory::Object_List;
static std::shared_ptr<Sound> tpl = nullptr;
static std::shared_ptr<Player> isalive = nullptr;
static std::shared_ptr<Textures> GameAssets = nullptr;

std::vector<std::shared_ptr<Object>>* Factory::callObjectList()
{
	return &Object_List;
}

void Factory::destoryList()
{
	Object_List.clear();
}

void Factory::destoryObject(int i)
{
	Object_List.erase(Object_List.begin() + i);
	Object_List.shrink_to_fit();
}

std::shared_ptr<Monster> Factory::CreateMonster(std::string mname)
{
	if (mname == "Monster") {
		std::shared_ptr<Monster> tm = std::make_shared<Monster>(Monster_Parameters.range, Monster_Parameters.hp, Monster_Parameters.ad, Monster_Parameters.speed, Monster_Parameters.window, nullptr);
		Object_List.push_back(tm);
		return tm;
	}
	else if (mname == "Yeti") {
		std::shared_ptr<Yeti> tm = std::make_shared<Yeti>(Monster_Parameters.speed, Monster_Parameters.range, Monster_Parameters.hp, Monster_Parameters.ad, Monster_Parameters.speed, Monster_Parameters.window, Monster_Parameters.texture);
		Object_List.push_back(tm);
		return tm;
	}
	else if (mname == "Bat") { 
		std::shared_ptr<Bat> tm = std::make_shared<Bat>(Bat_Parameters.optimalhight, Monster_Parameters.speed, Monster_Parameters.range, Monster_Parameters.hp, Monster_Parameters.ad, Monster_Parameters.speed, Monster_Parameters.window, Monster_Parameters.texture);
		Object_List.push_back(tm);
		return tm;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<Player> Factory::CreatePlayer()
{
	std::shared_ptr<Player> tpl = std::make_shared<Player>(Player_Parameters.range, Player_Parameters.hp, Player_Parameters.ad, Player_Parameters.speed, Player_Parameters.window, Player_Parameters.texture);
	Object_List.push_back(tpl);
	return tpl;
}

std::shared_ptr<StaticObject> Factory::CreateStaticObject()
{
	std::shared_ptr<StaticObject> ts = std::make_shared<StaticObject>(StaticObject_Parameters.range, StaticObject_Parameters.window, StaticObject_Parameters.texture);
	Object_List.push_back(ts);
	return ts;
}

std::shared_ptr<Item> Factory::CreateItem()
{
	std::shared_ptr<Item> tit = std::make_shared<Item>(Item_Parameters.range, Item_Parameters.window, Item_Parameters.texture);

	Object_List.push_back(tit);
	return tit;
}

std::shared_ptr<Skill> Factory::CreateSkill()
{
	std::shared_ptr<Skill> s = std::make_shared<Skill>(Skill_Parameters.Point_of_creation, 0, Skill_Parameters.window, Skill_Parameters.texture, Skill_Parameters.direction, Skill_Parameters.ownr);

	Object_List.push_back(s);
	return s;
}

std::shared_ptr<Sound> Factory::CreateSound()
{
	if (tpl == nullptr) {
		tpl = std::make_shared<Sound>();
	}

	return tpl;
}

std::shared_ptr<Textures> Factory::CreatGameAssets()
{
	if (GameAssets == nullptr) {
		GameAssets = std::make_shared<Textures>();
	}

	return GameAssets;
}


void Factory::SetUpMstr::SetUpMonster(double tlx, double tly, double brx, double bry, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window)
{
	Monster_Parameters.range(tlx, tly, brx, bry);
	Monster_Parameters.mhp = Monster_Parameters.hp = hp;
	Monster_Parameters.ad = ad;
	Monster_Parameters.window = window;
	Monster_Parameters.speed = spd;
}

void Factory::SetUpMstr::SetUpMonster(Point Tl, Point Br, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window)
{
	Monster_Parameters.range(Tl, Br);
	Monster_Parameters.hp = hp;
	Monster_Parameters.ad = ad;
	Monster_Parameters.window = window;
	Monster_Parameters.speed = spd;
}

void Factory::SetUpMstr::SetUpMonster(AABB range, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window)
{
	Monster_Parameters.range = range;
	Monster_Parameters.hp = hp;
	Monster_Parameters.ad = ad;
	Monster_Parameters.window = window;
	Monster_Parameters.speed = spd;
}

void Factory::SetUpMstr::SetUpYeti(double spd, std::string filename)
{
	Monster_Parameters.speed = spd;
	if (filename != "")
	{
		Monster_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpMstr::SetUpBat(double optimalhight, double spd, std::string filename)
{
	Bat_Parameters.optimalhight = optimalhight;
	Monster_Parameters.speed = spd;
	if (filename != "")
	{
		Monster_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(double tlx, double tly, double brx, double bry, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Player_Parameters.range(tlx, tly, brx, bry);
	Player_Parameters.mhp = Player_Parameters.hp = hp;
	Player_Parameters.ad = ad;
	Player_Parameters.window = window;
	Player_Parameters.speed = spd;
	if (filename != "")
	{
		Player_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(Point Tl, Point Br, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Player_Parameters.range(Tl, Br);
	Player_Parameters.hp = hp;
	Player_Parameters.ad = ad;
	Player_Parameters.window = window;
	Player_Parameters.speed = spd;
	if (filename != "")
	{
		Player_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(AABB range, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Player_Parameters.range = range;
	Player_Parameters.hp = hp;
	Player_Parameters.ad = ad;
	Player_Parameters.window = window;
	Player_Parameters.speed = spd;
	if (filename != "")
	{
		Player_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(double tlx, double tly, double brx, double bry, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	StaticObject_Parameters.range(tlx, tly, brx, bry);
	StaticObject_Parameters.window = window;
	if (filename != "")
	{
		StaticObject_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(Point Tl, Point Br, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	StaticObject_Parameters.range(Tl, Br);
	StaticObject_Parameters.window = window;
	if (filename != "")
	{
		StaticObject_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(AABB range, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	StaticObject_Parameters.range = range;
	StaticObject_Parameters.window = window;
	if (filename != "")
	{
		StaticObject_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(double tlx, double tly, double brx, double bry, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Item_Parameters.range(tlx, tly, brx, bry);
	Item_Parameters.window = window;
	if (filename != "")
	{
		Item_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(Point Tl, Point Br, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Item_Parameters.range(Tl, Br);
	Item_Parameters.window = window;
	if (filename != "")
	{
		Item_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(AABB range, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	Item_Parameters.range = range;
	Item_Parameters.window = window;
	if (filename != "")
	{
		Item_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpsk::SetUpSkill(double Point_of_creation_x_coordinate, double Point_of_creation_y_coordinate, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o, short direction)
{
	Skill_Parameters.Point_of_creation(Point_of_creation_x_coordinate, Point_of_creation_y_coordinate);
	Skill_Parameters.window = window;
	Skill_Parameters.ownr = o;
	Skill_Parameters.direction = direction;
	if (filename != "")
	{
		Skill_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpsk::SetUpSkill(Point Point_of_creation, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o, short direction)
{
	Skill_Parameters.Point_of_creation = Point_of_creation;
	Skill_Parameters.window = window;
	Skill_Parameters.ownr = o;
	Skill_Parameters.direction = direction;
	if (filename != "")
	{
		Skill_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

//void Factory::SetUpsk::SetUpSkill(AABB* range, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o, short direction)
//{
//	Skill_Parameters.range = *range;
//	Skill_Parameters.window = window;
//	Skill_Parameters.ownr = o;
//	Skill_Parameters.direction = direction;
//	if (filename != "")
//	{
//		Skill_Parameters.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
//	}
//}