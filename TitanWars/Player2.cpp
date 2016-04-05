#include "stdafx.h"

#include "Player2.h"
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

Player2::Player2(b2World &world, int width, int height)
{

	//Define a b2body
	b2BodyDef bodyDef;
	//bodyDef.type = b2_staticBody;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2(900, 300);
	bodyDef.userData = this;
	//Ask the b2Worldto create our body
	boxBody = world.CreateBody(&bodyDef);


	//Define the shape of the body
	b2PolygonShape shape;
	shape.SetAsBox(width * 0.5f, height * 0.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;  // Sets the density of the body
	FixtureDef.shape = &shape; // Sets the shape
	FixtureDef.userData = "Player";
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
	animationRect = sf::IntRect(0, 0, 85.5, 80);
	playerSprite.setTextureRect(animationRect);
	
	rotation = aimSprite.getRotation();

	//sound

	// load something into the sound buffer...
	rocketBuffer.loadFromFile("rocketThrow.wav");

	rocketSound.setBuffer(rocketBuffer);



}
void Player2::Draw(sf::RenderWindow &App, b2World &world)
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
	int32 BodyIterator = world.GetBodyCount();
	std::cout << playerSprite.getPosition().x << "  " << playerSprite.getPosition().y << std::endl;
	
}
void Player2::SetTitan(sf::String &myTitan)
{
	_myTitan = myTitan;
	if (_myTitan == "godzilla")
	{
		playerTexture.loadFromFile("godzilla.png");
	}
	else
	{
		playerTexture.loadFromFile("godzilla2.png");
	}
	playerSprite.setTexture(playerTexture);

}
void Player2::Update(sf::RenderWindow &App, b2World &world, Rocket *rocket)
{
	sf::Event Event;
	float xVelocity(5.6f);
	b2Vec2 yVelocity(0, 15);
	getVelocity = boxBody->GetLinearVelocity();


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		boxBody->SetLinearVelocity(b2Vec2(-xVelocity, boxBody->GetLinearVelocity().y));
		goingRight = false;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		boxBody->SetLinearVelocity(b2Vec2(xVelocity, boxBody->GetLinearVelocity().y));
		goingRight = true;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//rocket->setRocket(true);
		rocket->ApplyForceShotgun(boxBody->GetPosition(), rotation);
		rocketSound.play();

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