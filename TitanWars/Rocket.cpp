#include "stdafx.h"
#include "Rocket.h"


Rocket::Rocket(int owner, int width, float angle,b2Vec2 pos, b2World &m_world, float myPower)
{
	//if (rocketAlive)
	//{
		m_owner = owner;
		//Player temp(m_world, width, height);
		m_width = width;
		rocketDeleted = false;
		rBodyDef.type = b2_dynamicBody; //this will be a dynamic body
		//rBodyDef.position.Set(100, 100);
		rBodyDef.userData = this;

		rBodyDef.angle = 45; //set the starting angle


		rocketBody = m_world.CreateBody(&rBodyDef);
		rocketBody->SetUserData(this);
		//rShape.SetAsBox(width * 0.5f, height * 0.5f);
		//rFixtureDef.density = 0.f;  // Sets the density of the body

		//circular instead :)
		//rShapee.m_p.Set(0, 0);
		rShapee.m_radius = m_width;
		rFixtureDef.shape = &rShapee;
		rFixtureDef.userData = "Rocket";
		rFixtureDef.density = .1f;
		rFixtureDef.restitution = .3f;
		rocketBody->CreateFixture(&rFixtureDef);
		//rocketBody->CreateFixture(&rShapee, 0.0f);



		//if (goRocket == true)
		//{
		rocketTexture.loadFromFile("Rocket.png");
		rocketSprite.setOrigin(16, 16);
		rocketSprite.setTexture(rocketTexture);
		//rocketBody->SetLinearVelocity(b2Vec2(10, 10));
		/*rocketBody->GetAngularVelocity();
		rocketBody->SetLinearVelocity(new b2Vec2(force * Math.cos(angle),force * Math.sin(angle)));
		rocketBody->SetAngle(angle);
		rockteBody->SetAngularDamping(1.5);*/
		
		//rocketBody->SetAngularVelocity(1);
		rocketBody->ApplyTorque(20, goRocket);
		goRocket = false;
		//}
		//if (goRocket == false)
		//{
		float distanceToAimer = 100.0f;
		float speed = myPower;
		rocketBody->SetAwake(true);
		rocketBody->SetGravityScale(3);
		rocketBody->SetTransform(pos + (b2Vec2(cos(angle * DEG_TO_RAD)* distanceToAimer, sin(angle * DEG_TO_RAD)* distanceToAimer)), angle);
		rocketSprite.setRotation(angle);
		rocketBody->SetLinearVelocity(b2Vec2(cos(angle * DEG_TO_RAD)* speed, sin(angle * DEG_TO_RAD)* speed));	//Multiply by SPEED here
		animationRect = sf::IntRect(0, 0, 62, 62);
		ExplosionT.loadFromFile("godzilla.png");
		ExplsionS.setOrigin(16, 16);
		ExplsionS.setTexture(ExplosionT);
		//}
	//}
}
Rocket::~Rocket()
{
}
bool Rocket::isRocketDeleted()
{
	rocketDeleted = true;
	return rocketDeleted;
}
bool Rocket::isRocketAlive()
{
	rocketAlive = true;
	return rocketAlive;
}

void Rocket::Draw(sf::RenderWindow &window){
	if (!rocketDeleted)
	{
		b2Vec2 rocketPos = rocketBody->GetPosition();
		rocketSprite.setPosition(sf::Vector2f(rocketPos.x, rocketPos.y));
		window.draw(rocketSprite);
	}
}
void Rocket::DrawExplosion(sf::RenderWindow &window)
{
	if (playAnimation == true)
	{
		while (animationRect.left < 366)
		{
			b2Vec2 rocketPos = rocketBody->GetPosition();
			ExplsionS.setPosition(sf::Vector2f(rocketPos.x, rocketPos.y));



			if (animationClock.getElapsedTime().asSeconds() > .25f)
			{
				if (animationRect.left >= 366)
					animationRect.left = 0;
				else
					animationRect.left += 61;

				ExplsionS.setTextureRect(animationRect);
				animationClock.restart();
			}
			window.draw(ExplsionS);
		}
	}
	
}


b2Vec2 Rocket::getPosition()
{
	rocketPos = rocketBody->GetPosition();
	return rocketPos;
}
b2Body* Rocket::getBody()
{
	return rocketBody;
}
void Rocket::ApplyForceShotgun(b2Vec2 pos, float angle)
	{
		if (goRocket == true)
		{
			rocketTexture.loadFromFile("magic.png");
			rocketSprite.setOrigin(16, 16);
			rocketSprite.setTexture(rocketTexture);
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