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
const int Level::SCALE = 16;
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
	vector<string> map = Level::loadALevelFromTextFile(name);
	const int mapX = 60;
	const int mapY = 40;
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
			temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));

			
			if (c == 'C')
			{
				
				/*DIFFERENT CHARACTERS SPAN DIFFERENT TEXTURE SPRITES*/
				temp.setTextureRect(sf::IntRect(0 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);
				

			}
			if (c == 'G')
			{
				temp.setTextureRect(sf::IntRect(1 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);

			}
			if (c == 'S')
			{

				temp.setTextureRect(sf::IntRect(2 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);
			}
			if (c == 'K')
			{

				temp.setTextureRect(sf::IntRect(3 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);
			}
			if (c == 'R')
			{

				temp.setTextureRect(sf::IntRect(4 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);
			}
			if (c == 'F')
			{

				temp.setTextureRect(sf::IntRect(5 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);
			}
			if (c == 'L')
			{
				temp.setTextureRect(sf::IntRect(6 * SCALE, 0, SCALE, SCALE));
				//temp.setPosition((sf::Vector2f(x * SCALE, y * SCALE)));
				BlockManager::GetInstance()->addBlock(x * SCALE, y * SCALE, SCALE, SCALE, world, &temp);

			}
		}
	}
}



void Level::draw(sf::RenderWindow& Window)
{
	BlockManager::GetInstance()->Draw(Window);
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

