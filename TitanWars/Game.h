#include <iostream>
#include <cScreen.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"
#include "Block.h"
#include "Rocket.h"


class Game : public cScreen
{
private:
	
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	//b2Body* boxBody;
	Player* player;
	Level *level;
	Rocket *rocket;
	
	
public:
	//Game Init(void);
	Game(b2World &world);
	~Game(){ delete player, delete level; };
	virtual int Run(sf::RenderWindow &App, b2World &world);


};


Game::Game(b2World &world)
{
	
	player = new Player(world,  80, 80);
	rocket = new Rocket(80, 10, world);
	//rocket = new Rocket((60, 60), world, 80, 80,"rocket.png");
	//level = new Level(world, 27.66f, 4.f);//world, 26.66f, 4.f
	Level::LoadLevel("Level1.txt", "Block3.png", world);
	
}

int Game::Run(sf::RenderWindow &App, b2World &world)
{
	
	int alpha = 0;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	
	sf::Event Event;
	bool Running = true;
	
	//App.setSize(sf::Vector2u(1200, 640));
	

	

	
	if (!background.loadFromFile("canyonLevel.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	backgroundSprite.setTexture(background);
	//backgroundSprite.setColor(sf::Color(255, 255, 255, 1));
	while (Running)
	{
		
		*player;
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
		player->Draw(App,world);
		//level->draw(App);
		player->Update(App, world,rocket);
		if (rocket->getRocket() != true)
		{
			//rocket = new Rocket(80, 10, world);
			rocket->Draw(App);
			//rocket->ApplyForce();
		}
		App.draw(Rectangle);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	//return -1;
}
