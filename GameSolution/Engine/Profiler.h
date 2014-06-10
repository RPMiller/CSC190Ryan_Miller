#pragma once
#include<map>
#include<vector>
#include <iostream>
#include <fstream>

#pragma warning(disable : 4251)

class __declspec(dllexport)Profiler
{
	std::map<char*,std::vector<float>> categories;
	int currentFrame;
public:
	Profiler(void);
	~Profiler(void);
	void NewFrame();
	void AddEntry(char* categoryName, float time);
};

#pragma warning(default : 4251)