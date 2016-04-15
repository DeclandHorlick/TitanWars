
#include "stdafx.h"
#include <Box2D/Box2D.h>
#include <stdio.h>


#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include "ScreenManager.h"
#include <Box2D/Box2D.h>
#include "Player.h"
#include "CollisionResponder.h"


int main(int argc, char** argv)
{
		//Applications variables
		std::vector<cScreen*> Screens;
		int screen = 0;

		b2Vec2 Gravity(0.f,2.5f);
		b2World World(Gravity);
		CollisionResponder collisionResponder;
		World.SetContactListener(&collisionResponder);
		//Window creation
		sf::RenderWindow App(sf::VideoMode(1200, 700, 32), "Titan Wars");

		//Mouse cursor no more visible
		App.setMouseCursorVisible(false);
		
		//Screens preparations
		Menu s0;
		Screens.push_back(&s0);

		CharacterSelect s1;
		Screens.push_back(&s1);
		
		EndGame s3;
		Screens.push_back(&s3);

		bool gameLoaded = false;

		//Main loop
		while (screen >= 0)
		{

			screen = Screens[screen]->Run(App,World);
			if (screen == 3 && !gameLoaded)
			{
				Game s2(&World);
				Screens.push_back(&s2);
				gameLoaded = true;
			}
			else
			{
				gameLoaded = false;
				
			}
		}
		
		return EXIT_SUCCESS;
}

