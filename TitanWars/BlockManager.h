#ifndef BLOCKMANGER_H
#define BLOCKMANGER_H

#include <iostream> 		
#include <stdio.h>
#include <list>
#include "Block.h"
#include <vector>

using namespace std;

class	BlockManager
{
public:
	void Init(b2World *pWorld, sf::RenderWindow window);
	void Draw(sf::RenderWindow& window);
	void Update();
	static void addBlock(int x, int y, int w, int h, b2World& world, sf::Sprite* sprite);
	//bool CheckCollision(b2Body*playerBody);
	static BlockManager* GetInstance();
	~BlockManager()
	{
		instanceFlag = false;
	}
	void Reset();
private:
	BlockManager()
	{
		platforms = std::list<Block>();
	}
	std::list<Block> platforms;
	static bool instanceFlag;
	static BlockManager* instance;
	static std::vector<Block*> blocks; 
	


};
#endif