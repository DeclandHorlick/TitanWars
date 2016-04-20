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
#include "Rifle.h"
#include "SoundManager.h"
#include<vector>
//
class CollisionResponder : public b2ContactListener {
public:
	int magicBounces = 0;
	int carBounces = 0;


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
					SoundManager::GetInstance()->bombBang();
					rocket->rocketDeleted = true;
					rocket->playAnimation = true;
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
					SoundManager::GetInstance()->bombBang();
					rocket->rocketDeleted = true;
					rocket->playAnimation = true;
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
				
				b2Body* rocketBody = contact->GetFixtureB()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureB()->GetShape();


				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				Rocket* rocket = static_cast<Rocket*>(b);
				rocketShape->m_radius = 64;

				if (!rocket->rocketDeleted)
				{
					SoundManager::GetInstance()->bombBang();
					rocket->rocketDeleted = true;
					rocket->playAnimation = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					if (rocket->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(20);
					}
					if (PlayerManager::GetInstance()->getPlayer1()->getHealth() <= 0 )
					{
						SoundManager::GetInstance()->bombBang();
					}
				}

			}
			else if (fixBType == "Player")
			{
				b2Body* rocketBody = contact->GetFixtureA()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureA()->GetShape();
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Rocket* rocket = static_cast<Rocket*>(a);
				rocketShape->m_radius = 64;

				if (!rocket->rocketDeleted)
				{
					SoundManager::GetInstance()->bombBang();
					rocket->rocketDeleted = true;
					rocket->playAnimation = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					if (rocket->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(20);
					}
					if (PlayerManager::GetInstance()->getPlayer1()->getHealth() <= 0 )
					{
						SoundManager::GetInstance()->bombBang();
					}
				}
			}
		}
		if (fixAType == "Player2" && fixBType == "Rocket"
			|| fixAType == "Rocket" && fixBType == "Player2")
		{
			if (fixAType == "Player2")
			{
				
				b2Body* rocketBody = contact->GetFixtureB()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureB()->GetShape();

				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();

				Rocket* rocket = static_cast<Rocket*>(b);
				rocketShape->m_radius = 64;

				if (!rocket->rocketDeleted)
				{
					
					rocket->rocketDeleted = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					if (rocket->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(20);
					}
					if (PlayerManager::GetInstance()->getPlayer2()->getHealth() <= 0)
					{
						SoundManager::GetInstance()->bombBang();
					}
				}

			}
			else if (fixBType == "Player2")
			{
				b2Body* rocketBody = contact->GetFixtureA()->GetBody();
				b2Shape* rocketShape = contact->GetFixtureA()->GetShape();
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Rocket* rocket = static_cast<Rocket*>(a);
				rocketShape->m_radius = 64;

				if (!rocket->rocketDeleted)
				{
					
					rocket->rocketDeleted = true;
					PlayerManager::GetInstance()->GetPlayersRockets(rocket->m_owner)->clear();
					BodyDestroyer::GetInstance()->AddBody(rocketBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					if (rocket->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(20);
					}
					if (PlayerManager::GetInstance()->getPlayer2()->getHealth() <= 0)
					{
						SoundManager::GetInstance()->bombBang();
					}
				}
			}

			//block->blockDeleted = false;
		}










		if (fixAType == "Player" && fixBType == "Magic"
			|| fixAType == "Magic" && fixBType == "Player")
		{
			if (fixAType == "Player")
			{

				b2Body* magicBody = contact->GetFixtureB()->GetBody();
				


				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				Rifle* rifle = static_cast<Rifle*>(b);
				
				if (!rifle->rifleDeleted)
				{
					SoundManager::GetInstance()->niceShot();
					rifle->rifleDeleted = true;
					rifle->playAnimation = true;
					std::vector<Rifle*> *r = PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
					std::vector<Rifle*>::iterator it = r->begin();
					if (rifle->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(20);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(magicBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					magicBounces = 0;
					
				}

			}
			else if (fixBType == "Player")
			{
				b2Body* magicBody = contact->GetFixtureA()->GetBody();
				
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Rifle* rifle = static_cast<Rifle*>(a);
				

				if (!rifle->rifleDeleted)
				{
					SoundManager::GetInstance()->niceShot();
					rifle->rifleDeleted = true;
					rifle->playAnimation = true;
					std::vector<Rifle*> *r = PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
					std::vector<Rifle*>::iterator it = r->begin();
					if (rifle->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(20);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(magicBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					magicBounces = 0;
				}
			}
		}
		if (fixAType == "Player2" && fixBType == "Magic"
			|| fixAType == "Magic" && fixBType == "Player2")
		{
			if (fixAType == "Player2")
			{

				b2Body* magicBody = contact->GetFixtureB()->GetBody();
				
				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();

				Rifle* rifle = static_cast<Rifle*>(b);

				

				if (!rifle->rifleDeleted)
				{
					SoundManager::GetInstance()->niceShot();
					rifle->rifleDeleted = true;
					rifle->playAnimation = true;
					std::vector<Rifle*> *r = PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
					std::vector<Rifle*>::iterator it = r->begin();
					if (rifle->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(20);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(magicBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					magicBounces = 0;
				}

			}
			else if (fixBType == "Player2")
			{
				b2Body* magicBody = contact->GetFixtureA()->GetBody();

				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();

				Rifle* rifle = static_cast<Rifle*>(a);

				if (!rifle->rifleDeleted)
				{
					SoundManager::GetInstance()->niceShot();
					rifle->rifleDeleted = true;
					rifle->playAnimation = true;
					std::vector<Rifle*> *r = PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
					std::vector<Rifle*>::iterator it = r->begin();
					if (rifle->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(20);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(magicBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					magicBounces = 0;
				}
			}
			

			//block->blockDeleted = false;
		}








		if (fixAType == "Block" && fixBType == "Magic"
			|| fixAType == "Magic" && fixBType == "Block")
		{
			if (fixAType == "Block")
			{

				b2Body* magicBody = contact->GetFixtureB()->GetBody();



				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				Rifle* rifle = static_cast<Rifle*>(b);

				if (!rifle->rifleDeleted)
				{
					magicBounces += 1;
					rifle->playAnimation = true;
					if (magicBounces == 1 || magicBounces == 3)
					{
						SoundManager::GetInstance()->carBounce();
					}
					else if (magicBounces == 2)
					{
						SoundManager::GetInstance()->fart();
					}
					
					if (magicBounces == 4)
					{
						SoundManager::GetInstance()->haHa();
						rifle->rifleDeleted = true;
						std::vector<Rifle*> *r =  PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
						std::vector<Rifle*>::iterator it = r->begin();
						for (; it != r->end();)
						{
							delete (*it);
							it = r->erase(it);
						}

						BodyDestroyer::GetInstance()->AddBody(magicBody);
						PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
						PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
						magicBounces = 0;
					}
					
				}

			}
			else if (fixBType == "Block")
			{
				b2Body* magicBody = contact->GetFixtureA()->GetBody();

				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Rifle* rifle = static_cast<Rifle*>(a);


				if (!rifle->rifleDeleted)
				{
					magicBounces += 1;
					if (magicBounces == 1 || magicBounces == 3)
					{
						SoundManager::GetInstance()->carBounce();
					}
					else if (magicBounces == 2)
					{
						SoundManager::GetInstance()->fart();
					}
					rifle->playAnimation = true;
					
					if (magicBounces == 4)
					{
						SoundManager::GetInstance()->haHa();
						rifle->rifleDeleted = true;
						std::vector<Rifle*> *r = PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner);
						std::vector<Rifle*>::iterator it = r->begin();
						for (; it != r->end();)
						{
							delete (*it);
							it = r->erase(it);
						}
						BodyDestroyer::GetInstance()->AddBody(magicBody);
						PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
						PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
						magicBounces = 0;
					}
				}
			}
		}















		if (fixAType == "Player" && fixBType == "Car"
			|| fixAType == "Car" && fixBType == "Player")
		{
			if (fixAType == "Player")
			{

				b2Body* carBody = contact->GetFixtureB()->GetBody();
				


				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				Car* car = static_cast<Car*>(b);
				
				if (!car->carDeleted)
				{
					SoundManager::GetInstance()->howDareYou();
					car->carDeleted = true;
					car->playAnimation = true;
					std::vector<Car*> *r = PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
					std::vector<Car*>::iterator it = r->begin();
					if (car->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(30);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(carBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					carBounces = 0;
					
				}

			}
			else if (fixBType == "Player")
			{
				b2Body* carBody = contact->GetFixtureA()->GetBody();
				
				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Car* car = static_cast<Car*>(a);
				

				if (!car->carDeleted)
				{
					SoundManager::GetInstance()->howDareYou();
					car->carDeleted = true;
					car->playAnimation = true;
					std::vector<Car*> *r = PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
					std::vector<Car*>::iterator it = r->begin();
					if (car->m_owner == 2)
					{
						PlayerManager::GetInstance()->getPlayer1()->setHealth(30);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(carBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					carBounces = 0;
				}
			}
		}
		if (fixAType == "Player2" && fixBType == "Car"
			|| fixAType == "Car" && fixBType == "Player2")
		{
			if (fixAType == "Player2")
			{

				b2Body* carBody = contact->GetFixtureB()->GetBody();
				
				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();

				Car* car = static_cast<Car*>(b);

				

				if (!car->carDeleted)
				{
					SoundManager::GetInstance()->howDareYou();
					car->carDeleted = true;
					car->playAnimation = true;
					std::vector<Car*> *r = PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
					std::vector<Car*>::iterator it = r->begin();
					if (car->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(30);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(carBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					carBounces = 0;
				}

			}
			else if (fixBType == "Player2")
			{
				b2Body* carBody = contact->GetFixtureA()->GetBody();

				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();

				Car* car = static_cast<Car*>(a);

				if (!car->carDeleted)
				{
					SoundManager::GetInstance()->howDareYou();
					car->carDeleted = true;
					car->playAnimation = true;
					std::vector<Car*> *r = PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
					std::vector<Car*>::iterator it = r->begin();
					if (car->m_owner == 1)
					{
						PlayerManager::GetInstance()->getPlayer2()->setHealth(30);
					}
					for (; it != r->end();)
					{
						delete (*it);
						it = r->erase(it);
					}
					BodyDestroyer::GetInstance()->AddBody(carBody);
					PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
					PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
					carBounces = 0;
				}
			}
			

			//block->blockDeleted = false;
		}








		if (fixAType == "Block" && fixBType == "Car"
			|| fixAType == "Car" && fixBType == "Block")
		{
			if (fixAType == "Block")
			{

				b2Body* carBody = contact->GetFixtureB()->GetBody();



				b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();
				Car* car = static_cast<Car*>(b);

				if (!car->carDeleted)
				{
					
					car->playAnimation = true;
					
					carBounces += 1;
					if (carBounces == 1 || carBounces == 3 || carBounces == 5)
					{
						SoundManager::GetInstance()->somebodySaveUs();
					}
					else if(carBounces <= 5)
					{
						SoundManager::GetInstance()->stopIt();
					}
					if (carBounces == 6)
					{
						car->carDeleted = true;
						std::vector<Car*> *r =  PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
						std::vector<Car*>::iterator it = r->begin();
						Block* block = static_cast<Block*>(a);
						if (!block->blockDeleted)
						{
							block->blockDeleted = true;
							//block->BoxDeleted();
							BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
						}
						for (; it != r->end();)
						{
							delete (*it);
							it = r->erase(it);
						}

						BodyDestroyer::GetInstance()->AddBody(carBody);
						PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
						PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
						carBounces = 0;
					}
					
				}

			}
			else if (fixBType == "Block")
			{
				b2Body* carBody = contact->GetFixtureA()->GetBody();

				b2Body* bodyUserBody = contact->GetFixtureB()->GetBody();
				Car* car = static_cast<Car*>(a);


				if (!car->carDeleted)
				{
					
					car->playAnimation = true;
					carBounces += 1;
					if (carBounces == 1 || carBounces == 3 || carBounces == 5)
					{
						SoundManager::GetInstance()->somebodySaveUs();
					}
					else if (carBounces <= 5)
					{
						SoundManager::GetInstance()->stopIt();
					}
					if (carBounces == 6)
					{

						car->carDeleted = true;
						std::vector<Car*> *r = PlayerManager::GetInstance()->GetPlayersCar(car->m_owner);
						std::vector<Car*>::iterator it = r->begin();
						Block* block = static_cast<Block*>(a);
						if (!block->blockDeleted)
						{
							block->blockDeleted = true;
							//block->BoxDeleted();
							BodyDestroyer::GetInstance()->AddBody(bodyUserBody);
						}
						for (; it != r->end();)
						{
							delete (*it);
							it = r->erase(it);
						}
						BodyDestroyer::GetInstance()->AddBody(carBody);
						PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
						PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
						carBounces = 0;
					}
				}
			}
		}




		//if (fixAType == "Block" && fixBType == "Magic"
		//	|| fixAType == "Magic" && fixBType == "Block")
		//{
		//	if (fixAType == "Player2")
		//	{

		//		b2Body* magicBody = contact->GetFixtureB()->GetBody();

		//		b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();

		//		Rifle* rifle = static_cast<Rifle*>(b);



		//		if (!rifle->rifleDeleted)
		//		{
		//			
		//			rifle->playAnimation = true;
		//			magicBounces += 1;
		//			if (magicBounces == 4)
		//			{
		//				rifle->rifleDeleted = true;
		//				PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner)->clear();
		//				BodyDestroyer::GetInstance()->AddBody(magicBody);
		//				PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
		//				PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
		//			}
		//		}

		//	}
		//	else if (fixBType == "Player2")
		//	{
		//		b2Body* magicBody = contact->GetFixtureB()->GetBody();

		//		b2Body* bodyUserBody = contact->GetFixtureA()->GetBody();

		//		Rifle* rifle = static_cast<Rifle*>(a);

		//		if (!rifle->rifleDeleted)
		//		{
		//			
		//			rifle->playAnimation = true;
		//			magicBounces += 1;
		//			if (magicBounces == 4)
		//			{
		//				rifle->rifleDeleted = true;
		//				PlayerManager::GetInstance()->GetPlayersMagic(rifle->m_owner)->clear();
		//				BodyDestroyer::GetInstance()->AddBody(magicBody);
		//				PlayerManager::GetInstance()->getPlayer1()->player1Turn = !PlayerManager::GetInstance()->getPlayer1()->player1Turn;
		//				PlayerManager::GetInstance()->getPlayer2()->player2Turn = !PlayerManager::GetInstance()->getPlayer2()->player2Turn;
		//			}
		//		}
		//	}


		//	//block->blockDeleted = false;
		//}
	}
		void EndContact(b2Contact* contact)
		{
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