#ifndef _LEVEL_H 
#define _LEVEL_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <Box2D/Box2D.h>

class Level {
private:
	b2Body* levelBody;
	b2Body* levelBody2;
	b2Body* levelBody3;
	int m_width, m_height;
	
	//The final texture 
	sf::Texture levelTexture;
	sf::Sprite levelSprite;
	sf::Sprite level2Sprite;
	sf::Sprite level3Sprite;
	sf::Texture level2Texture;
	const float SCALE = 30.f;

public:
	Level(b2World &world, int width, int height);
	void Draw(sf::RenderWindow &App, b2World &world);
	~Level(){}






};
#endif