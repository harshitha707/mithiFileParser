#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include "filereader.h"



int main() {
	//load excluded words into filereader memory
	filereader::loadExcludeWords("excludeWords.txt");

	//create a filereader
	filereader fr;
	//create a vector equal to the output of the filereader
	auto page1 = fr.words("page1.txt");
	auto page2 = fr.words("page2.txt");
	auto page3 = fr.words("page3.txt");
	//for every word in the pages
	/*
	for (auto& word : page1) {
		//print the word
		std::cout << word << " ";
	}

	std::cout << "\n";

	for (auto& word : page2) {
		//print the word
		std::cout << word << " ";
	}

	std::cout << "\n";

	for (auto& word : page3) {
		//print the word
		std::cout << word << " ";
	}
	*/

	//maps contain a key and then a value at that key
	//the value is a set which is like vector but it can't contain duplicates
	std::map<std::string, std::set<int>> wordplaces;
	//for every word in page1
	for (auto& word : page1) {
		//add that word to the key and add a 1 to the set of page numbers
		wordplaces[word].insert(1);
	}
	//for every word in page2
	for (auto& word : page2) {
		//either add or update that key and add a 2 to the set of page numbers
		wordplaces[word].insert(2);
	}
	//for every word in page3
	for (auto& word : page3) {

		//either add or update that key and add a 3 to the set of page numbers
		wordplaces[word].insert(3);
	}
	//create an output file
	std::ofstream output;
	output.open("index.txt", std::ios::out);

	//for all the words combined
	for (auto& word : wordplaces) {
		//print the word to file
		output << word.first << " : ";
		//counter for comma check
		int i = 0;
		//for every page this word was on
		for (auto& pages : word.second) {
			//print the page number to file
			output << pages;
			//if it's not the last one
			if (++i != word.second.size()) {
				//add a comma to file
				output << ", ";
			}
		}
		//add a new line to file ready for the next word
		output << '\n';
	}
	//close file once we're done
	output.close();
	//we're done
	return EXIT_SUCCESS;

}





























/*
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	ifstream page1, page2, page3;
	ofstream index;
	//f1,f2,f3 for fetching strings from page 1, 2 , 3
	string f1, f2, f3; 

	page1.open("page1.txt", ios::in);
	page2.open("page2.txt", ios::in);
	page3.open("page3.txt", ios::in);
	index.open("index.txt", ios::out);

	while (getline(page1, f1)) {
		index << f1 << endl;
	}

	while (getline(page2, f2)) {
		index << f2 << endl;
	}

	while (getline(page3, f3)) {
		index << f2 << endl;
	}

	page1.close();
	page2.close();
	page3.close();
	index.close();

}
*/