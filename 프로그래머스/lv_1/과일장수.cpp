#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0, size = score.size();
	sort(score.begin(), score.end());
	for (int i=1; i<=size; ++i) {
		if (i % m == 0)
			answer += (score[size-i] * m);
	}
	return answer;
}
