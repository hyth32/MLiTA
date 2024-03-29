#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}
	std::ifstream in(argv[1]);

	int m;
	in >> m;

	for (int i = 0; i < m; i++) {
		int p, q;
		in >> p >> q;
		if ((p ^ q) % 2 == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "2" << std::endl;
		}
	}

    return 0;
}

