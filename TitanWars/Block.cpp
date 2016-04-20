#include "stdafx.h"
#include "Block.h"

Block::Block()
{
}
Block::Block(b2Vec2 position, int width, int height, b2World &m_world, sf::Sprite* sprite)
{
	this->sprite = *sprite;
	
	//b2BodyDef myBodyDef;
	blockDeleted = false;
	myBodyDef.type = b2_staticBody; //this will be a static body
	myBodyDef.position.Set(position.x, position.y);
	//myBodyDef.position = b2Vec2((position.x + width*0.5f), (position.y + height*0.5f)); //set the starting position
	myBodyDef.angle = 0; //set the starting angle
	myBodyDef.userData = this;

	blockBody = m_world.CreateBody(&myBodyDef);
	blockBody->SetUserData(this);
	//Define the shape 
	//b2PolygonShape shape;
	myShape.SetAsBox(width * 0.5f, height * 0.5f);
	
	myBodyFixtureDef.density = 0.f;  // Sets the density of the body
	myBodyFixtureDef.restitution = 0.f;
	myBodyFixtureDef.shape = &myShape; // Sets the shape
	myBodyFixtureDef.userData = "Block";
	blockBody->CreateFixture(&myBodyFixtureDef); // Apply the fixture definition

	//blockBody->CreateFixture(&myBodyFixtureDef, 0.0f);

	//Define the graphical geometry of the platfrom
	
	World = &m_world;
}

Block::~Block()
{
	if (!blockDeleted)
	World->DestroyBody(blockBody);

}
void Block::Draw(sf::RenderWindow &window){
	if (!blockDeleted)
	{
		window.draw(sprite);
	}
	else
	{
//		int* myDick = new int (50);
	}
}
bool Block::BoxDeleted()
{
	blockDeleted = true;
	return blockDeleted;
}
//void Block::onBeginContact(CollisionResponder* other) {
//}
//
//void Block::onEndContact(CollisionResponder* other) {
//}

