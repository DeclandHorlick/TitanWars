#ifndef _COLLISION_RESPONDER_H
#define _COLLISION_RESPONDER_H
//
#include "stdafx.h"
#include <Box2D/Box2D.h>
//#include "stdafx.h"
#include "Block.h"
//#include "Player.h"
#include "Rocket.h"
#include "BodyDestroyer.h"
#include "Player.h"
#include "Player2.h"
//
class CollisionResponder: public b2ContactListener {
public:

	void BeginContact(b2Contact* contact)
	{
		void* fixAType = contact->GetFixtureA()->GetUserData();
		void* fixBType = contact->GetFixtureB()->GetUserData();

		void* a = contact->GetFixtureA()->GetBody()->GetUserData();
		void* b = contact->GetFixtureB()->GetBody()->GetUserData();

		if ((fixAType == "Rocket" && fixBType == "Block")
			|| (fixAType == "Block" && fixBType == "Rocket")) 
		{
			if (fixAType == "Block")
			{

				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				b2Body* rocketBody = contact->GetFixtureB()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureB()->GetShape();
				rocketShape->m_radius = 64;

				Block* block = static_cast<Block*>(a);
				Rocket* rocket = static_cast<Rocket*>(b);

				if (!block->blockDeleted)
				{
					block->blockDeleted = true;
					//block->BoxDeleted();
					BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
				}
				if (!rocket->rocketDeleted)
				{
					rocket->rocketDeleted = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
				}

			}
			else if (fixBType == "Block") 
			{
				b2Body* rocketBody = contact->GetFixtureA()->GetBody();
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureB()->GetShape();
				rocketShape->m_radius = 64;
				//const_cast<Block*>(fixBType)->BoxDeleted();
				Block* block = static_cast<Block*>(b);
				Rocket* rocket = static_cast<Rocket*>(a);

				if (!block->blockDeleted)
				{
					block->blockDeleted = true;
					//block->BoxDeleted();
					BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
				}
				if (!rocket->rocketDeleted)
				{
					rocket->rocketDeleted = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
				}
			}


			//block->blockDeleted = false;
		}
		if (fixAType == "Player" && fixBType == "Rocket"
			|| fixAType == "Rocket" && fixBType == "Player")
		{
			if (fixAType == "Player")
			{



				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				
				//Block* block = static_cast<Block*>(a);

				//block->blockDeleted = true;
				//block->BoxDeleted();
				//BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
			}
			else if (fixBType == "Player")
			{
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				//const_cast<Block*>(fixBType)->BoxDeleted();
				//Block* block = static_cast<Block*>(b);
				//block->blockDeleted = true;
				//BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
			}


			//block->blockDeleted = false;
		}
	}

	void EndContact(b2Contact* contact) {
		void* fixAType = contact->GetFixtureA()->GetUserData();
		void* fixBType = contact->GetFixtureB()->GetUserData();


		if (fixAType == "Rocket" && fixBType == "Block"
			|| fixAType == "Block" && fixBType == "Rocket") 
		{
			if (fixAType == "Block") 
			{
				
			}
			else if (fixBType == "Block") 
			{
				
			}
		}

		
		
	}
};
#endif