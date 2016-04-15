#ifndef _ROCKET_H
#define _ROCKET_H

#include <Box2D/Box2D.h>
#include "SFML\Graphics.hpp"
#include "SFML/OpenGL.hpp"



class Rocket
{
private:
	b2Body *rocketBody;
	b2BodyDef rBodyDef;
	b2FixtureDef rFixtureDef;
	//b2PolygonShape rShape;
	b2CircleShape rShapee;
	int m_width, m_height;
	sf::Sprite rocketSprite;
	sf::Texture rocketTexture;
	bool goRocket = false;
	


public:
	Rocket(int owner, int width, float angle, b2Vec2 pos, b2World &m_world);
	void ApplyForce(b2Vec2 pos, float angle);
	void ApplyForceShotgun(b2Vec2 pos, float angle);
	void Draw(sf::RenderWindow &window);
	int m_owner;
	bool rocketDeleted;
	bool rocketAlive = false;

	/*void setRocket(bool tempGo)
	{
		goRocket = tempGo;
	}
	*/
	bool isRocketDeleted();
	bool isRocketAlive();
	
	~Rocket();

	

};
#endif;