#include "RenderUI.h"
#include "Engine.h"

Vector2 basicLeft, basicRight, basicResult;
Vector2 perpOriginal, perpNormal, perpCw,perpCcw;
Vector2 dot1, dot2, proj,rej;
Vector2 lerpAVector,lerpBVector,lerpAMinusBVector,lerpAVectorLerpPortion,lerpBVectorLerpPortion,lerpLerpResultVector;


void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data)
{
	basicLeft = data.scalar1 * Vector2(data.x1,data.y1);
	basicRight = data.scalar2 * Vector2(data.x2, data.y2);
	if(data.add)
	{
		basicResult = basicLeft + basicRight;
	}
	else
	{
		basicResult = basicLeft - basicRight;
	}
}

void myPerpendicularDataCallback(const PerpendicularData& data)
{
	perpOriginal = Vector2(data.x,data.y);
	perpNormal = Normalized(perpOriginal);
	perpCcw = PerpCCW(perpOriginal);
	perpCw = PerpCW(perpOriginal);
}

void myDotProductDataCallback(const DotProductData& data)
{
	dot1 = Vector2(data.v1i,data.v1j);
	dot2 = Vector2(data.v2i,data.v2j);
	if(data.projectOntoLeftVector)
	{
		proj = projLR(Vector2(data.v2i,data.v2j),Vector2(data.v1i,data.v1j));
		rej = rejLR(Vector2(data.v2i,data.v2j),Vector2(data.v1i,data.v1j));
	}
	else
	{
		proj = projLR(Vector2(data.v1i,data.v1j),Vector2(data.v2i,data.v2j));
		rej = rejLR(Vector2(data.v1i,data.v1j),Vector2(data.v2i,data.v2j));
	}
}

void myLerpDataCallback(const LerpData& data)
{
	lerpAVector = Vector2(data.a_i,data.a_j);
	lerpBVector = Vector2(data.b_i,data.b_j);
	lerpAMinusBVector = lerpBVector - lerpAVector;
	lerpAVectorLerpPortion = (1 - data.beta)*lerpAVector;
	lerpBVectorLerpPortion = data.beta * lerpBVector;
	lerpLerpResultVector = lerpAVectorLerpPortion + lerpBVectorLerpPortion;
}

int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback,basicLeft,basicRight,basicResult);
	renderUI.setPerpendicularData(perpOriginal,perpNormal,perpCw,perpCcw,myPerpendicularDataCallback); 
	renderUI.setDotProductData(dot1,dot2,proj,rej,myDotProductDataCallback);
	renderUI.setLerpData(lerpAVector,lerpBVector,lerpAMinusBVector,lerpAVectorLerpPortion,lerpBVectorLerpPortion,lerpLerpResultVector,myLerpDataCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}