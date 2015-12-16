#include "stdafx.h"
#include "Block.h"

Block::Block()
{
}
Block::Block(b2Vec2 position, int width, int height, b2World &m_world, sf::Texture &texture)
{
	//sprite.setTexture(texture);

	//b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody; //this will be a static body
	myBodyDef.position.Set(position.x, position.y);
	//myBodyDef.position = b2Vec2((position.x + width*0.5f), (position.y + height*0.5f)); //set the starting position
	myBodyDef.angle = 0; //set the starting angle
	myBodyDef.userData = this;

	blockBody = m_world.CreateBody(&myBodyDef);
	//Define the shape 
	//b2PolygonShape shape;
	myShape.SetAsBox(width * 0.5f, height * 0.5f);
	blockBody->CreateFixture(&myShape, 0.0f);
//	sprite.setOrigin(width*0.5f, height*0.5f);

	//Define the graphical geometry of the platfrom
	

}

Block::~Block()
{
}
void Block::Draw(sf::RenderWindow &window){

	window.draw(sprite);
}
//void Block::onBeginContact(CollisionResponder* other) {
//}
//
//void Block::onEndContact(CollisionResponder* other) {
//}

