#pragma once
#include "GameObject.h"
#include "Matrix3.h"
#include "Missile.h"

class Turret : public GameObject
{
	Matrix3 rotationMatrix;
	Missile** missiles;
	float reloadTimeLeft;
	float baseReloadTime;
	int numberOfMissiles;
public:
	Turret();
	~Turret(void);
	void TransformToBasicTurret();
	void UpdateTurretRotation();
	void Draw(Core::Graphics graphics);
	void Update(float dt);
	void SetShipRotationMatrix(Matrix3 rotation);
	void Fire();
};

