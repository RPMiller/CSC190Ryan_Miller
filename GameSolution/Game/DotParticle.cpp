#include "DotParticle.h"


DotParticle::DotParticle(void)
{
	numberOfShapes = 1;
	int numberOfParticleLines = 2;
	shapes = new Shape[numberOfShapes];
	shouldVaryColor = false;

	Vector3* particleLines = new Vector3[numberOfParticleLines];
	particleLines[0] = Vector3(0,0,0);
	particleLines[1] = Vector3(1,0,0);

	shapes[0] = Shape(particleLines,numberOfParticleLines,translationMatrix);
}


DotParticle::~DotParticle(void)
{
}
