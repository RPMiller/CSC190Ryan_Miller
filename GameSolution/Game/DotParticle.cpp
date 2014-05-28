#include "DotParticle.h"


DotParticle::DotParticle(void)
{
	numberOfShapes = 1;
	shapes = new Shape[numberOfShapes];
	shouldVaryColor = true;

	int numberOfParticleLines = 2;

	Vector2* particleLines = new Vector2[numberOfParticleLines];
	particleLines[0] = Vector2(0,0);
	particleLines[1] = Vector2(1,0);

	shapes[0] = Shape(particleLines,numberOfParticleLines,translationMatrix);
}


DotParticle::~DotParticle(void)
{
}
