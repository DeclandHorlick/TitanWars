#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#ifndef CSCREEN_H
#define CSCREEN_H
class cScreen
{
public:
	virtual int Run(sf::RenderWindow &App, b2World &world) = 0;
};

#endif