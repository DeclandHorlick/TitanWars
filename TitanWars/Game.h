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
#include "Rifle.h"
#include "BodyDestroyer.h"
#include "SFML\Audio.hpp"
#include "PlayerManager.h"
#include "BlockManager.h"
#include "SoundManager.h"


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
	//Rocket *rocket;
	//Rocket *rifle;
	//std::vector<Rocket*> myRockets;
	sf::SoundBuffer musicBuffer;
	sf::Sound mainMusic;
	int elapsedTime;
	sf::Clock deltaClock;
	sf::Clock p2Clock;
	sf::Clock soundEffectClock;
	
public:
	//Game Init(void);
	int playerTurn;
	
	Game(b2World* world);
	~Game(){ delete player, delete level; };
	virtual int Run(sf::RenderWindow &App, b2World &world);


};


Game::Game(b2World* world)
{
	//collisionResponder;

	//world->SetContactListener(&collisionResponder);
	PlayerManager::GetInstance()->createPlayers(*world, 80, 80);
	//myRockets.push_back(new  Rocket(16, 16, *world));
	//rocket = new Rocket(16, 16, *world);
	//rocket = new Rocket((60, 60), world, 80, 80,"rocket.png");
	//level = new Level(world, 27.66f, 4.f);//world, 26.66f, 4.f
	if (PlayerManager::GetInstance()->getCurrentLevel() == 0)
	{
		Level::LoadLevel("Level1.txt", "Terrain.png", *world);
	}
	else
	{
		Level::LoadLevel("wallLevel.txt", "Terrain.png", *world);
	}
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
	sf::Texture overlayT;
	sf::Sprite overlayS;
	sf::Font Font;
	sf::Text timeText;
	sf::Event Event;
	bool Running = true;
	
	//App.setSize(sf::Vector2u(1200, 640));
	
	mainMusic.play();
	

	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	timeText.setFont(Font);
	timeText.setCharacterSize(60);
	timeText.setPosition({ 550.f, 25.f });
	if (!background.loadFromFile("nightLevel.png"))
	{
		std::cerr << "Error loading bkground" << std::endl;
		return (-1);
	}
	if (!overlayT.loadFromFile("overlay.png"))
	{
		std::cerr << "Error loading overlay" << std::endl;
		return (-1);
	}
	backgroundSprite.setTexture(background);
	overlayS.setTexture(overlayT);
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

		int myRandom = rand() % 5;
		int soundTime = soundEffectClock.getElapsedTime().asSeconds();
		if (soundTime >= 20)
		{
			if (myRandom == 0)
			{
 				SoundManager::GetInstance()->itsGodzilla();
			}
			else if(myRandom == 1)
			{
				SoundManager::GetInstance()->ohMyGod();
			}
			else if (myRandom == 2)
			{
				SoundManager::GetInstance()->leaveUsAlone();
			}
			else if (myRandom == 3)
			{
				SoundManager::GetInstance()->howDareYou();
			}
			
			
			else if (myRandom == 4)
			{
				SoundManager::GetInstance()->whatsGoin();
			}
			/*else if (myRandom == 5)
			{

			}
			else if (myRandom == 6)
			{

			}*/
			soundEffectClock.restart();
		}



		int deltaTime = deltaClock.getElapsedTime().asSeconds();
		int p2Time = p2Clock.getElapsedTime().asSeconds();

		//deltaClock.restart();
		if (deltaTime < 62)
		{
			if (PlayerManager::GetInstance()->getPlayer1()->player1Turn == true)
			{
				
					if (deltaTime >= 0 && deltaTime <= 30)
					{
						PlayerManager::GetInstance()->getPlayer1()->Update(App, world);
						std::string s = std::to_string(30 -deltaTime);
						timeText.setString(s);
						//std::cerr << "This is the time we need = " << deltaTime << std::endl;
						p2Clock.restart();
						if (deltaTime == 30)
						{
							PlayerManager::GetInstance()->getPlayer1()->player1Turn = false;
							PlayerManager::GetInstance()->getPlayer2()->player2Turn = true;
						}
					}
				
			}
			
			else if (p2Time >= 0 && p2Time <= 30 && PlayerManager::GetInstance()->getPlayer2()->player2Turn == true)
			{
				PlayerManager::GetInstance()->getPlayer2()->Update(App, world);
				std::string k = std::to_string(30 - p2Time);
				timeText.setString(k);
				deltaClock.restart();

				if (p2Time == 30)
				{
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = false;
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = true;
				}
			
			}
			else //if (deltaTime > 60)
			{
				deltaClock.restart();
				p2Clock.restart();
			}


		}


		//PROBLEMS


		//elapsedTime = 0;
		for (int i = 0; PlayerManager::GetInstance()->getPlayer1()->myRockets.size() > i;i++)
		{

			if (PlayerManager::GetInstance()->getPlayer1()->myRockets[i]->rocketAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer1()->myRockets[i]->Draw(App);
				PlayerManager::GetInstance()->getPlayer1()->myRockets[i]->DrawExplosion(App);
			}
		}		
		for (int i = 0; PlayerManager::GetInstance()->getPlayer2()->myRockets.size() > i; i++)
		{

			if (PlayerManager::GetInstance()->getPlayer2()->myRockets[i]->rocketAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer2()->myRockets[i]->Draw(App);
				PlayerManager::GetInstance()->getPlayer2()->myRockets[i]->DrawExplosion(App);
			}
		}


		for (int i = 0; PlayerManager::GetInstance()->getPlayer1()->myMagic.size() > i; i++)
		{

			if (PlayerManager::GetInstance()->getPlayer1()->myMagic[i]->rifleAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer1()->myMagic[i]->Draw(App);
				
			}
		}
		for (int i = 0; PlayerManager::GetInstance()->getPlayer2()->myMagic.size() > i; i++)
		{

			if (PlayerManager::GetInstance()->getPlayer2()->myMagic[i]->rifleAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer2()->myMagic[i]->Draw(App);
				
			}
		}


		for (int i = 0; PlayerManager::GetInstance()->getPlayer1()->myCar.size() > i; i++)
		{

			if (PlayerManager::GetInstance()->getPlayer1()->myCar[i]->carAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer1()->myCar[i]->Draw(App);

			}
		}
		for (int i = 0; PlayerManager::GetInstance()->getPlayer2()->myCar.size() > i; i++)
		{

			if (PlayerManager::GetInstance()->getPlayer2()->myCar[i]->carAlive == true)
			{
				PlayerManager::GetInstance()->getPlayer2()->myCar[i]->Draw(App);

			}
		}
		
		App.draw(timeText);

		
		Level::draw(App);

		PlayerManager::GetInstance()->getPlayer1()->Draw(App, world);
		PlayerManager::GetInstance()->getPlayer2()->Draw(App, world);


		App.draw(overlayS);
		App.display();
		if (PlayerManager::GetInstance()->getPlayer1()->getHealth() <= 0 || PlayerManager::GetInstance()->getPlayer2()->getHealth() <= 0)
		{
			SoundManager::GetInstance()->winner();
			return(3);
		}
		
	}

	//Never reaching this point normally, but just in case, exit the application
	//return -1;
}
