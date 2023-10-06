#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// 시간을 정수로 변환
int convertTime(string time) {
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3, 2));
	return hour * 60 + minute;
}
// 정렬을 위한 비교 함수
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first < p2.first)
		return true;
	else if (p1.first == p2.first && ((p1.second == 1 && p2.second == 1) || p1.second == -1))
		return true;
	else
		return false;
}

int solution(vector<vector<string>> book_time) {
	int answer = 0, cnt = 0;
	vector<pair<int, int>> time_table;
	// 시작 시간과 종료 시간을 정수로 변환하여 time_table에 저장
	for (int i=0; i<book_time.size(); ++i) {
		// 시작 시간은 +1, 종료 시간은 -1
		int startTime = convertTime(book_time[i][0]);
		// 종료 시간은 +10
		int endTime = convertTime(book_time[i][1]) + 10;
		time_table.push_back(make_pair(startTime, 1));
		time_table.push_back(make_pair(endTime, -1));
	}
	sort(time_table.begin(), time_table.end(), compare);
	// time_table을 순회하며 현재 시간에 몇 개의 객실이 사용 중인지 확인
	for (int i=0; i<time_table.size(); ++i) {
		cnt += time_table[i].second;
		answer = max(answer, cnt);
	}
	return answer;
}
