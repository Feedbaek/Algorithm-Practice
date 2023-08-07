#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool visited[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int r, int c, vector<string>& maps) {
	int ret = 0;
	queue<pair<int, int> > q;

	q.push(make_pair(r, c));
	visited[r][c] = true;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		ret += maps[r][c] - '0';
		for (int i=0; i<4; ++i) {
			int f = r + dir[i][0];
			int s = c + dir[i][1];
			if (f >= 0 && f < maps.size() && s >= 0 && s < maps[0].size() && \
			!visited[f][s] && maps[f][s] != 'X') {
				q.push(make_pair(f, s));
				visited[f][s] = true;
			}
		}
		q.pop();
	}
	return ret;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	for (int i=0; i<maps.size(); ++i)
		for (int j=0; j<maps[i].size(); ++j)
			if (!visited[i][j] && maps[i][j] != 'X')
				answer.push_back(bfs(i, j, maps));

	if (answer.empty())
		answer.push_back(-1);

	sort(answer.begin(), answer.end());
	return answer;
}
