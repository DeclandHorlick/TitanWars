#ifndef _LEVEL_H 
#define _LEVEL_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <Box2D/Box2D.h>

class Level {
private:
	b2Body* boxBody;
	int m_width, m_height;
	sf::Sprite levelSprite;
	//The final texture 
	sf::Texture levelTexture;
	const float SCALE = 30.f;

public:
	Level(b2World &world, int width, int height);
	void Draw(sf::RenderWindow &App, b2World &world);
	~Level(){}






};
#endif