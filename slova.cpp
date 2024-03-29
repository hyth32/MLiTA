#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>


int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Not enough parameters" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);

	std::string word;
	in >> word;

	std::map<char, int> word_letters;
	for (char c : word) {
		word_letters[c]++;
	}

	std::vector<std::pair<int, std::string>> valid_words;
	int total_score = 0;

	std::string dict_word;
	while (in >> dict_word) {
		std::map<char, int> dict_word_letters;
		for (char c : dict_word) {
			dict_word_letters[c]++;
		}
		bool valid = true;
		for (auto p : dict_word_letters) {
			if (word_letters[p.first] < p.second) {
				valid = false;
				break;
			}
		}
		
		if (valid) {
			valid_words.push_back({static_cast<int>(dict_word.size()), dict_word});
			total_score += dict_word.size();
		}
	}

	std::sort(valid_words.begin(), valid_words.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
		return (a.first != b.first ? a.first > b.first : a.second < b.second);
	});

	std::cout << total_score << std::endl;
	for (auto p : valid_words) {
		std::cout << p.second << std::endl;
	}


    return 0;
}

