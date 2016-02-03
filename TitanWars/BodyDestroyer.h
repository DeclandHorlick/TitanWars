#pragma once


#include <Box2D/Box2D.h>
#include <vector>
#ifndef BODYDESTROYER
#define BODYDESTROYER

//put your includes here for box2d.

class BodyDestroyer {
private:
	BodyDestroyer(b2World*); 
	b2World* world;
	std::vector<b2Body*> bodies;

public:
	static BodyDestroyer* GetInstance(b2World*);
	static BodyDestroyer* GetInstance();

	void AddBody(b2Body*);
	void DestroyBodies();
};
#endif