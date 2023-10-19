#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
// 24:00 -> 1440 으로 변환
int convert_time(string time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	return h * 60 + m;
}
// 시간 순서대로 정렬하기 위함
bool cmp(vector<string> a, vector<string> b) {
	return convert_time(a[1]) < convert_time(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<pair<string, int>> s;

	sort(plans.begin(), plans.end(), cmp);
	// 마지막으로 일을 처리한 시간
	int before_time = 0;
	// plans를 순회하면서 일을 처리하고 도중에 멈춘 과제는 스택에 넣는다.
	for (int i=0; i<plans.size(); ++i) {
		int start = convert_time(plans[i][1]);
		int work_time = start - before_time;
		while (!s.empty()) {
			pair<string, int> top = s.back();
			// 일을 완료 할 수 있으면 처리하고 스택에서 제거
			if (top.second <= work_time) {
				answer.push_back(top.first);
				work_time -= top.second;
				s.pop_back();
		 	} else { // 일을 완료 할 수 없으면 처리하고 남은 시간으로 변경
				s.back().second = top.second - work_time;
				break;
			}
		}
		s.push_back(make_pair(plans[i][0], stoi(plans[i][2])));
		before_time = start;
	}
	// 스택에 남은 과제들 처리
	while (!s.empty()) {
		answer.push_back(s.back().first);
		s.pop_back();
	}
	return answer;
}
