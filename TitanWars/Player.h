#ifndef _PLAYER_H 
#define _PLAYER_H


#include <Box2D/Box2D.h>

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

class Player {
	 private:
			b2Body* boxBody;
		 	int m_width, m_height;
			sf::Sprite playerSprite;
			//The final texture 
			sf::Texture playerTexture;
			const float SCALE = 30.f;

	  public:
			Player(b2World &world, int width, int height);
			void Draw(sf::RenderWindow &App,b2World &world);
			~Player(){}
			
					
				 	
				


};
#endif