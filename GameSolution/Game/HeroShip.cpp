#include "HeroShip.h"

HeroShip::HeroShip()
{

}

HeroShip::~HeroShip(void)
{
	//delete shapes;
}

void HeroShip::Init(Vector2 position)
{
	HeroShip::position = position;

	acceleration = 2;
	const int numberOfShipLines = 7;
	const float shipSize = 32;
	Vector2* shipLines = new Vector2[numberOfShipLines];
	shipLines[0] = Vector2(0,-shipSize);
	shipLines[1] = Vector2(shipSize,0);
	shipLines[2] = Vector2(shipSize,shipSize);
	shipLines[3] = Vector2(0,shipSize / 2);
	shipLines[4] = Vector2(-shipSize,shipSize);
	shipLines[5] = Vector2(-shipSize,0);
	shipLines[6] = Vector2(0,-shipSize);
	Shape ship = Shape(shipLines,numberOfShipLines,translationMatrix);
	turret.TransformToBasicTurret();

	numberOfShapes = 1;
	height = ship.GetHeight();
	width = ship.GetWidth();
	shapes = new Shape[numberOfShapes];

	shapes[0] = ship;
}

void HeroShip::Draw(Core::Graphics graphics)
{/*
	Matrix3 turretRotateMatrix;
	turretRotateMatrix.Rotate(turretRadsRotate);
	Matrix3 turretTranslate;
	turretTranslate.TranslateY(-turretYOffSet);

	translationMatrix.Translate(velocity);
	Matrix3 drawMatrix;
	drawMatrix.Rotate(radsRotated);
	turret.SetTranslationMatrix(turretRotateMatrix * turretTranslate * drawMatrix * translationMatrix);*/
	GameObject::Draw(graphics);
	turret.SetPosition(position);
	turret.Draw(graphics);
	//turret.DrawShape(graphics);
}

void HeroShip::Fire()
{
	turret.Fire();
}