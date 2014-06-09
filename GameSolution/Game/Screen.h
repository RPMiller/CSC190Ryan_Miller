#pragma once
#include "Core.h"
#include "ScreenConstants.h"
#include "Utilities.h"

class Screen
{
protected:
	float score;
	Utilities util;
public:
	Screen(void);
	~Screen(void);
	virtual bool Update(float dt) = 0;
	virtual void Draw(Core::Graphics& graphics) = 0;
	virtual Screen* GetNextScreen() = 0;
	void SetScore(float score);
};

