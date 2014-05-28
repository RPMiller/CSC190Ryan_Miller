#include "Turret.h"
#include "Utilities.h"

Turret::Turret()
{

}

void Turret::TransformToBasicTurret()
{
	numberOfMissiles = 20;
	missiles = new Missile*[numberOfMissiles];
	for(int i = 0; i < numberOfMissiles;i++)
	{
		missiles[i] = 0;
	}

	int numberOfTurretLines = 6;
	const float turretSize = 8;
	Vector2* turretLines = new Vector2[numberOfTurretLines];
	turretLines[0] = Vector2(-turretSize / 2,-turretSize - (.5f * turretSize));
	turretLines[1] = Vector2(0,-turretSize / 2);
	turretLines[2] = Vector2(turretSize / 2,-turretSize - (.5f * turretSize));
	turretLines[3] = Vector2(turretSize,0);
	turretLines[4] = Vector2(-turretSize,0);
	turretLines[5] = Vector2(-turretSize / 2,-turretSize - (.5f * turretSize));
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];
	shapes[0] = Shape(turretLines,numberOfTurretLines,translationMatrix);
	baseReloadTime = .5;
	reloadTimeLeft = baseReloadTime;

	/*height = ship.GetHeight();
	width = ship.GetWidth();
	shapes = new Shape[numberOfShapes];

	shapes[0] = ship;*/
}


Turret::~Turret(void)
{
}

void Turret::UpdateTurretRotation()
{
	Core::Input input;
	Vector2 mouseVector = Vector2((float)input.GetMouseX(),(float)input.GetMouseY());
	input;
	Vector2 shipToMouse = mouseVector - position;
	Vector2 normal = Normalized(shipToMouse);
	Vector2 cw = PerpCW(normal);
	rotationMatrix = Matrix3(normal,cw);
	rotationMatrix.Rotate(3.1459f / 2);
}

void Turret::Draw(Core::Graphics graphics)
{
	UpdateTurretRotation();
	position = position + velocity;
	translationMatrix = Matrix3();
	translationMatrix.Translate(position);
	translationMatrix = rotationMatrix * translationMatrix;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetTranslationMatrix(translationMatrix);
		(shapes + i)->DrawShape(graphics);
	}
	for(int i = 0; i < numberOfMissiles;i++)
	{
		Missile* next = missiles[i];
		if(next == 0)
		{

		}
		else
		{
			if(next->CheckDead())
			{
				delete(next);
				missiles[i] = 0;
			}
			else
			{
				next->Draw(graphics);
			}
		}
	}

	//Utilities util;
	//util.DrawValue(graphics,0,600,rotationMatrix);
}

void Turret::Update(float dt)
{
	GameObject::Update(dt);
	reloadTimeLeft -= dt;

	for(int i = 0; i < numberOfMissiles;i++)
	{
		Missile* next = missiles[i];
		if(next == 0)
		{

		}
		else
		{
			if(next->CheckDead())
			{
				delete(next);
				missiles[i] = 0;
			}
			else
			{
				next->Update(dt);
			}
		}
	}
}

void Turret::Fire()
{
	Vector2 baseVelocity(0,-200);
	bool missileReady = true;
	for(int i = 0; reloadTimeLeft <= 0 && i < numberOfMissiles && missileReady;i++)
	{
		Missile* next = missiles[i];
		if(next == 0)
		{
 			missiles[i] = new Missile(position,baseVelocity * rotationMatrix);
			missileReady = false;
			reloadTimeLeft = baseReloadTime;
		}
	}
}