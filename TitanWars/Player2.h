#ifndef _PLAYER2_H 
#define _PLAYER2_H

#include <Box2D/Box2D.h>

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "SFML/Audio.hpp"
#include "Rocket.h"

class Player2 {
private:
	b2Body* boxBody;
	int m_width, m_height;
	int weaponSelected = 0;
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
	bool goingRight = true;
	Rocket *rocket;
	sf::String _myTitan;
	sf::IntRect animationRect;

	sf::Sprite cWeaponSprite;
	sf::Texture cWeaponTexture1;
	sf::Texture cWeaponTexture2;
	sf::Texture cWeaponTexture3;

	sf::Sprite powerSprite;
	sf::Texture powerTexture;

	bool buttonReleased;
	bool buttonRoleased;
	b2Vec2 bodypos;

	int health = 200;

public:
	//Rocket *rocket;
	bool touchingPlat;
	Player2(b2World &world, int width, int height);
	void Draw(sf::RenderWindow &App, b2World &world);
	void Update(sf::RenderWindow &App, b2World &world, Rocket *rocket);
	void SetTitan(sf::String &myTitan);
	sf::String GetTitan();
	~Player2(){}
	std::vector<Rocket*> myRockets;
	bool player2Turn = false;
	int getHealth();
	int setHealth(int lostHealth);
	/*void onBeginContact(CollisionResponder* other)override ;
	void onEndContact(CollisionResponder* other)override ;
	*/





};
#endif