#include "Profiler.h"


Profiler::Profiler(void)
{
	currentFrame = -1;
}


Profiler::~Profiler(void)
{
	std::ofstream file;
	file.open ("profiler.csv");
	for(auto mapIterator = categories.begin(); mapIterator != categories.end(); mapIterator++) 
	{
		file << mapIterator->first << ",";
		std::vector<float> nextVector = mapIterator->second;
		for(auto vectorIterator = nextVector.begin(); vectorIterator != nextVector.end(); vectorIterator++) 
		{
			file << *vectorIterator << ",";
		}
		file << "\n";
	}
	file.close();
	categories.clear();
}

void Profiler::NewFrame()
{
	currentFrame++;
}


void Profiler::AddEntry(char* categoryName, float time)
{
	std::vector<float> current = categories[categoryName];
	if(categories.find(categoryName) == categories.end())
	{
		current = std::vector<float>();
	}
	unsigned currentSize = current.size();
	//buffer with -1 if the index was not assigned
	for(int i = currentSize; i < currentFrame; i++)
	{
		current.insert(current.begin() + i,-1);
	}
	current.insert(current.begin() + currentFrame,time);
	categories[categoryName] = current;
}