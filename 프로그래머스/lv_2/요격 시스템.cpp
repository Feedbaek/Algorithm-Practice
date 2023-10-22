#include <vector>
#include <algorithm>

using namespace std;
// 미사일의 x좌표 끝나는 구간을 기준으로 정렬
bool cmp(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
	int answer = 1;
	sort(targets.begin(), targets.end(), cmp);
	int prev = targets[0][1];
	for (int i=1; i<targets.size(); ++i) {
		if (targets[i][0] < prev) // 끝나는 구간보다 시작하는 구간이 작으면 관통
			continue;
		prev = targets[i][1]; // 끝나는 구간 갱신
		answer++; // 새로운 요격 미사일 발사
	}
	return answer;
}
