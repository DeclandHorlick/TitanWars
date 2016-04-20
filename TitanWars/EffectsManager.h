#pragma once
#include "Explosion.h"

class EffectsManager
{
public:
	
	
	void addExplosion(b2Vec2 pos);
	void update();
	void draw(sf::RenderWindow &window);
	void reset();
	static EffectsManager* GetInstance();


	~EffectsManager()
	{
		instanceFlag = false;
	}

private:
	std::vector<Explosion*> myExplosions;
	EffectsManager()
	{

	}
	void RemoveExplosion();
	static bool instanceFlag;
	static EffectsManager* instance;
};

