#include <iostream>
#include <cScreen.h>

#include <SFML/Graphics.hpp>
#include "SFML\Audio.hpp"
#include "PlayerManager.h"

class CharacterSelect : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
	
	


public:
	CharacterSelect(void);
	virtual int Run(sf::RenderWindow &App, b2World &world);
	sf::String gozillaS = "godzilla";
	sf::String kingS = "kingkong";
};

CharacterSelect::CharacterSelect(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	
}
int CharacterSelect::Run(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture godzillaTexture;
	sf::Sprite godzillaSprite;
	sf::Texture kingTexture;
	sf::Sprite kingSprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text godzillaText;
	sf::Text kingText;
	
	int selection = 0;


	if (!godzillaTexture.loadFromFile("godPortait.jpg"))
	{
		std::cerr << "Error loading godPortait.jpg" << std::endl;
	}
	godzillaSprite.setTexture(godzillaTexture);
	godzillaSprite.setColor(sf::Color(255, 255, 255, alpha));
	
	if (!kingTexture.loadFromFile("kingPortait.jpg"))
	{
		std::cerr << "Error loading king.jpg" << std::endl;
	}
	kingSprite.setTexture(kingTexture);
	kingSprite.setColor(sf::Color(255, 255, 255, alpha));
	
	
	
	
	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	godzillaText.setFont(Font);
	godzillaText.setCharacterSize(60);
	godzillaText.setString("GODZILLA");
	godzillaText.setPosition({ 600.f, 300.f });

	kingText.setFont(Font);
	kingText.setCharacterSize(60);
	kingText.setString("KINGKONG");
	kingText.setPosition({ 600.f, 500.f });


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
					selection = 0;
					break;
				case sf::Keyboard::Right:
					selection = 1;
					break;
				case sf::Keyboard::Return:
					if (selection == 0)
					{
						//get gozilla
						playing = true;
						PlayerManager::GetInstance()->setP1TextureName(gozillaS);
						
						return (2);
					}
					else
					{
						//get kingkong
						playing = true;
						PlayerManager::GetInstance()->setP1TextureName(kingS);

						return(2);
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
			godzillaText.setColor(sf::Color(255, 255, 255, 255));
			kingText.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			kingText.setColor(sf::Color(255, 255, 255, 255));
			godzillaText.setColor(sf::Color(255, 0, 0, 255));
		}
		/*godzillaSprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		kingSprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		
		kingText.setColor(sf::Color(255, 255, 255, 255));
		godzillaText.setColor(sf::Color(255, 255, 255, 255));*/

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(godzillaSprite);
		App.draw(kingSprite);

		if (alpha == alpha_max)
		{
			
				App.draw(godzillaText);
				App.draw(kingText);
			
		}
		App.display();
	}

}