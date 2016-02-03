#ifndef _BLOCK_H
#define _BLOCK_H

#include <Box2D/Box2D.h>
#include "SFML\Graphics.hpp"
#include "SFML/OpenGL.hpp"


class Block  {
protected:
	b2Body* blockBody;
	int SCALE = 32;
	b2Body* myBody;
	b2BodyDef myBodyDef;
	b2FixtureDef myBodyFixtureDef;
	b2PolygonShape myShape;
	

	sf::Texture myTexture;
	sf::Sprite sprite;
	
public:
	Block();
	Block(b2Vec2 position, int width, int height, b2World &m_world, sf::Texture &texture);
	~Block();
	void Draw(sf::RenderWindow &window);
	bool BoxDeleted();
	bool blockDeleted;
	/*void onBeginContact(CollisionResponder* other)override;
	void onEndContact(CollisionResponder* other)override;
	*/
};
#endif