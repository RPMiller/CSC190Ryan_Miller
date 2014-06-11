#include "Turret.h"
#include "Utilities.h"

Turret::Turret()
{

}


Turret::~Turret(void)
{
	
}

void Turret::Destroy()
{
	for(int i = 0; i < numberOfMissiles ; i++)
	{
		Missile* missile = missiles[i];
		if(missile != 0)
		{
			missile->Destroy();
			delete missile;
		}
	}
	delete [] missiles;
	GameObject::Destroy();
}

void Turret::UpdateTurretRotation()
{
	Core::Input input;
	Vector3 mouseVector = Vector3((float)input.GetMouseX(),(float)input.GetMouseY(),0);
	input;
	Vector3 shipToMouse = mouseVector - position;
	Vector3 normal = Normalized(shipToMouse);
	Vector3 cw = PerpCW(normal);
	//rotationMatrix = Matrix3(normal,cw);
	rotationMatrix.RotateAroundZ(3.1459f / 2);
	color = Color(0,255,255);
}

void Turret::Draw(Core::Graphics graphics)
{
	/*UpdateTurretRotation();
	position = position + velocity;
	translationMatrix = Matrix4();
	translationMatrix.Translate(position);
	translationMatrix = rotationMatrix * translationMatrix;
	for(int i = 0 ; i < numberOfShapes ; i++)
	{
		(shapes + i)->SetTranslationMatrix(translationMatrix);
		(shapes + i)->DrawShape(graphics,position);
	}*/
	for(int i = 0; i < numberOfMissiles;i++)
	{
		Missile* next = missiles[i];
		if(next == 0)
		{

		}
		else
		{
			if(!next->CheckDead())
			{
				next->SetColor(color);
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
				next->Destroy();
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
	if(isAlive)
	{
		bool missileReady = true;
		for(int i = 0; reloadTimeLeft <= 0 && i < numberOfMissiles && missileReady;i++)
		{
			Missile* next = missiles[i];
			if(next == 0)
			{
				missiles[i] = new Missile(position,baseMissileVelocity,7.0f);
				missileReady = false;
				reloadTimeLeft = baseReloadTime;
			}
		}
	}
}

Missile** Turret::GetMissiles()
{
	return missiles;
}

int Turret::GetNumberOfMissiles()
{
	return numberOfMissiles;
}

void Turret::SetBaseMissileVelocity(Vector3 velocity)
{
	baseMissileVelocity = velocity;
}