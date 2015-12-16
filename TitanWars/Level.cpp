#include "stdafx.h"

#include "Level.h"
#include <vector> 
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Window/Mouse.hpp>
#include "SFML/OpenGL.hpp"
#include <iostream>
#include <string.h>
#include "BlockManager.h"
//eventually this level class will be loaded from a BMP/Text file creating a level of box2D bodies that can be destroyed
using namespace std;
#include "Level.h"



std::vector<sf::Sprite> Level::background(0);
//std::vector<int> Level::bestTimes(0);
const int Level::SCALE = 32;
//const int Level::MAXLEVELS = 5;
int Level::currentlevel = 0;
sf::Texture Level::texture;


Level::Level()
{
	currentlevel = 0;
}
//void  Level::reloadlevel()
//{
//	BoxManager::clearAll();
//	RopeManager::RemoveRopes();
//	string levelnames[] = { "Level1.txt", "Level2.txt", "Level3.txt", "Level4.txt", "Level5.txt" };
//	string leveltexturenames[] = { "myTextures3.png", "myTextures4.png", "myTextures5.png", "myTextures5.png", "myTextures7.png" };
//	string enemylevelnames[] = { "Level1_Enemies.txt", "Level2_Enemies.txt", "Level3_Enemies.txt", "Level4_Enemies.txt", "Level5_Enemies.txt" };
//	LoadLevel(levelnames[currentlevel], leveltexturenames[currentlevel]);
//	EnemyManager::LoadFromMap(enemylevelnames[currentlevel]);
//	RopeManager::addRope(currentlevel);
//	gameClock::clock.restart();
//}

// a load level method inside 
void Level::LoadLevel(string name, string texturename , b2World &world)
{
	background.clear();
	vector<string> map = Level::loadALevelFromTextFile(name);
	const int mapX = 30;
	const int mapY = 20;
	sf::Sprite temp;

	if (!texture.loadFromFile(texturename))//"myTextures3.png"
	{
		cout << "image did not load" << endl;
	}

	int noOfSpritesOnX = 10;
	/*if ("Level5.txt" == name)
	{
		noOfSpritesOnX = 10;
	}*/
	const int noOfSpritesOnY = 1;
	/*sf::Vector2u size = texture.getSize();
	float xscale = SCALE / (float)size.x;
	float yscale = SCALE / (float)size.y;*/
	//temp.setScale(sf::Vector2f(xscale * noOfSpritesOnX, yscale * noOfSpritesOnY));
	temp.setOrigin(16, 16);
	temp.setTexture(texture);
	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			char c = (char)map[y][x];
			//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));

			
			if (c == 'F')
			{
				
				/*b2BodyDef levelBodyDef;
				levelBodyDef.type = b2_staticBody;*/
				temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				//temp.setTextureRect(sf::IntRect(0 * SCALE, 0, SCALE, SCALE));
				//blocks.push_back(new Block(b2Vec2(1, 1), SCALE, SCALE, world));
				BlockManager::addBlock(x * SCALE, y * SCALE, SCALE, SCALE,world,texture);
				//b2PolygonShape levelShape;
				//levelShape.SetAsBox(SCALE* 0.5f, SCALE * 0.5f);
				//levelBody = world.CreateBody(&levelBodyDef);
				//b2FixtureDef levelFixtureDef
				//levelFixtureDef.density = 0.f;  // Sets the density of the body
				//levelFixtureDef.shape = &levelShape; // Sets the shape
				//levelBody->CreateFixture(&levelFixtureDef); // Apply the fixture definition
				//levelTexture.loadFromFile("Level.png");
				//
				//levelSprite.setTexture(levelTexture);

			}
			/*if (c == 'h')
			{
				temp.setTextureRect(sf::IntRect(1 * SCALE, 0, SCALE, SCALE));

			}
			if (c == 'L')
			{

				temp.setTextureRect(sf::IntRect(3 * SCALE, 0, SCALE, SCALE));
				BoxManager::addLadder(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 'F')
			{

				temp.setTextureRect(sf::IntRect(2 * SCALE, 0, SCALE, SCALE));
				BoxManager::addFloor(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 'C')
			{

				temp.setTextureRect(sf::IntRect(4 * SCALE, 0, SCALE, SCALE));
				BoxManager::addChest(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 'H')
			{

				temp.setTextureRect(sf::IntRect(5 * SCALE, 0, SCALE, SCALE));
				BoxManager::addChest(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 't')
			{
				temp.setTextureRect(sf::IntRect(6 * SCALE, 0, SCALE, SCALE));

			}
			if (c == 'X')
			{
				temp.setTextureRect(sf::IntRect(8 * SCALE, 0, SCALE, SCALE));
				BoxManager::addFloor(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 'P')
			{
				temp.setTextureRect(sf::IntRect(6 * SCALE, 0, SCALE, SCALE));
				BoxManager::addFloor(x * SCALE, y*SCALE, SCALE, SCALE);
			}
			if (c == 'Y')
			{
				temp.setTextureRect(sf::IntRect(2 * SCALE, 0, SCALE, SCALE));
			}
			if (c == 'A')
			{
				temp.setTextureRect(sf::IntRect(9 * SCALE, 0, SCALE, SCALE));
				BoxManager::addHook(x * SCALE, y*SCALE, SCALE, SCALE);
			}*/
			background.push_back(temp);

		}
	}
}


//inside the main while loop
//in a cpp file  put this inside a draw method that takes (sf::RenderWindow& Window)  as its arguements
//bool  Level::islevelAvaliable(int i)
//{
//	if (i == 0)
//	{
//		return true;
//	}
//	else if (bestTimes[i - 1] > 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
void Level::draw(sf::RenderWindow& Window)
{
	for (int i = 0; i < background.size(); i++)
	{
		Window.draw(background[i]);
	}




}
vector<string> Level::loadALevelFromTextFile(string name)
{
	vector<string > mystringvector;
	ifstream myfile;
	myfile.open(name);
	string c = "";
	while (myfile >> c)
	{
		mystringvector.push_back(c);
	}

	myfile.close();
	return mystringvector;
}

