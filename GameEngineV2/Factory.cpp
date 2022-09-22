#pragma once
#include "Factory.h"
#include <SFML\Graphics.hpp>

MonsterParameters Factory::mparam;
YetiParameters Factory::yetiparam;
BatParameters Factory::btparam;
PlayerParameters Factory::pparam;
StaticParameters Factory::sparam;
ItemParameters Factory::iparam;
SkillParameters Factory::skparam;

std::vector<std::shared_ptr<Object>> Factory::list;
static std::shared_ptr<Sound> tpl = nullptr;
//static std::shared_ptr<Textures> tpga = nullptr;
static std::shared_ptr<Player> isalive = nullptr;
static std::shared_ptr<Textures> GameAssets = nullptr;

std::vector<std::shared_ptr<Object>>* Factory::callobjectList()
{
	return &list;
}

void Factory::destorylist()
{
	list.clear();
}

void Factory::destoryObject(int i)
{
	list.erase(list.begin() + i);
	list.shrink_to_fit();
}

std::shared_ptr<Monster> Factory::CreateMonster(std::string mname)
{
	if (mname == "Monster") {
		std::shared_ptr<Monster> tm = std::make_shared<Monster>(mparam.range, mparam.hp, mparam.ad, mparam.speed, mparam.window, nullptr);
		list.push_back(tm);
		return tm;
	}
	else if (mname == "Yeti") {
		std::shared_ptr<Yeti> tm = std::make_shared<Yeti>(yetiparam.speed, mparam.range, mparam.hp, mparam.ad, mparam.speed, mparam.window, yetiparam.texture);
		list.push_back(tm);
		return tm;
	}
	else if (mname == "Bat") { 
		std::shared_ptr<Bat> tm = std::make_shared<Bat>(btparam.optimalhight, btparam.speed, mparam.range, mparam.hp, mparam.ad, mparam.speed, mparam.window, btparam.texture);
		list.push_back(tm);
		return tm;
	}
	else
	{
		return nullptr;
	}
}

std::shared_ptr<Player> Factory::CreatePlayer()
{
	std::shared_ptr<Player> tpl = std::make_shared<Player>(pparam.range, pparam.hp, pparam.ad, pparam.speed, pparam.window, pparam.texture);
	list.push_back(tpl);
	return tpl;
}

std::shared_ptr<StaticObject> Factory::CreatestaticObject()
{
	std::shared_ptr<StaticObject> ts = std::make_shared<StaticObject>(sparam.range, sparam.window, sparam.texture);
	list.push_back(ts);
	return ts;
}

std::shared_ptr<Item> Factory::CreateItem()
{
	std::shared_ptr<Item> tit = std::make_shared<Item>(iparam.range, iparam.window, iparam.texture);

	list.push_back(tit);
	return tit;
}

std::shared_ptr<Skill> Factory::CreateSkill()
{
	std::shared_ptr<Skill> s = std::make_shared<Skill>(skparam.range, 0, skparam.window, skparam.texture, skparam.ownr);

	list.push_back(s);
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
	mparam.range(tlx, tly, brx, bry);
	mparam.mhp = mparam.hp = hp;
	mparam.ad = ad;
	mparam.window = window;
	mparam.speed = spd;
}

void Factory::SetUpMstr::SetUpMonster(Point* Tl, Point* Br, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window)
{
	mparam.range(*Tl, *Br);
	mparam.hp = hp;
	mparam.ad = ad;
	mparam.window = window;
	mparam.speed = spd;
}

void Factory::SetUpMstr::SetUpMonster(AABB* range, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window)
{
	mparam.range = *range;
	mparam.hp = hp;
	mparam.ad = ad;
	mparam.window = window;
	mparam.speed = spd;
}

void Factory::SetUpMstr::SetUpYeti(double spd, std::string filename)
{
	yetiparam.speed = spd;
	if (filename != "")
	{
		yetiparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpMstr::SetUpBat(double optimalhight, double spd, std::string filename)
{
	btparam.optimalhight = optimalhight;
	btparam.speed = spd;
	if (filename != "")
	{
		btparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(double tlx, double tly, double brx, double bry, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	pparam.range(tlx, tly, brx, bry);
	pparam.mhp = pparam.hp = hp;
	pparam.ad = ad;
	pparam.window = window;
	pparam.speed = spd;
	if (filename != "")
	{
		pparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(Point* Tl, Point* Br, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	pparam.range(*Tl, *Br);
	pparam.hp = hp;
	pparam.ad = ad;
	pparam.window = window;
	pparam.speed = spd;
	if (filename != "")
	{
		pparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpPlyr::SetUpPlayer(AABB* range, double hp, double ad, double spd, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	pparam.range = *range;
	pparam.hp = hp;
	pparam.ad = ad;
	pparam.window = window;
	pparam.speed = spd;
	if (filename != "")
	{
		pparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(double tlx, double tly, double brx, double bry, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	sparam.range(tlx, tly, brx, bry);
	sparam.window = window;
	if (filename != "")
	{
		sparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(Point* Tl, Point* Br, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	sparam.range(*Tl, *Br);
	sparam.window = window;
	if (filename != "")
	{
		sparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpStatic::SetUpStaticObject(AABB* range, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	sparam.range = *range;
	sparam.window = window;
	if (filename != "")
	{
		sparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(double tlx, double tly, double brx, double bry, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	iparam.range(tlx, tly, brx, bry);
	iparam.window = window;
	if (filename != "")
	{
		iparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(Point* Tl, Point* Br, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	iparam.range(*Tl, *Br);
	iparam.window = window;
	if (filename != "")
	{
		iparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpItm::SetUpItem(AABB* range, std::shared_ptr<sf::RenderWindow> window, std::string filename)
{
	iparam.range = *range;
	iparam.window = window;
	if (filename != "")
	{
		iparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpsk::SetUpSkill(double tlx, double tly, double brx, double bry, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o)
{
	skparam.range(tlx, tly, brx, bry);
	skparam.window = window;
	skparam.ownr = o;
	if (filename != "")
	{
		skparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpsk::SetUpSkill(Point* Tl, Point* Br, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o)
{
	skparam.range(*Tl, *Br);
	skparam.window = window;
	skparam.ownr = o;
	if (filename != "")
	{
		skparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}

void Factory::SetUpsk::SetUpSkill(AABB* range, std::shared_ptr<sf::RenderWindow> window, std::string filename, std::shared_ptr<Object> o)
{
	skparam.range = *range;
	skparam.window = window;
	skparam.ownr = o;
	if (filename != "")
	{
		skparam.texture = std::make_shared<sf::Texture>(*GameAssets->getTexture(filename));
	}
}