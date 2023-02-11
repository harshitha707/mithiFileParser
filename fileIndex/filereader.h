#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>

class filereader {
public:
	//making function called words which contains string parameters
	std::vector<std::string> words(std::string filepathOfStr);
	//static functions affect the whole class instead of a single instance
	static void loadExcludeWords(std::string filepathOfStr);

private:
	//static variables are the same across all instances
	static std::vector<std::string> excludewords;
	
};
