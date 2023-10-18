#include <string>
#include <vector>

using namespace std;

int dp[100001];

int calculate(int k) {
	int cnt = 0;
	dp[cnt] = k;
	while (k > 1) {
		if (k % 2 == 0) {
			k /= 2;
		} else {
			k = k * 3 + 1;
		}
		dp[++cnt] = k;
	}
	return cnt;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
	vector<double> answer;
	int n = calculate(k);
	for (int i=0; i<ranges.size(); ++i) {
		int x1 = ranges[i][0];
		int x2 = n + ranges[i][1];
		int sum = 0;
		while (x1 < x2) {
			sum += dp[x1] + dp[x1+1];
			++x1;
		}
		if (x1 > x2)
			sum = -2;
		answer.push_back((double)sum / 2);
	}
	return answer;
}
