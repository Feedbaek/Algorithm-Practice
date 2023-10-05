#include <string>
#include <sstream>
#include <vector>

using namespace std;

int getPlayTime(string startTime, string endTime) {
	int startHour = stoi(startTime.substr(0, 2));
	int startMin = stoi(startTime.substr(3, 2));
	int endHour = stoi(endTime.substr(0, 2));
	int endMin = stoi(endTime.substr(3, 2));
	return (endHour - startHour) * 60 + (endMin - startMin);
}

vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream ss(input);
	string tmp;

	while (getline(ss, tmp, delimiter)) result.push_back(tmp);

	return result;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int longTime = 0;

	string startTime, endTime, title, melody;
	for (int i=0; i<musicinfos.size(); ++i) {
		vector<string> info = split(musicinfos[i], ',');
		startTime = info[0]; // 음악 시작 시간
		endTime = info[1]; // 음악 끝난 시간
		title = info[2]; // 음악 제목
		melody = info[3]; // 악보 정보

		int playTime = getPlayTime(startTime, endTime);
		int cnt_start = -1; // #을 제외하고 음의 개수를 세기 위한 변수
		for (int j=0; j<melody.size(); ++j) {
			if (melody[j] == '#')
				continue;
			++cnt_start;
			int m_idx = 0; // m_idx: m의 인덱스
			int idx = j; // idx: melody의 인덱스
			int cnt = cnt_start; // cnt: #을 제외한 melody의 음 개수
			while (m_idx < m.size() && m[m_idx] == melody[idx] && cnt < playTime) {
				++m_idx;
				idx = (idx + 1) % melody.size();
				if (melody[idx] != '#')
					++cnt;
			}
			if (m_idx == m.size()) { // m이 melody에 포함되는 경우
				if (melody[idx] == '#')
					continue; // #이 붙은 음은 다른 음과 구분되지 않으므로 continue
				if (longTime < playTime) {
					longTime = playTime; // 재생 시간 갱신
					answer = title; // 제목 갱신
				}
			}
		}
	}
	if (longTime == 0)
		return "(None)"; // 일치하는 음악이 없는 경우
	return answer;
}
