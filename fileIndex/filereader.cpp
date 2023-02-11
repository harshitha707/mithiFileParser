#include "filereader.h"
std::vector<std::string> filereader::excludewords;

std::vector<std::string> filereader::words(std::string filepathOfStr) {
	std::ifstream openFile;
	//reading the file
	openFile.open(filepathOfStr, std::ios::in);
	//create a vector of strings that we can add to to output later
	std::vector<std::string> output;
	//create a string to use as a place to load each word into
	std::string thisWord;

	//while we still have words we haven't read yet
	while (openFile >> thisWord) {
		//this word is good
		bool isbad = false;
		//for every word in the bad words list
		for (auto& badword : excludewords) {
			//if this word is the same as a bad word
			if (thisWord == badword) {
				//this word is now bad
				isbad = true;
			}
		}
		//the loop is over, if the word was not found to be bad
		if (!isbad) {
			//then we can add it to the output
			output.push_back(thisWord);
		}
	}

	std::unordered_set<std::string> s(output.begin(), output.end());
	output.assign(s.begin(), s.end());

	//lowercasing and removing non letters 
	for (auto& word : output) {
		std::transform(word.begin(), word.end(), word.begin(), std::tolower);
		std::erase_if(word, [](char& c) {return !std::isalpha(static_cast<unsigned char> (c)); });
	}

	//sorting the file lexicographically once all words are added
	std::sort(output.begin(), output.end());

	//finally return the output vector we created
	return output;
}

void filereader::loadExcludeWords(std::string filepathOfStr) {
	std::ifstream openFile;
	//reading the file
	openFile.open(filepathOfStr, std::ios::in);
	//create a place to store each word
	std::string thisWord;


	//for every word in the badword file
	while (openFile >> thisWord) {
		//add it to the static list of bad words
		excludewords.push_back(thisWord);
	}
}
