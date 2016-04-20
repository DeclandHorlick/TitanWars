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

	b2Vec2 rocketPos;
	int m_width, m_height;
	sf::Sprite rocketSprite;
	sf::Texture rocketTexture;

	sf::Sprite ExplsionS;
	sf::Texture ExplosionT;

	
	bool goRocket = false;
	sf::Clock animationClock;
	sf::IntRect animationRect;


public:
	Rocket(int owner, int width, float angle, b2Vec2 pos, b2World &m_world,float myPower);
	b2Vec2 getPosition();
	void ApplyForceShotgun(b2Vec2 pos, float angle);
	void Draw(sf::RenderWindow &window);
	void DrawExplosion(sf::RenderWindow &window);
	int m_owner;
	bool rocketDeleted;
	bool rocketAlive = false;
	bool playAnimation = false;
	b2Body* getBody();
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