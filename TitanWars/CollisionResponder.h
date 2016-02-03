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
//
class CollisionResponder : public b2ContactListener {
public:

	void BeginContact(b2Contact* contact)
	{
		void* fixAType = contact->GetFixtureA()->GetUserData();
		void* fixBType = contact->GetFixtureB()->GetUserData();

		if (fixAType == "Rocket" && fixBType == "Block"
			|| fixAType == "Block" && fixBType == "Rocket") 
		{
			if (fixAType == "Block") 
			{
				b2Body* bodyUserBody= contact->GetFixtureA()->GetBody();
				static_cast<Block*>(fixAType)->BoxDeleted();
				//Block* block = static_cast<Block*>(fixAType);
				//block->BoxDeleted();
				BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
			}
			else if (fixBType == "Block") 
			{
				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				static_cast<Block*>(fixBType)->BoxDeleted();
				//Block* block = static_cast<Block*>(fixBType);
				//block->BoxDeleted();
				BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
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