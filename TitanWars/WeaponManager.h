#ifndef  _WEAPONMANAGER_H
#define _WEAPONMANAGER_H


#include <Box2D/Box2D.h>
#include "SFML\Graphics.hpp"
#include "SFML/OpenGL.hpp"



class WeaponManager
{
private:

public:
	WeaponManager();
	void createBomb(int height, int width, b2World &m_world);
	void createBreath(b2Vec2 pos, float angle);
	void createStone(sf::RenderWindow &window);


};
#endif;