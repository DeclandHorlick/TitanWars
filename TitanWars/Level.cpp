#include "stdafx.h"

#include "Level.h"
#include <vector> 
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window/Mouse.hpp>
#include "SFML/OpenGL.hpp"
#include <iostream>
#include <string.h>

Level::Level(b2World &world, int width, int height)
{
	
	//Define a b2body
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(0, 600);
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
	levelTexture.loadFromFile("Level.png");
	levelSprite.setOrigin(16.f, 16.f);
	levelSprite.setTexture(levelTexture);
	//Define the graphical geometry of the player
	//sf::Vector2f Sprite = { boxBody->GetPosition().x - (width / 2), boxBody->GetPosition().y - (height / 2), width, height };

	//Set this player's handleKey methods to be the ones called by the input manager

	//xBody->SetGravityScale(0.f);

}
void Level::Draw(sf::RenderWindow &App, b2World &world)
{
	b2Vec2 bodypos = boxBody->GetPosition();
	levelSprite.setPosition(sf::Vector2f(SCALE*bodypos.x, SCALE*bodypos.y));
	App.draw(levelSprite);
}