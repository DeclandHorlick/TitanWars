#include <iostream>
#include <cScreen.h>

#include <SFML/Graphics.hpp>
#include "SFML\Audio.hpp"


class HowToPlay : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;




public:
	HowToPlay(void);
	virtual int Run(sf::RenderWindow &App, b2World &world);
	
};

HowToPlay::HowToPlay(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;

}
int HowToPlay::Run(sf::RenderWindow &App, b2World &world)
{
	sf::Event Event;
	bool Running = true;
	bool level2selection = false;
	sf::Texture level1T;
	sf::Sprite level1S;
	
	int alpha = 0;
	sf::Font Font;
	sf::Text level1Text;
	

	int selection = 0;


	if (!level1T.loadFromFile("tutorial.png"))
	{
		std::cerr << "Error loading godPortait.jpg" << std::endl;
	}
	level1S.setTexture(level1T);
	level1S.setColor(sf::Color(255, 255, 255, 255));




	if (!Font.loadFromFile("C:\\Windows\\Fonts\\SLKSCR.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
	}

	level1Text.setFont(Font);
	level1Text.setCharacterSize(20);
	level1Text.setString("Press Enter When Done");
	level1Text.setPosition({ 450.f, 100.f });

	


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
				
				case sf::Keyboard::Return:

					if (selection == 0)
					{
						
						return (0);
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
			level1Text.setColor(sf::Color(255, 255, 255, 255));
			
		}
		



		//Clearing screen
		App.clear();
		//Drawing
		App.draw(level1S);
		

		if (alpha == alpha_max)
		{

			App.draw(level1Text);

		}
		App.display();
	}

}