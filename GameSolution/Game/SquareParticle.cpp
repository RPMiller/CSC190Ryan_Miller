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
		Vector2* particleLines = new Vector2[numberOfParticleLines];
		particleLines[0] = Vector2(-particleSize,particleSize);
		particleLines[1] = Vector2(particleSize,particleSize);
		particleLines[2] = Vector2(particleSize,-particleSize);
		particleLines[3] = Vector2(-particleSize,-particleSize);
		particleLines[4] = Vector2(-particleSize,particleSize);
		shapes[i] = Shape(particleLines,numberOfParticleLines,translationMatrix);
	}
}


SquareParticle::~SquareParticle(void)
{
}
