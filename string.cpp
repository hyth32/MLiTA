#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);

	int n;
	std::string s;
	in >> n >> s;
	
	int maxLen = 0, start = 0;
	std::string maxSubstr = "";

	for (int i = 0; i < n; i++) {
		std::unordered_set<char> unique;
		int j = i;
		while (j < n && unique.insert(s[j]).second) {
			j++;
		}

		int len = j - i;
		if (len > maxLen || (len == maxLen && s.substr(i, len) < maxSubstr)) {
			maxLen = len;
			maxSubstr = s.substr(i, len);
			start = i;
		}
	}

	std::cout << maxSubstr << std::endl;

    return 0;
}

