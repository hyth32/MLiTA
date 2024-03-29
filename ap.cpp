#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cmath>

bool CanFormAP(std::vector<int>& nums) {
	int n = nums.size();
	if (n < 3) {
		return true;
	}

	std::sort(nums.begin(), nums.end());
	int diff = nums[1] - nums[0];
	for (int i = 2; i < n; i++) {
		if (nums[i] - nums[i - 1] != diff) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Not enough arguments" << std::endl;
		return 1;
	}
	std::ifstream in(argv[1]);

	int l;
	in >> l;
	while (l--) {
		int n;
		in >> n;

		std::vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			in >> nums[i];
		}
		if (CanFormAP(nums)) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
	}


    return 0;
}
