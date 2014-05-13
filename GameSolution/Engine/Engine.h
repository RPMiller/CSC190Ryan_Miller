#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "ExportHeader.h"
#include "Vector2.h"
#include "Matrix2.h"
#include "Vector3.h"
#include "Matrix3.h"

namespace Engine
{
	// your stuff goes here...
	// use ENGINE_SHARED to indicate a function or class that you want to export
	ENGINE_SHARED void Init();

	ENGINE_SHARED bool sampleFunctionThatReturnsTrue();
}

#endif // _ENGINE_H_