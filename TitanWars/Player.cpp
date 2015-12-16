#include "stdafx.h"

#include "Player.h"
#include "CollisionResponder.h"
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
	
	//Define a b2body
	b2BodyDef bodyDef;
	//bodyDef.type = b2_staticBody;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2(1.3f, 1);
	bodyDef.userData = this;
	//Ask the b2Worldto create our body
	boxBody = world.CreateBody(&bodyDef);
	

	//Define the shape of the body
	b2PolygonShape shape;
	shape.SetAsBox(width * 0.5f, height * 0.5f);
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &shape; // Sets the shape
	boxBody->CreateFixture(&FixtureDef); // Apply the fixture definition
	//boxBody->ApplyForce(velocity, bodyDef.position, true);
	m_width = width;
	m_height = height;
	playerTexture.loadFromFile("godzilla.png");
	aimTexture.loadFromFile("aimer.png");
	playerSprite.setOrigin(42.5, 40);
	playerSprite.setTexture(playerTexture);
	aimSprite.setOrigin(-42.5, 0);
	aimSprite.setTexture(aimTexture);
	animationRect = sf::IntRect(0, 0, 85, 80);
	aimSprite.setTextureRect(animationRect);
	//Define the graphical geometry of the player
	//sf::Vector2f Sprite = { boxBody->GetPosition().x - (width / 2), boxBody->GetPosition().y - (height / 2), width, height };
	rotation = aimSprite.getRotation();

	//sound
	
	// load something into the sound buffer...
	rocketBuffer.loadFromFile("rocketThrow.wav");
	
	rocketSound.setBuffer(rocketBuffer);
	
	getVelocity = boxBody->GetLinearVelocity();
	
}
void Player::Draw(sf::RenderWindow &App,b2World &world)
{
	if (animationClock.getElapsedTime().asSeconds() > .25f)
	{
		if (animationRect.left >= 560)
			animationRect.left = 0;
		else
			animationRect.left += 85.5;

		playerSprite.setTextureRect(animationRect);
		animationClock.restart();
	}
	b2Vec2 bodypos = boxBody->GetPosition();
	playerSprite.setPosition(sf::Vector2f(bodypos.x,bodypos.y));
	aimSprite.setPosition(sf::Vector2f(bodypos.x, bodypos.y));
	App.draw(playerSprite);
	App.draw(aimSprite);
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
void Player::Update(sf::RenderWindow &App, b2World &world, Rocket *rocket)
{
	sf::Event Event;
	float xVelocity(5.6f);
	b2Vec2 yVelocity(0, 15);
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		boxBody->SetLinearVelocity(b2Vec2(-xVelocity, boxBody->GetLinearVelocity().y));


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		boxBody->SetLinearVelocity(b2Vec2(xVelocity, boxBody->GetLinearVelocity().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
			//jumping = true;
			//boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -50));
		if (getVelocity.y == 0)
		{
			boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -yVelocity.y));
		}


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		//rocket->setRocket(true);
		rocket->ApplyForce(boxBody->GetPosition(), rotation);
		rocketSound.play();
	}
	if (sf::Event::KeyReleased)
	{
		if (sf::Keyboard::E)
		{
			
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (rotation > 270 || rotation == 0)
		{
			aimSprite.rotate(-.25);
			rotation = aimSprite.getRotation();
			
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (rotation >= 270 )
		{
			//aimSprite.setRotation(0);
			aimSprite.rotate(.25);
			rotation = aimSprite.getRotation();
		}
		
		
	}
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
