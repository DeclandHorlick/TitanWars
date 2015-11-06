#include "stdafx.h"

#include "Level.h"
#include <vector> 
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window/Mouse.hpp>
#include "SFML/OpenGL.hpp"
#include <iostream>
#include <string.h>
//eventually this level class will be loaded from a BMP/Text file creating a level of box2D bodies that can be destroyed
Level::Level(b2World &world, int width, int height)
{
	
	//Define a b2body
	b2BodyDef levelBodyDef;
	levelBodyDef.type = b2_staticBody;
	levelBodyDef.position = b2Vec2(13.333f, 18.3);
	levelBodyDef.userData = this;

	b2BodyDef levelBodyDef2;
	levelBodyDef2.type = b2_staticBody;
	levelBodyDef2.position = b2Vec2(26, 15);
	levelBodyDef2.userData = this;

	b2BodyDef levelBodyDef3;
	levelBodyDef3.type = b2_staticBody;
	levelBodyDef3.position = b2Vec2(34, 11.7);
	levelBodyDef3.userData = this;


	//Ask the b2Worldto create our body
	levelBody = world.CreateBody(&levelBodyDef);
	levelBody2 = world.CreateBody(&levelBodyDef2);
	levelBody3 = world.CreateBody(&levelBodyDef3);

	//Define the shape of the body
	b2PolygonShape levelShape;
	levelShape.SetAsBox(width * 0.5f, height * 0.5f);
	b2PolygonShape levelShape2;
	levelShape2.SetAsBox(width * 0.5f, height * 0.5f);
	b2PolygonShape levelShape3;
	levelShape3.SetAsBox(width * 0.5f, height * 0.5f);

	b2FixtureDef levelFixtureDef;
	levelFixtureDef.density = 0.f;  // Sets the density of the body
	levelFixtureDef.shape = &levelShape; // Sets the shape
	levelBody->CreateFixture(&levelFixtureDef); // Apply the fixture definition

	b2FixtureDef level2FixtureDef;
	level2FixtureDef.density = 0.f;  
	level2FixtureDef.shape = &levelShape; // Sets the shape
	levelBody2->CreateFixture(&level2FixtureDef);

	b2FixtureDef level3FixtureDef;
	level3FixtureDef.density = 0.f;
	level3FixtureDef.shape = &levelShape; // Sets the shape
	levelBody3->CreateFixture(&level2FixtureDef);

	//boxBody->ApplyForce(velocity, bodyDef.position, true);
	m_width = width;
	m_height = height;
	levelTexture.loadFromFile("Level.png");

	levelSprite.setOrigin(450, 50);
	level2Sprite.setOrigin(450, 50);
	level3Sprite.setOrigin(450, 50);

	levelSprite.setTexture(levelTexture);
	level2Sprite.setTexture(levelTexture);
	level3Sprite.setTexture(levelTexture);
	

	

}
void Level::Draw(sf::RenderWindow &App, b2World &world)
{
	b2Vec2 levelBodypos = levelBody->GetPosition();
	b2Vec2 level2Bodypos = levelBody2->GetPosition();
	b2Vec2 level3Bodypos = levelBody3->GetPosition();
	levelSprite.setPosition(sf::Vector2f(SCALE*levelBodypos.x, SCALE*levelBodypos.y));
	level2Sprite.setPosition(sf::Vector2f(SCALE*level2Bodypos.x, SCALE*level2Bodypos.y));
	level3Sprite.setPosition(sf::Vector2f(SCALE*level3Bodypos.x, SCALE*level3Bodypos.y));
	App.draw(levelSprite);
	App.draw(level2Sprite);
	App.draw(level3Sprite);
	
}