#include "stdafx.h"
#include "Rifle.h"


Rifle::Rifle(int owner, int width, float angle, b2Vec2 pos, b2World &m_world)
{
	//if (rocketAlive)
	//{
	m_owner = owner;
	//Player temp(m_world, width, height);
	m_width = width;
	rifleDeleted = false;
	rBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	//rBodyDef.position.Set(100, 100);
	rBodyDef.userData = this;

	rBodyDef.angle = 45; //set the starting angle
	

	rifleBody = m_world.CreateBody(&rBodyDef);
	rifleBody->SetUserData(this);
	//rShape.SetAsBox(width * 0.5f, height * 0.5f);
	//rFixtureDef.density = 0.f;  // Sets the density of the body

	//circular instead :)
	//rShapee.m_p.Set(0, 0);
	rShapee.m_radius = m_width;
	rFixtureDef.shape = &rShapee;
	rFixtureDef.userData = "Magic";
	rFixtureDef.density = .5f;
	rFixtureDef.restitution = 1.f;
	rifleBody->CreateFixture(&rFixtureDef);
	//rocketBody->CreateFixture(&rShapee, 0.0f);



	
	rifleTexture.loadFromFile("magic.png");
	rifleSprite.setOrigin(16, 16);
	rifleSprite.setTexture(rifleTexture);
	

	rifleBody->SetAngularVelocity(1);
	rifleBody->ApplyTorque(20, goRifle);
	goRifle = false;
	//}
	//if (goRocket == false)
	//{
	float distanceToAimer = 80.0f;
	float speed = 50;

	rifleBody->SetAwake(true);
	rifleBody->SetGravityScale(0);
	rifleBody->SetTransform(pos + (b2Vec2(cos(angle * DEG_TO_RAD)* distanceToAimer, sin(angle * DEG_TO_RAD)* distanceToAimer)), angle);
	rifleSprite.setRotation(angle);
	rifleBody->SetLinearVelocity(b2Vec2(cos(angle * DEG_TO_RAD)* speed, sin(angle * DEG_TO_RAD)* speed));	//Multiply by SPEED here
}


Rifle::~Rifle()
{
}
bool Rifle::isRifleDeleted()
{
	rifleDeleted = true;
	return rifleDeleted;
}
bool Rifle::isRifleAlive()
{
	rifleAlive = true;
	return rifleAlive;
}

void Rifle::Draw(sf::RenderWindow &window){
	if (!rifleDeleted)
	{
		b2Vec2 riflePos = rifleBody->GetPosition();
		rifleSprite.setPosition(sf::Vector2f(riflePos.x, riflePos.y));
		window.draw(rifleSprite);
	}
}

b2Vec2 Rifle::getPosition()
{
	riflePos = rifleBody->GetPosition();
	return riflePos;
}
b2Body* Rifle::getBody()
{
	return rifleBody;
}