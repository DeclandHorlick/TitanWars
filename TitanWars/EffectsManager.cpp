#include "stdafx.h"
#include "EffectsManager.h"

bool EffectsManager::instanceFlag = false;
EffectsManager* EffectsManager::instance = NULL;



EffectsManager* EffectsManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new EffectsManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void EffectsManager::addExplosion(b2Vec2 pos)
{
	myExplosions.push_back(new Explosion(pos));
}
void EffectsManager::update()
{
	RemoveExplosion();
}
void EffectsManager::reset()
{
	for (int i = 0; i < myExplosions.size(); i++)
	{
		myExplosions[i]->playExplode = false;
	}
	RemoveExplosion();
}
void EffectsManager::draw(sf::RenderWindow &window)
{
	
		for (int i = 0; i < myExplosions.size(); i++)
		{
			myExplosions[i]->draw(window);
		}
	
}

//Recursive
void EffectsManager::RemoveExplosion()
{
	for (int i=0; i < myExplosions.size(); i++)
	{
		if (myExplosions[i]->playExplode == false)
		{

			delete myExplosions[i];
			myExplosions.erase(std::remove(myExplosions.begin(), myExplosions.end(), myExplosions[i]));
			//remove it from list
			RemoveExplosion();
			return;
		}
	}
}