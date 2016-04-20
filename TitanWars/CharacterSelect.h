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
	bool player2selection = false;
	bool playSwitch = false;
	bool playSwitch2 = false;
	sf::Texture godzillaTexture;
	sf::Sprite godzillaSprite;
	sf::Texture kingTexture;
	sf::Sprite kingSprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text godzillaText;
	sf::Text kingText;
	
	int selection = 0;


	if (!godzillaTexture.loadFromFile("charSelect.png"))
	{
		std::cerr << "Error loading CHARACTER SELECT.jpg" << std::endl;
	}
	godzillaSprite.setTexture(godzillaTexture);
	godzillaSprite.setColor(sf::Color(255, 255, 255, 255));
	
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
	godzillaText.setPosition({ 200.f, 600.f });

	kingText.setFont(Font);
	kingText.setCharacterSize(60);
	kingText.setString("KINGKONG");
	kingText.setPosition({ 675.f, 600.f });


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
					if (player2selection)
					{
						 if (selection == 0)
						{
							//get gozilla
							playing = true;
							PlayerManager::GetInstance()->setP2TextureName(gozillaS);
							SoundManager::GetInstance()->p2Sound();
							return (2);
						}
						else
						{
							//get kingkong
							playing = true;
							PlayerManager::GetInstance()->setP2TextureName(kingS);
							SoundManager::GetInstance()->p2Sound();
							return(2);
						}
					}
					else if (selection == 0)
					{
						//get gozilla
						
						PlayerManager::GetInstance()->setP1TextureName(gozillaS);
						player2selection = true;
						//return (2);
						SoundManager::GetInstance()->p1Sound();
					}
					else
					{
						//get kingkong
						
						PlayerManager::GetInstance()->setP1TextureName(kingS);
						player2selection = true;
						SoundManager::GetInstance()->p1Sound();
						//return(2);
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
		if (player2selection)
		{
			if (selection == 1)
			{
				godzillaText.setColor(sf::Color(255, 255, 255, 255));
				kingText.setColor(sf::Color(0, 0, 255, 255));
			}
			else
			{
				kingText.setColor(sf::Color(255, 255, 255, 255));
				godzillaText.setColor(sf::Color(0, 0, 255, 255));
			}

		}
		else if (selection == 1)
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
		

		if (alpha == alpha_max)
		{
			
				App.draw(godzillaText);
				App.draw(kingText);
			
		}
		App.display();
	}

}