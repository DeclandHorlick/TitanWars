#ifndef _LEVEL_H 
#define _LEVEL_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <Box2D/Box2D.h>
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "string.h"
#include "Block.h"
 

class Level {
private:

	static b2Body* levelBody;
	b2Body* levelBody2;
	b2Body* levelBody3;
	int m_width, m_height;
	
	//The final texture 
	static sf::Texture levelTexture;
	static sf::Sprite levelSprite;
	sf::Sprite level2Sprite;
	sf::Sprite level3Sprite;
	sf::Texture level2Texture;

	
	static std::vector<sf::Sprite> background; //class variables
	
	static sf::Texture texture; //class variables
	static const int SCALE;//class variable
	static int mylevel;
	static const int MAXLEVELS;
	std::vector<Block*> blocks;

	int currentLevel;

public:

	Level();
	//Level(b2World &world, int width, int height);
	//void Draw(sf::RenderWindow &App, b2World &world);
	~Level(){};

	
	static void LoadLevel(std::string name, std::string texturename, b2World &world);
	
	static void draw(sf::RenderWindow& window);
	static std::vector<std::string>loadALevelFromTextFile(std::string name);
	
	
	





};
#endif