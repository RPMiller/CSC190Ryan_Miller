#include "BasicTurret.h"


BasicTurret::BasicTurret(void)
{
	baseMissileVelocity = Vector3(0,0,400);
	numberOfMissiles = 60;
	missiles = new Missile*[numberOfMissiles];
	for(int i = 0; i < numberOfMissiles;i++)
	{
		missiles[i] = 0;
	}

	int numberOfTurretLines = 6;
	const float turretSize = 8;
	Vector3* turretLines = new Vector3[numberOfTurretLines];
	turretLines[0] = Vector3(-turretSize / 2,-turretSize - (.5f * turretSize),0);
	turretLines[1] = Vector3(0,-turretSize / 2,0);
	turretLines[2] = Vector3(turretSize / 2,-turretSize - (.5f * turretSize),0);
	turretLines[3] = Vector3(turretSize,0,0);
	turretLines[4] = Vector3(-turretSize,0,0);
	turretLines[5] = Vector3(-turretSize / 2,-turretSize - (.5f * turretSize),0);
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];
	shapes[0] = Shape(turretLines,numberOfTurretLines,translationMatrix);
	baseReloadTime = .1f;
	reloadTimeLeft = baseReloadTime;

	/*height = ship.GetHeight();
	width = ship.GetWidth();
	shapes = new Shape[numberOfShapes];

	shapes[0] = ship;*/
}


BasicTurret::~BasicTurret(void)
{
}
