#include "stdafx.h"
#include "Rocket.h"


Rocket::Rocket( int width, int height, b2World &m_world)
{
	//Player temp(m_world, width, height);
	
	rBodyDef.type = b2_dynamicBody; //this will be a dynamic body
	rBodyDef.position.Set(100, 100);
	rBodyDef.userData = this;
	
	rBodyDef.angle = 45; //set the starting angle
	

	rocketBody = m_world.CreateBody(&rBodyDef);
	//rShape.SetAsBox(width * 0.5f, height * 0.5f);
	//rFixtureDef.density = 0.f;  // Sets the density of the body

	//circular instead :)
	rShapee.m_p.Set(0, 0);
	rShapee.m_radius = 16; 
	rFixtureDef.shape = &rShapee; 
	rFixtureDef.userData = "Rocket";
	rFixtureDef.density = 0.f;
	rocketBody->CreateFixture(&rFixtureDef);
	//rocketBody->CreateFixture(&rShapee, 0.0f);
	

	m_width = width;
	m_height = height;

	rocketTexture.loadFromFile("Rocket.png");
	rocketSprite.setOrigin(16, 16);
	rocketSprite.setTexture(rocketTexture);
}
Rocket::~Rocket()
{
}
void Rocket::Draw(sf::RenderWindow &window){
	b2Vec2 rocketPos = rocketBody->GetPosition();
	rocketSprite.setPosition(sf::Vector2f(rocketPos.x, rocketPos.y));
	window.draw(rocketSprite);
}

void Rocket::ApplyForce(b2Vec2 pos, float angle)
{
	if (goRocket == true)
	{
		//rocketBody->SetLinearVelocity(b2Vec2(10, 10));
		/*rocketBody->GetAngularVelocity();
		rocketBody->SetLinearVelocity(new b2Vec2(force * Math.cos(angle),force * Math.sin(angle)));
		rocketBody->SetAngle(angle);
		rockteBody->SetAngularDamping(1.5);*/

		rocketBody->SetAngularVelocity(1);
		rocketBody->ApplyTorque(20, goRocket);
		goRocket = false;
	}
	if (goRocket == false)
	{
		float distanceToAimer = 100.0f;
		float speed = 50;
		rocketBody->SetAwake(true);
		rocketBody->SetGravityScale(3);
		rocketBody->SetTransform(pos + (b2Vec2(cos(angle * DEG_TO_RAD)* distanceToAimer, sin(angle * DEG_TO_RAD)* distanceToAimer)), angle);
		rocketSprite.setRotation(angle);
		rocketBody->SetLinearVelocity(b2Vec2(cos(angle * DEG_TO_RAD)* speed, sin(angle * DEG_TO_RAD)* speed));	//Multiply by SPEED here

	}
}
void Rocket::ApplyForceShotgun(b2Vec2 pos, float angle)
	{
		if (goRocket == true)
		{
			//rocketBody->SetLinearVelocity(b2Vec2(10, 10));
			/*rocketBody->GetAngularVelocity();
			rocketBody->SetLinearVelocity(new b2Vec2(force * Math.cos(angle),force * Math.sin(angle)));
			rocketBody->SetAngle(angle);
			rockteBody->SetAngularDamping(1.5);*/

			rocketBody->SetAngularVelocity(1);
			rocketBody->ApplyTorque(20, goRocket);
			goRocket = false;
		}
		if (goRocket == false)
		{
			float distanceToAimer = 100.0f;
			float speed = 100;
			rocketBody->SetAwake(true);
			rocketBody->SetGravityScale(0);
			rocketBody->SetTransform(pos + (b2Vec2(cos(angle * DEG_TO_RAD)* distanceToAimer, sin(angle * DEG_TO_RAD)* distanceToAimer)), angle);
			rocketSprite.setRotation(angle);
			rocketBody->SetLinearVelocity(b2Vec2(cos(angle * DEG_TO_RAD)* speed, sin(angle * DEG_TO_RAD)* speed));	//Multiply by SPEED here

		}
	
}