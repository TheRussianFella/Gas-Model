// No Copyright. Vladislav Aleinik 2019
#include "Walls.hpp"

GasContainer::GasContainer(Vector boxSize) :
	containerSize (boxSize)
{}

void GasContainer::moleculeBounce(Molecule& mol)
{
	Vector cur = mol.coords;
	PhysVal_t radius = COLLISION_RADIUS[mol.type];

	if (cur.x < radius)
	{
		cur.x = 2 * radius - cur.x;
		mol.speed.x *= -1;
	}
	else if (cur.x > containerSize.x - radius)
	{
		cur.x = 2 * (containerSize.x - radius) - cur.x;
		mol.speed.x *= -1;
	}

	if (cur.y < radius)
	{
		cur.y = 2 * radius - cur.y;
		mol.speed.y *= -1;
	}
	else if (cur.y > containerSize.y - radius)
	{
		cur.y = 2 * (containerSize.y - radius) - cur.y;
		mol.speed.y *= -1;
	}

	if (cur.z < radius)
	{
		cur.z = 2 * radius - cur.z;
		mol.speed.z *= -1;
	}
	else if (cur.z > containerSize.z - radius)
	{
		cur.z = 2 * (containerSize.z - radius) - cur.z;
		mol.speed.z *= -1;
	}

	mol.coords = cur;
}
