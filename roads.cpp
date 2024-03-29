#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Segment {
	int start, end;
};

bool cmp(Segment a, Segment b) {
	return a.start < b.start;
}

int main(int argc, char* argv[]) {
	std::ifstream input(argv[1]);
	int n, m;
	input >> n >> m;

	std::vector<Segment> segments(n);
	for (int i = 0; i < n; i++) {
		input >> segments[i].start >> segments[i].end;
	}

	std::sort(segments.begin(), segments.end(), cmp);

	int teams = 0;
	int cur_start = -1, cur_end = -1;
	for (int i = 0; i < n; i++) {
		int start = segments[i].start, end = segments[i].end;
		if (start <= cur_end) {
			cur_end = std::max(cur_end, end);
		}
		else {
			int len = cur_end - cur_start + 1;
			if (len >= m) {
				teams++;
			}
			cur_start = start;
			cur_end = end;
		}
	}

	int len = cur_end - cur_start + 1;

	std::cout << teams << std::endl;

	return 0;
}