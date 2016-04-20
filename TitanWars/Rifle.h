#ifndef _RIFLE_H
#define _RIFLE_H

#include <Box2D/Box2D.h>
#include "SFML\Graphics.hpp"
#include "SFML/OpenGL.hpp"



class Rifle
{
private:
	b2Body *rifleBody;
	b2BodyDef rBodyDef;
	b2FixtureDef rFixtureDef;
	//b2PolygonShape rShape;
	b2CircleShape rShapee;

	b2Vec2 riflePos;
	int m_width, m_height;
	sf::Sprite rifleSprite;
	sf::Texture rifleTexture;

	sf::Sprite ExplsionS;
	sf::Texture ExplosionT;


	bool goRifle = false;
	sf::Clock animationClock;
	sf::IntRect animationRect;


public:
	Rifle(int owner, int width, float angle, b2Vec2 pos, b2World &m_world);
	b2Vec2 getPosition();
	
	void Draw(sf::RenderWindow &window);
	void DrawExplosion(sf::RenderWindow &window);
	int m_owner;
	bool rifleDeleted;
	bool rifleAlive = false;
	bool playAnimation = false;
	b2Body* getBody();
	
	bool isRifleDeleted();
	bool isRifleAlive();

	~Rifle();



};
#endif;