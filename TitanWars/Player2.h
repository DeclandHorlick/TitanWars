#ifndef _PLAYER2_H 
#define _PLAYER2_H
#include "CollisionResponder.h"

#include <Box2D/Box2D.h>

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "SFML/Audio.hpp"
#include "Rocket.h"

class Player2 {
private:
	b2Body* boxBody;
	int m_width, m_height;
	sf::Sprite playerSprite;
	//The final texture 
	sf::Texture playerTexture;
	sf::Sprite aimSprite;
	sf::Texture aimTexture;
	float rotation;
	const float SCALE = 30.f;
	bool force;
	bool jumping;
	sf::SoundBuffer rocketBuffer;//create buffer
	sf::Sound rocketSound;
	sf::Clock animationClock;
	b2Vec2 getVelocity;
public:
	//Rocket *rocket;
	bool touchingPlat;
	Player2(b2World &world, int width, int height);
	void Draw(sf::RenderWindow &App, b2World &world);
	void Update(sf::RenderWindow &App, b2World &world, Rocket *rocket);
	~Player2(){}
	sf::IntRect animationRect;
	/*void onBeginContact(CollisionResponder* other)override ;
	void onEndContact(CollisionResponder* other)override ;
	*/





};
#endif