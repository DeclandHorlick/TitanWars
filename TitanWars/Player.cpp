#include "stdafx.h"

#include "Player.h"
#include "Block.h"
#include <vector> 
#include <iostream>
#ifdef _DEBUG
 #pragma comment(lib, "sfml-graphics-d.lib")
 #pragma comment(lib, "sfml-audio-d.lib")
 #pragma comment(lib, "sfml-system-d.lib")
 #pragma comment(lib, "sfml-window-d.lib")
 #pragma comment(lib, "sfml-network-d.lib")
 #else
 #pragma comment(lib, "sfml-graphics.lib")
 #pragma comment(lib, "sfml-audio.lib")
 #pragma comment(lib, "sfml-system.lib")
 #pragma comment(lib, "sfml-window.lib")
 #pragma comment(lib, "sfml-network.lib")
 #endif
 #pragma comment(lib, "opengl32.lib")
 #pragma comment(lib, "glu32.lib")
 #include "SFML/Graphics.hpp"
 #include <SFML/Window/Mouse.hpp>
 #include "SFML/OpenGL.hpp"

 #include <iostream>
 #include <string.h>

Player::Player(b2World &world, int width, int height)
{
	Rocket *rocket;
	//Define a b2body
	b2BodyDef bodyDef;
	//bodyDef.type = b2_staticBody;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2(20, 0);
	bodyDef.userData = this;
	//Ask the b2Worldto create our body
	boxBody = world.CreateBody(&bodyDef);
	int health = 200;

	//Define the shape of the body
	b2PolygonShape shape;
	shape.SetAsBox(width * 0.5f, height * 0.5f);
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &shape; // Sets the shape
	FixtureDef.userData = "Player";
	FixtureDef.restitution = 0.f;
	boxBody->CreateFixture(&FixtureDef); // Apply the fixture definition
	//boxBody->ApplyForce(velocity, bodyDef.position, true);
	m_width = width;
	m_height = height;
	//playerTexture.loadFromFile("godzilla.png");
	
	aimTexture.loadFromFile("aimer.png");
	playerSprite.setOrigin(34.5, 36);
	playerSprite.setTexture(playerTexture);
	aimSprite.setOrigin(-42.5, 0);
	aimSprite.setTexture(aimTexture);

	cWeaponTexture1.loadFromFile("bomb.png");
	cWeaponTexture2.loadFromFile("cmagic.png");
	cWeaponTexture3.loadFromFile("shotgun.png");

	playerSprite.setTextureRect(animationRect);
	//Define the graphical geometry of the player
	//sf::Vector2f Sprite = { boxBody->GetPosition().x - (width / 2), boxBody->GetPosition().y - (height / 2), width, height };
	rotation = aimSprite.getRotation();

	//sound
	
	// load something into the sound buffer...
	rocketBuffer.loadFromFile("rocketThrow.wav");
	
	rocketSound.setBuffer(rocketBuffer);
	
	
	
	
}
void Player::Draw(sf::RenderWindow &App,b2World &world)
{
	if (weaponSelected == 0)
	{
		cWeaponSprite.setTexture(cWeaponTexture1);
		cWeaponSprite.setPosition(40, 600);
	}
	else if (weaponSelected == 1)
	{
		cWeaponSprite.setTexture(cWeaponTexture2);
		cWeaponSprite.setPosition(40, 600);
	}
	else if (weaponSelected == 2)
	{
		cWeaponSprite.setTexture(cWeaponTexture3);
		cWeaponSprite.setPosition(40, 600);
	}
	if (_myTitan == "godzilla")
	{
		if (animationClock.getElapsedTime().asSeconds() > .25f)
		{
			if (animationRect.left >= 274)
				animationRect.left = 0;
			else
				animationRect.left += 69;

			playerSprite.setTextureRect(animationRect);
			animationClock.restart();
		}
	}
	else if (_myTitan == "kingkong")
	{
		if (animationClock.getElapsedTime().asSeconds() > .25f)
		{
			if (animationRect.left >= 366)
				animationRect.left = 0;
			else
				animationRect.left += 61;

			playerSprite.setTextureRect(animationRect);
			animationClock.restart();
		}
	}
	bodypos = boxBody->GetPosition();
	playerSprite.setPosition(sf::Vector2f(bodypos.x, bodypos.y));
	aimSprite.setPosition(sf::Vector2f(bodypos.x, bodypos.y));
	if (rotation < 270 && rotation > 0)
	{
		playerSprite.setScale(-1, 1);
		
	}
	else if (rotation >= 270 || rotation == 0)
	{
		playerSprite.setScale(1, 1);
		
	}
	
	App.draw(playerSprite);
	App.draw(aimSprite);
	App.draw(cWeaponSprite);
	int32 BodyIterator = world.GetBodyCount();
	std::cout << playerSprite.getPosition().x << "  " << playerSprite.getPosition().y << std::endl;
	//std::cout << BodyIterator << std::endl; //making sure theres 2 bodies
	//for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	//{
	//	if (BodyIterator->GetType() == b2_dynamicBody)
	//	{
	//		playerSprite.setTexture(playerTexture);
	//		playerSprite.setOrigin(16.f, 16.f);
	//		playerSprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
	//		playerSprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
	//		App.draw(playerSprite);
	//		std::cout << playerSprite.getPosition().x << "           " << playerSprite.getPosition().y << std::endl;
	//	}
	//}
}
void Player::SetTitan(sf::String &myTitan)
{
	_myTitan = myTitan;
	if (_myTitan == "godzilla")
	{
		animationRect = sf::IntRect(0, 0, 69, 72);
		playerTexture.loadFromFile("godzilla.png");
	}
	else
	{
		animationRect = sf::IntRect(0, 0, 61, 72);
		playerTexture.loadFromFile("kingkong.png");
	}
	playerSprite.setTexture(playerTexture);
	
}
sf::String Player::GetTitan()
{
	return _myTitan;
}
void Player::Update(sf::RenderWindow &App, b2World &world, Rocket *rocket)
{
	sf::Event Event;
	float xVelocity(5.6f);
	b2Vec2 yVelocity(0, 15);
	getVelocity = boxBody->GetLinearVelocity();
	
	

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (bodypos.x >= 10)
			{
				boxBody->SetLinearVelocity(b2Vec2(-xVelocity, boxBody->GetLinearVelocity().y));
				goingRight = false;
			}
			else
			{
								boxBody->SetLinearVelocity(b2Vec2(0, 0));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (bodypos.x <= 1190)
			{

				boxBody->SetLinearVelocity(b2Vec2(xVelocity, boxBody->GetLinearVelocity().y));
				goingRight = true;
			}
			else
			{
				boxBody->SetLinearVelocity(b2Vec2(0, 0));
			}
		}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		spaceReleased = false;
	}
	if (!spaceReleased && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

		//jumping = true;
		//boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -50));
		if (getVelocity.y == 0.f)
		{
 			boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -yVelocity.y));
		}
		spaceReleased = true;


	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		buttonRoleased = false;
		//rocket->setRocket(true);
	}
	if (!buttonReleased && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if (myRockets.size() == 0)
		{
			
			myRockets.push_back(new Rocket(1, 16, rotation, boxBody->GetPosition(), world));
			myRockets[0]->isRocketAlive();
//			
			rocketSound.play();
		}
		buttonRoleased = true;
		//playerTurn = false;
		
	}
	
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
	
		buttonReleased = false;
			
	}
	if (!buttonReleased && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		if (weaponSelected == 2)
		{
			weaponSelected = 0;
		}
		else
		{
			weaponSelected += 1;
		}
		buttonReleased = true;
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (rotation > 180 || rotation == 0)
			{
				aimSprite.rotate(-.25);
				rotation = aimSprite.getRotation();

			}
		}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
			if (rotation >= 180)
			{
				//aimSprite.setRotation(0);
				aimSprite.rotate(.25);
				rotation = aimSprite.getRotation();
			}


	}
}
int Player::setHealth(int lostHealth)
{
	health -= lostHealth;
	return health;
}
//void Player::onBeginContact(CollisionResponder* other) {
//	printf("++contact++");
//	if (dynamic_cast<Block*>(other)) {
//		touchingPlat = true;
//		
//		boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, 2.5));
//		
//	}
//}
//
//void Player::onEndContact(CollisionResponder* other) {
//	printf("--contact--");
//	if (dynamic_cast<Block*>(other))
//	{
//		touchingPlat = false;
//		boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, 2.5));
//		
//	}
//}
