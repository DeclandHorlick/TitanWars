#pragma once

#include <iostream>
#include "Player.h"
#include "Player2.h"

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 


class PlayerManager
{


public:
	Player* getPlayer1();
	Player2* getPlayer2();
	sf::String setPlayer();
	void createPlayers(b2World &world, int width, int height);
	void setP1TextureName(sf::String p1TextureName);
	void setP2TextureName(sf::String p2TextureName);
	void setCurrentLevel(int theLevel);
	int getCurrentLevel();

	std::vector<Rocket*>* GetPlayersRockets(int playerNumber);
	std::vector<Rifle*>* GetPlayersMagic(int playerNumber);
	std::vector<Car*>* GetPlayersCar(int playerNumber);
	static PlayerManager* GetInstance();


	~PlayerManager()
	{
		instanceFlag = false;
	}
	void Reset();

private:
	int currentLevel = 0;
	Player* myPlayer1;
	Player2* myPlayer2;
	sf::String p1TextureName;
	sf::String p2TextureName;

	PlayerManager()
	{
		
	}
	
	static bool instanceFlag;
	static PlayerManager* instance;
};

