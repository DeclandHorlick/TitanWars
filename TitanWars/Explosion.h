#pragma once
#include "Box2D\Box2D.h"
#include "SFML/Graphics.hpp" 


class Explosion
{
public:
	Explosion(b2Vec2 pos);
	void draw(sf::RenderWindow &window);
	~Explosion();
	bool playExplode;

private:
	sf::Sprite explosionS;
	sf::Texture explosionT;
	sf::Clock animationClock;
	sf::IntRect animationRect = sf::IntRect(0, 0, 64, 64);
	
};

