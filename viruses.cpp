#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

const int MAXN = 1000;

int n, m;
bool grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

int bfs(std::ifstream& in) {
	std::queue<std::pair<int, int>> q;
	int steps = 0;

	for (int i = 0; i < m; i++) {
		int x, y;
		in >> x >> y;
		x--;
		y--;
		grid[x][y] = true;
		visited[x][y] = true;
		q.push({ x, y });
	}

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x > 0 && !visited[x - 1][y]) {
				visited[x - 1][y] = true;
				grid[x - 1][y] = true;
				q.push({ x - 1, y });
			}
			if (x < n - 1 && !visited[x + 1][y]) {
				visited[x + 1][y] = true;
				grid[x + 1][y] = true;
				q.push({ x + 1, y });
			}
			if (y > 0 && !visited[x][y - 1]) {
				visited[x][y - 1] = true;
				grid[x][y - 1] = true;
				q.push({ x, y - 1 });
			}
			if (y < n - 1 && !visited[x][y + 1]) {
				visited[x][y + 1] = true;
				grid[x][y + 1] = true;
				q.push({ x, y + 1 });
			}
		}
		steps++;
	}

	return steps - 1;
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cout << "Not enough parameters" << std::endl;
		return 1;
	}

	std::ifstream in(argv[1]);
	
	in >> n >> m;
	memset(grid, false, sizeof(grid));
	memset(visited, false, sizeof(visited));

	int steps = bfs(in);
	std::cout << steps << std::endl;
	in.close();

    return 0;
}

