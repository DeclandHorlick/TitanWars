#pragma once

#include <Box2D/Box2D.h>
#include "SFML\Graphics.hpp"
#include "SFML/OpenGL.hpp"


class Car
{
private:
	b2Body *carBody;
	b2BodyDef rBodyDef;
	b2FixtureDef rFixtureDef;
	//b2PolygonShape rShape;
	b2CircleShape rShapee;

	b2Vec2 carPos;
	int m_width, m_height;
	sf::Sprite carSprite;
	sf::Texture carTexture;




	bool goCar = false;

public:
	Car(int owner, int width, float angle, b2Vec2 pos, b2World &m_world, float myPower);

	b2Vec2 getPosition();
	void Draw(sf::RenderWindow &window);
	int m_owner;
	bool carDeleted;
	bool carAlive = false;
	bool playAnimation = false;
	b2Body* getBody();

	bool isCarDeleted();
	bool isCarAlive();
	~Car();
};

