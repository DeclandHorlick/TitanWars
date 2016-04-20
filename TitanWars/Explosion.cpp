#include "stdafx.h"
#include "Explosion.h"


Explosion::Explosion(b2Vec2 pos)
{
	explosionT.loadFromFile("explawsion.png");
	explosionS.setOrigin(32, 32);
	explosionS.setTexture(explosionT);
	explosionS.setTextureRect(animationRect);
	explosionS.setPosition(pos.x, pos.y);
	explosionS.setScale(1.8f, 1.8f);

	playExplode = true;
	
}

void Explosion::draw(sf::RenderWindow &window)
{

	if (playExplode == true)
	{

		if (animationClock.getElapsedTime().asSeconds() > .04f)
		{

			if (animationRect.left >= 512)
			{
				animationRect.left = 0;
				playExplode = false;
			}
			else
			{
				animationRect.left += 64;
			}
			explosionS.setTextureRect(animationRect);
			animationClock.restart();
		}
		window.draw(explosionS);
	}
}


Explosion::~Explosion()
{
}
