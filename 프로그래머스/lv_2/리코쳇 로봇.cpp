#include <string>
#include <vector>
#include <deque>

using namespace std;

int cnt_move[101][101];

int solution(vector<string> board) {
	int answer = -1;
	int row = board.size(), col = board[0].size();
	deque<pair<int, int>> q;

	for (int i=0; i<board.size(); ++i) {
		for (int j=0; j<board[i].size(); ++j) {
			if (board[i][j] == 'R') {
				q.push_back(make_pair(i, j));
				cnt_move[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop_front();
		if (board[cur.first][cur.second] == 'G') {
			answer = cnt_move[cur.first][cur.second] - 1;
			break;
		}
		// 상 끝까지
		for (int i=cur.first-1; i>=-1; --i) {
			if (i == -1 || board[i][cur.second] == 'D') {
				if (!cnt_move[i+1][cur.second]) {
					cnt_move[i+1][cur.second] = cnt_move[cur.first][cur.second] + 1;
					q.push_back(make_pair(i+1, cur.second));
				}
				break;
			}
		}
		// 하 끝까지
		for (int i=cur.first+1; i<=row; ++i) {
			if (i == row || board[i][cur.second] == 'D') {
				if (!cnt_move[i-1][cur.second]) {
					cnt_move[i-1][cur.second] = cnt_move[cur.first][cur.second] + 1;
					q.push_back(make_pair(i-1, cur.second));
				}
				break;
			}
		}
		// 좌 끝까지
		for (int i=cur.second-1; i>=-1; --i) {
			if (i == -1 || board[cur.first][i] == 'D') {
				if (!cnt_move[cur.first][i+1]) {
					cnt_move[cur.first][i+1] = cnt_move[cur.first][cur.second] + 1;
					q.push_back(make_pair(cur.first, i+1));
				}
				break;
			}
		}
		// 우 끝까지
		for (int i=cur.second+1; i<=col; ++i) {
			if (i == col || board[cur.first][i] == 'D') {
				if (!cnt_move[cur.first][i-1]) {
					cnt_move[cur.first][i-1] = cnt_move[cur.first][cur.second] + 1;
					q.push_back(make_pair(cur.first, i-1));
				}
				break;
			}
		}
	}

	return answer;
}
