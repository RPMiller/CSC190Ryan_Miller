#pragma once
#include<map>
#include<vector>
#include <iostream>
#include <fstream>

class Profiler
{
	std::map<char*,std::vector<float>> categories;
	int currentFrame;
public:
	Profiler(void);
	~Profiler(void);
	void NewFrame();
	void AddEntry(char* categoryName, float time);
};

