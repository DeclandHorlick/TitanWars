#include <iostream>
#include <cScreen.h>

#include <SFML/Graphics.hpp>
#include "SFML\Audio.hpp"
#include "PlayerManager.h"

class EndGame : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;




public:
	EndGame(void);
	virtual int Run(sf::RenderWindow &App, b2World &world);
	
};

EndGame::EndGame(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;

}
int EndGame::Run(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture endGameTexture;
	sf::Sprite endGameSprite;
	
	int alpha = 0;
	sf::Font Font;
	sf::Text restartGame;
	sf::Text mainMenuTxt;
	sf::Text changeCharacter;

	int selection = 0;


	if (!endGameTexture.loadFromFile("endGame.png"))
	{
		std::cerr << "Error loading godPortait.jpg" << std::endl;
	}
	endGameSprite.setTexture(endGameTexture);
	endGameSprite.setColor(sf::Color(255, 255, 255, 255));

	




	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	mainMenuTxt.setFont(Font);
	mainMenuTxt.setCharacterSize(40);
	mainMenuTxt.setString("Main Menu");
	mainMenuTxt.setPosition({ 470.f, 380.f });

	restartGame.setFont(Font);
	restartGame.setCharacterSize(40);
	restartGame.setString("Restart");
	restartGame.setPosition({ 510.f,480.f });

	changeCharacter.setFont(Font);
	changeCharacter.setCharacterSize(40);
	changeCharacter.setString("Change Characters");
	changeCharacter.setPosition({ 375.f, 580.f });




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
					if (selection == 0)
						selection = 0;
					else
					{
						selection -= 1;
						SoundManager::GetInstance()->choose();
					}
					break;
				case sf::Keyboard::Down:
					if (selection == 2)
						selection = 2;
					else
					{
						selection += 1;
						SoundManager::GetInstance()->choose();
					}
					break;
				case sf::Keyboard::Return:
					
						if (selection == 0)
						{
							//get gozilla
							//playing = true;
							//PlayerManager::GetInstance()->setP2TextureName(gozillaS);
							SoundManager::GetInstance()->selected();
							BlockManager::GetInstance()->Reset();
							PlayerManager::GetInstance()->Reset();
							EffectsManager::GetInstance()->reset();
							return (0);
						}
						else if (selection == 1)
						{
							SoundManager::GetInstance()->selected();
							BlockManager::GetInstance()->Reset();
							PlayerManager::GetInstance()->Reset();
							EffectsManager::GetInstance()->reset();
							return(5);
						}
						else
						{
							SoundManager::GetInstance()->selected();
							BlockManager::GetInstance()->Reset();
							PlayerManager::GetInstance()->Reset();
							EffectsManager::GetInstance()->reset();
							return(1);
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
			if (selection == 0)
			{
				restartGame.setColor(sf::Color(255, 255, 255, 255));
				mainMenuTxt.setColor(sf::Color(255, 0, 0, 255));
				changeCharacter.setColor(sf::Color(255, 255, 255, 255));
			}
			else if (selection == 1)
			{
				mainMenuTxt.setColor(sf::Color(255, 255, 255, 255));
				restartGame.setColor(sf::Color(255, 0, 0, 255));
				changeCharacter.setColor(sf::Color(255, 255, 255, 255));
			}
			else
			{
				restartGame.setColor(sf::Color(255, 255, 255, 255));
				mainMenuTxt.setColor(sf::Color(255, 255, 255, 255));
				changeCharacter.setColor(sf::Color(255, 0, 0, 255));
				

			}

		
		/*godzillaSprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		kingSprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));

		kingText.setColor(sf::Color(255, 255, 255, 255));
		godzillaText.setColor(sf::Color(255, 255, 255, 255));*/

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(endGameSprite);

		if (alpha == alpha_max)
		{

			App.draw(restartGame);
			App.draw(mainMenuTxt);
			App.draw(changeCharacter);

		}
		App.display();
	}

}