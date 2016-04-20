#include "stdafx.h"

#include "Player2.h"
#include "BodyDestroyer.h"
#include "PlayerManager.h"
#include "SoundManager.h"
#include "Block.h"
#include <vector> 
#include <iostream>
#ifdef _DEBUG
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-network-d.lib")
#else
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-network.lib")
#endif
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include "SFML/Graphics.hpp"
#include <SFML/Window/Mouse.hpp>
#include "SFML/OpenGL.hpp"

#include <iostream>
#include <string.h>

Player2::Player2(b2World &world, int width, int height)
{
	World = &world;
	//Define a b2body
	b2BodyDef bodyDef;
	//bodyDef.type = b2_staticBody;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = b2Vec2(900, 300);
	bodyDef.userData = this;
	//Ask the b2Worldto create our body
	boxBody = world.CreateBody(&bodyDef);
	
	//Define the shape of the body
	b2PolygonShape shape;
	shape.SetAsBox(width * 0.5f, height * 0.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.2f;  // Sets the density of the body
	FixtureDef.shape = &shape; // Sets the shape
	FixtureDef.restitution = 0.f;
	FixtureDef.userData = "Player2";
	boxBody->CreateFixture(&FixtureDef); // Apply the fixture definition
	//boxBody->ApplyForce(velocity, bodyDef.position, true);
	m_width = width;
	m_height = height;
	//playerTexture.loadFromFile("godzilla.png");
	aimTexture.loadFromFile("aimer.png");
	playerSprite.setOrigin(34.5, 36);
	playerSprite.setTexture(playerTexture);
	aimSprite.setOrigin(-42.5, 0);
	aimSprite.setTexture(aimTexture);

	cWeaponTexture1.loadFromFile("bomb.png");
	cWeaponTexture2.loadFromFile("cmagic.png");
	cWeaponTexture3.loadFromFile("shotgun.png");

	powerTexture.loadFromFile("bigBoom.png");
	powerSprite.setOrigin(0, 80);
	powerSprite.setTexture(powerTexture);

	weaponBkT.loadFromFile("bar2.png");
	weaponBkS.setTexture(weaponBkT);
	weaponBkS.setPosition(1010, 680);

	myNames.push_back("Gormy : ");
	myNames.push_back("John : ");
	myNames.push_back("Ken : ");
	myNames.push_back("Bren : ");
	myNames.push_back("Helen : ");
	myNames.push_back("Enda : ");
	myNames.push_back("Con : ");
	myNames.push_back("Jebb : ");
	myNames.push_back("Ryan : ");
	myNames.push_back("Andy : ");
	myNames.push_back("Shane : ");
	myNames.push_back("Chris : ");
	myNames.push_back("Josh : ");
	myNames.push_back("Phil : ");
	myNames.push_back("Laz : ");
	int myRandom = rand() % myNames.size();
	currentName = myNames[myRandom];
	
	playerSprite.setTextureRect(animationRect);
	
	rotation = aimSprite.getRotation();

	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;

	}
	health = 100;
	nameHealth.setFont(Font);
	nameHealth.setCharacterSize(12);
	nameHealth.setColor(sf::Color(87, 146, 181, 255));

	rocketBuffer.loadFromFile("rocketThrow.wav");

	rocketSound.setBuffer(rocketBuffer);



}
void Player2::Draw(sf::RenderWindow &App, b2World &world)
{
	nameHealth.setPosition({ bodypos.x - 30, bodypos.y + 35 });
	s = std::to_string(getHealth());
	nameHealth.setString(currentName + s);

	if (weaponSelected == 0)
	{
		cWeaponSprite.setTexture(cWeaponTexture1);
		cWeaponSprite.setPosition(1000, 600);
	}
	else if (weaponSelected == 1)
	{
		cWeaponSprite.setTexture(cWeaponTexture2);
		cWeaponSprite.setPosition(1000, 600);
	}
	else if (weaponSelected == 2)
	{
		cWeaponSprite.setTexture(cWeaponTexture3);
		cWeaponSprite.setPosition(1000, 600);
	}
	if (_myTitan == "godzilla")
	{
		if (animationClock.getElapsedTime().asSeconds() > .25f)
		{
		if (currentAnimation == 0)
		{

			animationRect.top = 0;
			if (animationRect.left >= 207)
			{
				animationRect.left = 0;
			}
			else
			{
				animationRect.left += 69;
			}
		}
		else if (currentAnimation == 1)
		{
			if (switchAnimation == true)
			{
				animationRect.left = 0;
				animationRect.top = 72;
				switchAnimation = false;
			}

			if (animationRect.left >= 276)
			{
				animationRect.left = 0;
				currentAnimation = 0;
			}
			else
			{
				animationRect.left += 69;
			}
		}
		else if (currentAnimation == 2)
		{
			if (switchAnimation == true)
			{
				animationRect.left = 0;
				animationRect.top = 144;
				switchAnimation = false;
			}

			if (animationRect.left >= 276)
			{
				animationRect.left = 0;
				currentAnimation = 0;
			}
			else
				animationRect.left += 69;
		}
			playerSprite.setTextureRect(animationRect);
			animationClock.restart();
		}
	}
	else if (_myTitan == "kingkong")
	{
		if (animationClock.getElapsedTime().asSeconds() > .25f)
		{
			if (currentAnimation == 0)
			{

				animationRect.top = 0;
				if (animationRect.left >= 183)
				{
					animationRect.left = 0;
				}
				else
				{
					animationRect.left += 61;
				}
			}
			else if (currentAnimation == 1)
			{
				if (switchAnimation == true)
				{
					animationRect.left = 0;
					animationRect.top = 72;
					switchAnimation = false;
				}

				if (animationRect.left >= 305)
				{
					animationRect.left = 0;
					currentAnimation = 0;
				}
				else
				{
					animationRect.left += 61;
				}
			}
			else if (currentAnimation == 2)
			{
				if (switchAnimation == true)
				{
					animationRect.left = 0;
					animationRect.top = 144;
					switchAnimation = false;
				}

				if (animationRect.left >= 276)
				{
					animationRect.left = 0;
					currentAnimation = 0;
				}
				else
					animationRect.left += 61;
			}

			playerSprite.setTextureRect(animationRect);
			animationClock.restart();
		}
	}
	bodypos = boxBody->GetPosition();
	playerSprite.setPosition(sf::Vector2f(bodypos.x, bodypos.y));
	aimSprite.setPosition(sf::Vector2f(bodypos.x, bodypos.y));
	if (rotation < 270 && rotation > 0)
	{
		playerSprite.setScale(-1, 1);

	}
	else if (rotation >= 270 || rotation == 0)
	{
		playerSprite.setScale(1, 1);

	}
	App.draw(weaponBkS);
	App.draw(playerSprite);
	App.draw(nameHealth);
	App.draw(aimSprite);
	App.draw(cWeaponSprite);
	int32 BodyIterator = world.GetBodyCount();
	//std::cout << playerSprite.getPosition().x << "  " << playerSprite.getPosition().y << std::endl;
	
}
void Player2::SetTitan(sf::String &myTitan)
{
	_myTitan = myTitan;
	if (_myTitan == "godzilla")
	{
		animationRect = sf::IntRect(0, 0, 69, 72);
		playerTexture.loadFromFile("godzilla.png");
	}
	else
	{
		animationRect = sf::IntRect(0, 0, 61, 72);
		playerTexture.loadFromFile("kingkong.png");
	}
	playerSprite.setTexture(playerTexture);

}
void Player2::Update(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	float xVelocity(5.6f);
	b2Vec2 yVelocity(0, 15);
	getVelocity = boxBody->GetLinearVelocity();
	powerSprite.setPosition(bodypos.x - 20, bodypos.y);

	if (bodypos.y > 850)
	{
		setHealth(100);
	}
	//cant shoot multiple
	if (myRockets.size() == 1)
	{
		weaponSelected = 0;
	}
	if (myMagic.size() == 1)
	{
		weaponSelected = 1;
	}
	if (myCar.size() == 1)
	{
		weaponSelected = 2;
	}

	if (myRockets.size() == 0 && weaponSelected == 0)
	{
		App.draw(powerSprite);
	}
	if (myCar.size() == 0 && weaponSelected == 2)
	{
		App.draw(powerSprite);
	}
	if (power <= 100 && powerSwitch == false)
	{

		power += .5;
		if (power >= 100)
		{
			powerSwitch = true;
		}
	}
	else if (power >= 0 && powerSwitch == true)
	{
		power -= .5;
		if (power <= 0)
		{
			powerSwitch = false;
		}
	}
	powerSprite.setScale(power, 1);


	if (myRockets.size() != 0)
	{
		if (myRockets[0]->getPosition().x < -150 || myRockets[0]->getPosition().x > 1350)
		{
			myRockets[0]->rocketDeleted = true;

			BodyDestroyer::GetInstance()->AddBody(myRockets[0]->getBody());

			player2Turn = false;

			PlayerManager::GetInstance()->getPlayer1()->player1Turn = true;
			myRockets.clear();
		}
	}


	if (myMagic.size() != 0)
	{
		if (myMagic[0]->getPosition().x < -150 || myMagic[0]->getPosition().x > 1350)
		{
			myMagic[0]->rifleDeleted = true;

			BodyDestroyer::GetInstance()->AddBody(myMagic[0]->getBody());

			player2Turn = false;

			PlayerManager::GetInstance()->getPlayer1()->player1Turn = true;
			std::vector<Rifle*>::iterator it = myMagic.begin();
			for (; it != myMagic.end();)
			{
				delete (*it);
				it = myMagic.erase(it);
			}

		}
		else if (myMagic[0]->getPosition().y < -500)
		{
			myMagic[0]->rifleDeleted = true;

			BodyDestroyer::GetInstance()->AddBody(myMagic[0]->getBody());

			player2Turn = false;

			PlayerManager::GetInstance()->getPlayer1()->player1Turn = true;

			std::vector<Rifle*>::iterator it = myMagic.begin();
			for (; it != myMagic.end();)
			{
				delete (*it);
				it = myMagic.erase(it);
			}
		}
	}


	if (myCar.size() != 0)
	{
		if (myCar[0]->getPosition().x < -150 || myCar[0]->getPosition().x > 1350)
		{
			myCar[0]->carDeleted = true;

			BodyDestroyer::GetInstance()->AddBody(myCar[0]->getBody());

			player2Turn = false;

			PlayerManager::GetInstance()->getPlayer1()->player1Turn = true;


			std::vector<Car*>::iterator it = myCar.begin();
			for (; it != myCar.end();)
			{
				delete (*it);
				it = myCar.erase(it);
			}

		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (bodypos.x >= 10)
		{
			boxBody->SetLinearVelocity(b2Vec2(-xVelocity, boxBody->GetLinearVelocity().y));
			goingRight = false;
			if (currentAnimation != 2)
			{
				currentAnimation = 2;
				switchAnimation = true;
			}
		}
		else
		{
			boxBody->SetLinearVelocity(b2Vec2(0, 0));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (bodypos.x <= 1190)
		{

			boxBody->SetLinearVelocity(b2Vec2(xVelocity, boxBody->GetLinearVelocity().y));
			goingRight = true;
			if (currentAnimation != 2)
			{
				currentAnimation = 2;
				switchAnimation = true;
			}
		}
		else
		{
			boxBody->SetLinearVelocity(b2Vec2(0, 0));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

		//jumping = true;
		//boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -50));
		if (getVelocity.y == 0)
		{
			boxBody->SetLinearVelocity(b2Vec2(boxBody->GetLinearVelocity().x, -yVelocity.y));
		}


	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		buttonRoleased = true;
		//rocket->setRocket(true);
	}
	if (buttonRoleased && sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		if (weaponSelected == 0)
		{
			if (myRockets.size() == 0)
			{
				if (currenRtMusic == 0)
				{
					SoundManager::GetInstance()->bombsAway();
					currenRtMusic += 1;
				}
				else if (currenRtMusic == 1)
				{
					SoundManager::GetInstance()->eatThis();
					currenRtMusic = 0;
				}
				currentAnimation = 1;
				switchAnimation = true;
				myRockets.push_back(new Rocket(2, 16, rotation, boxBody->GetPosition(), world, power));
				myRockets[0]->isRocketAlive();
						
				
			}
		}
		if (weaponSelected == 1)
		{
			if (myMagic.size() == 0)
			{
				if (myMagic.size() == 0)
				{
					if (currentMusic == 0)
					{
						SoundManager::GetInstance()->puke();
						currentMusic += 1;
					}
					else if (currentMusic == 1)
					{
						SoundManager::GetInstance()->puke2();
						currentMusic += 1;
					}
					else
					{
						SoundManager::GetInstance()->puke3();
						currentMusic = 0;
					}
					currentAnimation = 1;
					switchAnimation = true;
					myMagic.push_back(new Rifle(2, 16, rotation, boxBody->GetPosition(), world));
					myMagic[0]->isRifleAlive();

					//rocketSound.play();
				}
			}
		}
		else if (weaponSelected == 2)
		{
			if (myCar.size() == 0)
			{
				SoundManager::GetInstance()->scream();
				currentAnimation = 1;
				switchAnimation = true;
				myCar.push_back(new Car(2, 16, rotation, boxBody->GetPosition(), world, power / 2));
				myCar[0]->isCarAlive();
			}
		}
		buttonRoleased = false;
		power = 1;
		

	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{

		buttonReleased = false;

	}
	if (!buttonReleased && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		if (weaponSelected == 2)
		{
			weaponSelected = 0;
		}
		else
		{
			weaponSelected += 1;
		}
		buttonReleased = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (rotation > 180 || rotation == 0)
		{
			aimSprite.rotate(-.25);
			rotation = aimSprite.getRotation();

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (rotation >= 180)
		{
			//aimSprite.setRotation(0);
			aimSprite.rotate(.25);
			rotation = aimSprite.getRotation();
		}


	}
}
int Player2::setHealth(int lostHealth)
{
	health -= lostHealth;
	return health;
}
int Player2::getHealth()
{
	return health;
}