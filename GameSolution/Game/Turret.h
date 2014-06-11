#pragma once
#include "GameObject.h"
#include "Matrix3.h"
#include "Missile.h"

class Turret : public GameObject
{
protected :
	Matrix4 rotationMatrix;
	Missile** missiles;
	Vector3 baseMissileVelocity;
	float reloadTimeLeft;
	float baseReloadTime;
	int numberOfMissiles;

public:
	Turret();
	~Turret(void);
	void UpdateTurretRotation();
	void Draw(Core::Graphics graphics);
	void Update(float dt);
	void SetShipRotationMatrix(Matrix4 rotation);
	void Fire();
	Missile** GetMissiles();
	int GetNumberOfMissiles();
	void SetBaseMissileVelocity(Vector3 velocity);
	virtual void Destroy();
};

