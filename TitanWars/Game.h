#include <iostream>
#include <cScreen.h>
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Game : public cScreen
{
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	Game(void);
	virtual int Run(sf::RenderWindow &App);
};

Game::Game(void)
{
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int Game::Run(sf::RenderWindow &App)
{
	int alpha = 0;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	sf::Event Event;
	bool Running = true;
	if (!background.loadFromFile("Level.jpg"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	backgroundSprite.setTexture(background);
	backgroundSprite.setColor(sf::Color(255, 255, 255, 350));
	while (Running)
	{
		
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return (0);
					break;
				case sf::Keyboard::Up:
					posy -= movement_step;
					break;
				case sf::Keyboard::Down:
					posy += movement_step;
					break;
				case sf::Keyboard::Left:
					posx -= movement_step;
					break;
				case sf::Keyboard::Right:
					posx += movement_step;
					break;
				default:
					break;
				}
			}
		}

		//Updating
		if (posx>790)
			posx = 790;
		if (posx<0)
			posx = 0;
		if (posy>590)
			posy = 590;
		if (posy<0)
			posy = 0;
		Rectangle.setPosition({ posx, posy });

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(backgroundSprite);
		App.draw(Rectangle);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	//return -1;
}