#include <iostream>
#include <cScreen.h>

#include <SFML/Graphics.hpp>
#include "SFML\Audio.hpp"
#include "PlayerManager.h"

class LevelSelect : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;




public:
	LevelSelect(void);
	virtual int Run(sf::RenderWindow &App, b2World &world);
	sf::String level1S = "Open Battle";
	sf::String level2S = "The Wall";
};

LevelSelect::LevelSelect(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;

}
int LevelSelect::Run(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	bool Running = true;
	bool level2selection = false;
	bool playSwitch = false;
	bool playSwitch2 = false;
	sf::Texture level1T;
	sf::Sprite level1S;
	sf::Texture level2T;
	sf::Sprite level2S;
	int alpha = 0;
	sf::Font Font;
	sf::Text level1Text;
	sf::Text level2Text;

	int selection = 0;


	if (!level1T.loadFromFile("mapselect.png"))
	{
		std::cerr << "mapselect" << std::endl;
	}
	level1S.setTexture(level1T);
	level1S.setColor(sf::Color(255, 255, 255, 255));

	if (!level2T.loadFromFile("kingPortait.jpg"))
	{
		std::cerr << "Error loading king.jpg" << std::endl;
	}
	level2S.setTexture(level2T);
	level2S.setColor(sf::Color(255, 255, 255, alpha));




	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	level1Text.setFont(Font);
	level1Text.setCharacterSize(40);
	level1Text.setString("Open Battle");
	level1Text.setPosition({ 130.f, 600.f });

	level2Text.setFont(Font);
	level2Text.setCharacterSize(40);
	level2Text.setString("The Wall");
	level2Text.setPosition({ 800.f, 600.f });


	if (playing)
	{
		alpha = alpha_max;
	}

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
				case sf::Keyboard::Left:
				{
					if (playSwitch2 == true)
					{
						SoundManager::GetInstance()->choose();
						playSwitch = false;
						playSwitch2 = false;

					}
					selection = 0;
				}
					break;
				case sf::Keyboard::Right:
				{
					if (!playSwitch)
					{
						SoundManager::GetInstance()->choose();
						playSwitch = true;
						playSwitch2 = true;
					}
					selection = 1;
				}
					break;
				case sf::Keyboard::Return:
					
					if (selection == 0)
					{
						//get gozilla
						SoundManager::GetInstance()->levelSsound();
						PlayerManager::GetInstance()->setCurrentLevel(0);

						//load level 1
						//level1selection = true;
						return (5);
					}
					else
					{
						//get kingkong
						SoundManager::GetInstance()->levelSsound();
						PlayerManager::GetInstance()->setCurrentLevel(1);
						return (5);
						
					}
					break;
				default:
					break;
				}
			}
		}
		//Creating text
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha < alpha_max)
		{
			alpha++;
		}
		if (selection == 1)
		{
				level1Text.setColor(sf::Color(255, 255, 255, 255));
				level2Text.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
				level2Text.setColor(sf::Color(255, 255, 255, 255));
				level1Text.setColor(sf::Color(255, 0, 0, 255));
		}

		
		
		//Clearing screen
		App.clear();
		//Drawing
		App.draw(level1S);
		App.draw(level2S);

		if (alpha == alpha_max)
		{

			App.draw(level1Text);
			App.draw(level2Text);

		}
		App.display();
	}

}