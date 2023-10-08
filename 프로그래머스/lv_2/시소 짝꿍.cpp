#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
	long long answer = 0;
	int m[4001] = {};
	int w[1001] = {};

	for (int i=0; i<weights.size(); i++) {
		for (int j=2; j<=4; ++j) {
			if (m[weights[i] * j] > 0)
				answer += m[weights[i] * j];
			m[weights[i] * j]++;
		}
		answer -= w[weights[i]] * 2;
		w[weights[i]]++;
	}
	return answer;
}
