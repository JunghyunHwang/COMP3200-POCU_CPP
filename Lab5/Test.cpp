#include "Test.h"

void lab5::TestOfficial()
{
	Lawn* lawn = new RectangleLawn(10, 20);
	unsigned int area = lawn->GetArea();
	unsigned int grassPrice = lawn->GetGrassPrice(eGrassType::BERMUDA);
	unsigned int sodRollsCount = lawn->GetMinimumSodRollsCount();

	assert(area == 200);
	assert(grassPrice == 1600);
	assert(sodRollsCount == 667);

	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;

	unsigned int fencePrice = rectangleLawn->GetFencePrice(eFenceType::RED_CEDAR);
	unsigned int fencesCount = rectangleLawn->GetMinimumFencesCount();

	assert(fencePrice == 360);
	assert(fencesCount == 240);
}

void lab5::TestLawnArea()
{
	Lawn* t = new EquilateralTriangleLawn(5);
	assert(t->GetArea() == 11);

	Lawn* s = new SquareLawn(10);
	assert(s->GetArea() == 100);
	
	Lawn* c = new CircleLawn(10);
	assert(c->GetArea() == 314);
}
