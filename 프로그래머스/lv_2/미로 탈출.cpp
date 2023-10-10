#include <string>
#include <vector>
#include <deque>

using namespace std;

bool possible(bool (*visited)[100], int row, int col, int x, int y, vector<string>& maps) {
	if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y] || maps[x][y] == 'X')
		return false;
	return true;
}

int solution(vector<string> maps) {
	int answer = 0;
	bool l_visited[100][100] = {};
	bool e_visited[100][100] = {};
	deque<vector<int>> q;
	int row = maps.size(), col = maps[0].size();

	for (int i=0; i<row; ++i)
		for (int j=0; j<col; ++j)
			if (maps[i][j] == 'S')
				q.push_back({i, j, 0});

	while (!q.empty()) {
		vector<int> v = q.front();
		q.pop_front();
		if (l_visited[v[0]][v[1]])
			continue;
		l_visited[v[0]][v[1]] = true;
		if (maps[v[0]][v[1]] == 'L') {
			answer += v[2];
			q.clear();
			q.push_back({v[0], v[1], 0});
			break;
		}
		if (possible(l_visited, row, col, v[0] + 1, v[1], maps))
			q.push_back({v[0] + 1, v[1], v[2] + 1});
		if (possible(l_visited, row, col, v[0] - 1, v[1], maps))
			q.push_back({v[0] - 1, v[1], v[2] + 1});
		if (possible(l_visited, row, col, v[0], v[1] + 1, maps))
			q.push_back({v[0], v[1] + 1, v[2] + 1});
		if (possible(l_visited, row, col, v[0], v[1] - 1, maps))
			q.push_back({v[0], v[1] - 1, v[2] + 1});
	}
	while (!q.empty()) {
		vector<int> v = q.front();
		q.pop_front();
		if (e_visited[v[0]][v[1]])
			continue;
		e_visited[v[0]][v[1]] = true;
		if (maps[v[0]][v[1]] == 'E') {
			answer += v[2];
			return answer;
		}
		if (possible(e_visited, row, col, v[0] + 1, v[1], maps))
			q.push_back({v[0] + 1, v[1], v[2] + 1});
		if (possible(e_visited, row, col, v[0] - 1, v[1], maps))
			q.push_back({v[0] - 1, v[1], v[2] + 1});
		if (possible(e_visited, row, col, v[0], v[1] + 1, maps))
			q.push_back({v[0], v[1] + 1, v[2] + 1});
		if (possible(e_visited, row, col, v[0], v[1] - 1, maps))
			q.push_back({v[0], v[1] - 1, v[2] + 1});
	}
	return -1;
}
