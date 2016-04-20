
#include "stdafx.h"
#include "BlockManager.h"
#include "BodyDestroyer.h"


bool BlockManager::instanceFlag = false;
BlockManager* BlockManager::instance = NULL;

std::vector<Block*> BlockManager::blocks(0);


BlockManager* BlockManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new BlockManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}
void BlockManager::Init(b2World *pWorld, sf::RenderWindow window)
{




}
void BlockManager::addBlock(int x, int y, int w, int h, b2World  &world, sf::Sprite* sprite)
{
	//std::string path = p;
	b2Vec2 pos(x, y);
	Block* temp = new Block(pos, w, h, world, sprite);

	blocks.push_back(temp);
}




void BlockManager::Draw(sf::RenderWindow& window){

	for each  (Block* block in blocks)
	{

		block->Draw(window);

	}

}

void BlockManager::Update()
{


}

//bool BlockManager::CheckCollision(b2Body*playerBody)
//{
//	for each (Block theBlock in blocks){
//		if (theBlock.CheckCollision(playerBody))
//		{
//			
//			return true;
//		}
//	}
//	return false;
//}

void BlockManager::Reset()
{
	int size = blocks.size();

	for (int i = 0; i < size; i++)
	{
		delete blocks[i];
	}
	blocks.clear();
	//std::vector<Block*>::iterator it = blocks.begin();
	//for (; it != blocks.end();)
	//{
	//	if (*it != NULL)
	//	{

	//		//delete *it;
	//		it = blocks.erase(it);
	//	}
	//	
	//}

}









