#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
	int cnt_o = 0;
	int cnt_x = 0;
	for (int i=0; i<3; ++i) {
		if (board[i][i] == 'O')
			++cnt_o;
		else if (board[i][i] == 'X')
			++cnt_x;
	}
	if (cnt_o < cnt_x || cnt_o > cnt_x + 1)
		return 0;

	for (int i=0; i<3; ++i) {

	}
}
