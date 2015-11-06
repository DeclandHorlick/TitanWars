#include "stdafx.h"

#include "Player.h"
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
	playerTexture.loadFromFile("Player.png");
	playerSprite.setOrigin(40, 40);
	playerSprite.setTexture(playerTexture);
	//Define the graphical geometry of the player
	//sf::Vector2f Sprite = { boxBody->GetPosition().x - (width / 2), boxBody->GetPosition().y - (height / 2), width, height };
	
	
}
void Player::Draw(sf::RenderWindow &App,b2World &world)
{
	b2Vec2 bodypos = boxBody->GetPosition();
	playerSprite.setPosition(sf::Vector2f(SCALE*bodypos.x,SCALE*bodypos.y));
	App.draw(playerSprite);
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
void Player::Update(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	float xVelocity(.6f);
	b2Vec2 yVelocity(0, 1);
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		
		boxBody->SetLinearVelocity(b2Vec2(-xVelocity, world.GetGravity().y)); 
		
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		boxBody->SetLinearVelocity(b2Vec2(xVelocity, world.GetGravity().y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
		boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -1));
	}
				
	
}
