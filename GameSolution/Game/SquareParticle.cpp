#include "SquareParticle.h"


SquareParticle::SquareParticle(void)
{
	numberOfShapes = 4;
	shapes = new Shape[numberOfShapes];
	shouldVaryColor = true;

	int numberOfParticleLines = 5;
	float maxParticleSize = 7;
	float minParticleSize = 2;

	for(int i = 0; i < numberOfShapes; i ++)
	{
		float particleSize = maxParticleSize - ( (i + 1) * maxParticleSize / numberOfShapes) + minParticleSize;
		Vector3* particleLines = new Vector3[numberOfParticleLines];
		particleLines[0] = Vector3(-particleSize,particleSize,0);
		particleLines[1] = Vector3(particleSize,particleSize,0);
		particleLines[2] = Vector3(particleSize,-particleSize,0);
		particleLines[3] = Vector3(-particleSize,-particleSize,0);
		particleLines[4] = Vector3(-particleSize,particleSize,0);
		shapes[i] = Shape(particleLines,numberOfParticleLines,translationMatrix);
	}
}


SquareParticle::~SquareParticle(void)
{
}
