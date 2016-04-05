#include "stdafx.h"
#include <iostream>
#include <cScreen.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Player2.h"
#include "Level.h"
#include "Block.h"
#include "Rocket.h"
#include "BodyDestroyer.h"
#include "SFML\Audio.hpp"
#include "PlayerManager.h"


class Game : public cScreen
{
private:
	
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	//b2Body* boxBody;
	Player* player;
	Player2* player2;
	Level *level;
	Rocket *rocket;
	
	sf::SoundBuffer musicBuffer;
	sf::Sound mainMusic;
	int elapsedTime;
	sf::Clock deltaClock;
	
public:
	//Game Init(void);
	Game(b2World* world);
	~Game(){ delete player, delete level; };
	virtual int Run(sf::RenderWindow &App, b2World &world);


};


Game::Game(b2World* world)
{
	//collisionResponder;

	//world->SetContactListener(&collisionResponder);
	PlayerManager::GetInstance()->createPlayers(*world, 80, 80);
	rocket = new Rocket(80, 10, *world);
	//rocket = new Rocket((60, 60), world, 80, 80,"rocket.png");
	//level = new Level(world, 27.66f, 4.f);//world, 26.66f, 4.f
	Level::LoadLevel("Level1.txt", "Terrain.png", *world);
	musicBuffer.loadFromFile("mainMusic.wav");
	mainMusic.setBuffer(musicBuffer);
	
}

int Game::Run(sf::RenderWindow &App, b2World &world)
{
	//world.SetContactListener(&collisionResponder);
	BodyDestroyer::GetInstance(&world);
	int alpha = 0;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	
	sf::Event Event;
	bool Running = true;
	
	//App.setSize(sf::Vector2u(1200, 640));
	
	mainMusic.play();
	

	
	if (!background.loadFromFile("nightLevel.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	backgroundSprite.setTexture(background);
	//backgroundSprite.setColor(sf::Color(255, 255, 255, 1));
	while (Running)
	{
		BodyDestroyer::GetInstance()->DestroyBodies();
		
		//*level;
		while (App.pollEvent(Event))
		{

			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return (0);
					break;
				default:
					break;
				}
			}
		}


		world.Step(1 / 60.f, 8, 3);
		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing

		App.draw(backgroundSprite);
		Level::draw(App);
		PlayerManager::GetInstance()->getPlayer1()->Draw(App, world);
		//level->draw(App);
		
		PlayerManager::GetInstance()->getPlayer2()->Draw(App, world);
		float deltaTime = deltaClock.getElapsedTime().asSeconds();
		//deltaClock.restart();
		if (deltaTime < 61)
		{
			if (deltaTime >= 0 && deltaTime <= 30)
			{
				PlayerManager::GetInstance()->getPlayer1()->Update(App, world, rocket);
				//deltaTime += 1;
				//std::cerr << "This is the time we need = " << deltaTime << std::endl;
			}
			else if (deltaTime > 30 && deltaTime < 60)
			{
				PlayerManager::GetInstance()->getPlayer2()->Update(App, world, rocket);
				//deltaTime++;
			}
			else if (deltaTime > 60)
			{
				deltaClock.restart();
			}
			
			
		}
		
		//elapsedTime = 0;
		if (rocket->getRocket() != true)
		{
			//rocket = new Rocket(80, 10, world);
			rocket->Draw(App);
			//rocket->ApplyForce();
		}
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	//return -1;
}
