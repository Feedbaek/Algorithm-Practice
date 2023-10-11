#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ccol;

bool cmp(vector<int> a, vector<int> b) {
	if (a[ccol] == b[ccol]) {
		return a[0] > b[0];
	}
	return a[ccol] < b[ccol];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
	int answer = 0;
	ccol = col - 1;
	sort(data.begin(), data.end(), cmp);
	for (int row = row_begin-1; row < row_end; row++) {
		int s_i = 0;
		for (int c=0; c<data[row].size(); c++) {
			s_i += data[row][c] % (row + 1);
		}
		answer = answer ^ s_i;
	}
	return answer;
}
