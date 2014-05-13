#include "RenderUI.h"
#include "Engine.h"

Vector2 basicLeft, basicRight, basicResult;
Vector2 perpOriginal, perpNormal, perpCw,perpCcw;
Vector2 dot1, dot2, proj,rej;
Vector2 lerpAVector,lerpBVector,lerpAMinusBVector,lerpAVectorLerpPortion,lerpBVectorLerpPortion,lerpLerpResultVector;

float span = .3;
Vector2 bottomLeft(-span,-span);
Vector2 topLeft(-span,span);
Vector2 bottomRight(span,-span);
Vector2 topRight(span,span);
Vector2 roofTop(0,span + .25);

int numLines = 0;

Vector2 lines[] = 
{
	bottomLeft,topLeft,
	topLeft,topRight,
	topRight,bottomRight,
	bottomRight,bottomLeft,
	topLeft,roofTop,
	roofTop,topRight
};
const int NUM_MATRIX = 20;
Matrix3 matracies[NUM_MATRIX];
Matrix3 current;

const int NUM_VECTORS = 5;
Vector3 vectorsAffine[NUM_VECTORS] = {Vector3(-1,-1,1),Vector3(-1,1,1),Vector3(1,1,1),Vector3(1,-1,1),Vector3(2,2,1)};

Vector2 basicMultMatrixResultVector;

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
		proj = projLR(dot1,dot2);
		rej = rejLR(dot1,dot2);
	}
	else
	{
		proj = projLR(dot2,dot1);
		rej = rejLR(dot2,dot1);
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

void MyLinearTransformationCallback(const LinearTransformationData& data)
{
	Matrix2 matrix = Matrix2(data.m00,data.m10,data.m01,data.m11);
	Vector2 vector = Vector2(data.v0,data.v1);
	basicMultMatrixResultVector = matrix * vector;
}

void MyMatrixTransformData2DCallback( const MatrixTransformData2D& data)
{
	Matrix3 selected;
	selected.ScaleX(data.scaleX);
	selected.ScaleY(data.scaleY);
	selected.Rotate(data.rotate);
	selected.TranslateX(data.translateX);
	selected.TranslateY(data.translateY);
	matracies[data.selectedMatrix] = selected;

	Matrix3 next;
	for(int i = 0; i < NUM_MATRIX; i++)
	{
		next = next * matracies[i];
	}
	current = next;
}

void MyAffineTransformationCallback(const AffineTransformationData& data)
{
	Matrix3* matrix =  new Matrix3(data.data[0],data.data[3],data.data[6],data.data[1],data.data[4],data.data[7],data.data[2],data.data[5],data.data[8]);
	int vectorStart = 11;
	int vectorEnd = vectorStart + (NUM_VECTORS * 3);
	for(int i = vectorStart; i < vectorEnd; i +=3)
	{
		int vectorIndex = (i - vectorStart) / 3;
		vectorsAffine[vectorIndex] = Vector3(data.data[i - 2],data.data[i - 1],data.data[i]) * *matrix;
	}
	delete(matrix);
}


int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback,basicLeft,basicRight,basicResult);
	renderUI.setPerpendicularData(perpOriginal,perpNormal,perpCw,perpCcw,myPerpendicularDataCallback); 
	renderUI.setDotProductData(dot1,dot2,proj,rej,myDotProductDataCallback);
	renderUI.setLerpData(lerpAVector,lerpBVector,lerpAMinusBVector,lerpAVectorLerpPortion,lerpBVectorLerpPortion,lerpLerpResultVector,myLerpDataCallback);
	renderUI.setLinearTransformationData(basicMultMatrixResultVector,MyLinearTransformationCallback);
	renderUI.setAffineTransformationData(*vectorsAffine,MyAffineTransformationCallback);

	numLines = sizeof(lines)/ (sizeof(*lines) * 2);

	renderUI.set2DMatrixVerticesTransformData(*lines,numLines,*matracies,current,MyMatrixTransformData2DCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}