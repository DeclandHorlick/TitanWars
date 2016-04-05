#include "stdafx.h"
#include "PlayerManager.h"
bool PlayerManager::instanceFlag = false;
PlayerManager* PlayerManager::instance = NULL;



PlayerManager* PlayerManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new PlayerManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

Player* PlayerManager::getPlayer1()
{
	return myPlayer1;
}
Player2* PlayerManager::getPlayer2()
{
	return myPlayer2;

}

void PlayerManager::createPlayers(b2World &world, int width, int height)
{

	myPlayer1 = new Player(world, 80, 80);
	myPlayer1->SetTitan(p1TextureName);

	myPlayer2 = new Player2(world, 80, 80);
	myPlayer2->SetTitan(p2TextureName);

}
void PlayerManager::setP1TextureName(sf::String p1TextureName)
{
	this->p1TextureName = p1TextureName;
}
void PlayerManager::setP2TextureName(sf::String p2TextureName)
{
	this->p2TextureName = p2TextureName;
}