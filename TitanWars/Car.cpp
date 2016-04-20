#include "stdafx.h"
#include "Car.h"


Car::Car(int owner, int width, float angle, b2Vec2 pos, b2World &m_world, float myPower)
{
	//if (rocketAlive)
	//{
	m_owner = owner;
	//Player temp(m_world, width, height);
	m_width = width;
	carDeleted = false;
	rBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	//rBodyDef.position.Set(100, 100);
	rBodyDef.userData = this;

	rBodyDef.angle = 45; //set the starting angle


	carBody = m_world.CreateBody(&rBodyDef);
	carBody->SetUserData(this);
	//rShape.SetAsBox(width * 0.5f, height * 0.5f);
	//rFixtureDef.density = 0.f;  // Sets the density of the body

	//circular instead :)
	
	rShapee.m_radius = m_width;
	rFixtureDef.shape = &rShapee;
	rFixtureDef.userData = "Car";
	rFixtureDef.density = 1.f;
	rFixtureDef.restitution = 1.f;
	carBody->CreateFixture(&rFixtureDef);
	
	carTexture.loadFromFile("carnow.png");
	carSprite.setOrigin(16, 16);
	carSprite.setTexture(carTexture);
	
	carBody->ApplyTorque(20, goCar);
	goCar = false;
	
	
	float distanceToAimer = 100.0f;
	float speed = myPower;
	carBody->SetAwake(true);
	carBody->SetGravityScale(3);
	carBody->SetTransform(pos + (b2Vec2(cos(angle * DEG_TO_RAD)* distanceToAimer, sin(angle * DEG_TO_RAD)* distanceToAimer)), angle);
	carSprite.setRotation(angle);
	carBody->SetLinearVelocity(b2Vec2(cos(angle * DEG_TO_RAD)* speed, sin(angle * DEG_TO_RAD)* speed));	//Multiply by SPEED here
	
	//}
	//}
}
Car::~Car()
{
}
bool Car::isCarDeleted()
{
	carDeleted = true;
	return carDeleted;
}
bool Car::isCarAlive()
{
	carAlive = true;
	return carAlive;
}

void Car::Draw(sf::RenderWindow &window){
	if (!carDeleted)
	{
		b2Vec2 carPos = carBody->GetPosition();
		carSprite.setPosition(sf::Vector2f(carPos.x, carPos.y));
		window.draw(carSprite);
	}
}



b2Vec2 Car::getPosition()
{
	carPos = carBody->GetPosition();
	return carPos;
}
b2Body* Car::getBody()
{
	return carBody;
}



