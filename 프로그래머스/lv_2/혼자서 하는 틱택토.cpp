#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_max(vector<string> &board, int *dir, int x, int y, char c, int cnt) {
	if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != c)
		return cnt;
	return find_max(board, dir, x+dir[0], y+dir[1], c, cnt+1);
}

int solution(vector<string> board) {
	char c[2] = {'O', 'X'};
	int end = 0;
	for (int k=0; k<2; ++k) {
		bool check = false;
		bool win = false;
		// 행 체크
		for (int i=0; i<3; ++i) {
			int dir[2] = {0, 1};
			int ret = find_max(board, dir, i, 0, c[k], 0);
			if (ret == 3) {
				if (check)
					return 0;
				else
					check = true;
			}
		}
		if (check) {
			if (end)
				return 0;
			else
				win = true;
		}
		check = false;
		// 열 체크
		for (int i=0; i<3; ++i) {
			int dir[2] = {1, 0};
			int ret = find_max(board, dir, 0, i, c[k], 0);
			if (ret == 3) {
				if (check)
					return 0;
				else
					check = true;
			}
		}
		if (check) {
			if (end)
				return 0;
			else
				win = true;
		}
		check = false;
		// 대각선 체크
		{
			int dir[2] = {1, 1};
			int ret = find_max(board, dir, 0, 0, c[k], 0);
			if (ret == 3) {
				if (check)
					return 0;
				else
					check = true;
			}
		}
		if (check) {
			if (end)
				return 0;
			else
				win = true;
		}
		check = false;
		// 대각선 체크
		{
			int dir[2] = {1, -1};
			int ret = find_max(board, dir, 0, 2, c[k], 0);
			if (ret == 3) {
				if (check)
					return 0;
				else
					check = true;
			}
		}
		if (check) {
			if (end)
				return 0;
			else
				win = true;
		}
		if (win)
			end = k+1;
	}
	// 개수 체크
	int cnt_o = 0;
	int cnt_x = 0;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			if (board[i][j] == 'O')
				++cnt_o;
			else if (board[i][j] == 'X')
				++cnt_x;
		}
	}
	if (end == 1 && (cnt_o != cnt_x+1))
		return 0;
	else if (end == 2 && (cnt_o != cnt_x))
		return 0;
	else if (cnt_o != cnt_x && cnt_o != cnt_x+1)
		return 0;
	return 1;
}
