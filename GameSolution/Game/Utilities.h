#pragma once
#include<Core.h>
#include<sstream>
#include<Vector2.h>
#include "Vector3.h"
#include "Matrix3.h"
#include "Matrix4.h"

using std::stringstream;

class Utilities
{
public:
	Utilities(void);
	~Utilities(void);
	void DrawValue( Core::Graphics& graphics, int x, int y, float num );
	void DrawValue( Core::Graphics& graphics, int x, int y, int num );
	void DrawValue( Core::Graphics& graphics, int x, int y, Vector2 num );
	void DrawValue( Core::Graphics& graphics, int x, int y, Matrix3 matrix );
	void DrawValue( Core::Graphics& graphics, int x, int y, Vector3 num );
	void DrawValue( Core::Graphics& graphics, int x, int y, Matrix4 matrix );
	void DrawValue( Core::Graphics& graphics, int x, int y, size_t val );
};

