#include "Screen.h"


Screen::Screen(void)
{
}


Screen::~Screen(void)
{
}

void Screen::SetScore(float score)
{
	if(score < 0)
	{
		score = 0;
	}
	Screen::score = score;
}