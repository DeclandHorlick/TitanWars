#include <iostream>
#include <cScreen.h>

#include <SFML/Graphics.hpp>
#include "SFML\Audio.hpp"
#include "PlayerManager.h"

class Menu : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	
	sf::SoundBuffer godzillaBuffer;
	sf::Sound godzillaSound;
	bool playing;
public:
	Menu(void);
	virtual int Run(sf::RenderWindow &App, b2World &world);
 
};

Menu::Menu(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int Menu::Run(sf::RenderWindow &App,b2World &world)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
	godzillaBuffer.loadFromFile("godzillaRoar.wav");
	godzillaSound.setBuffer(godzillaBuffer);

	if (!Texture.loadFromFile("presentation.jpg"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);
	Sprite.setColor(sf::Color(255, 255, 255, alpha));
	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		//return (-1);
	}
	Menu1.setFont(Font);
	Menu1.setCharacterSize(60);
	Menu1.setString("Play");
	Menu1.setPosition({ 100.f, 80.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(60);
	Menu2.setString("Exit");
	Menu2.setPosition({ 100.f, 160.f });

	Menu3.setFont(Font);
	Menu3.setCharacterSize(60);
	Menu3.setString("Continue");
	Menu3.setPosition({ 100.f, 80.f });

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
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Return:
					if (menu == 0 && playing == true)
					{
						//get play !
						return (2);
					}
					else if (menu == 0)
					{
						//get play !
						godzillaSound.play();
						playing = true;
						return (1);
					}
					else
					{
						//get work
						return (-1);
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
		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(Sprite);
		
		if (alpha == alpha_max)
		{
			if (playing)
			{
				App.draw(Menu3);
				if (PlayerManager::GetInstance()->getPlayer1()->getHealth() <= 0 || PlayerManager::GetInstance()->getPlayer2()->getHealth() <= 0)
				{
					playing = false;
				}
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		}
		App.display();
	}

	
}