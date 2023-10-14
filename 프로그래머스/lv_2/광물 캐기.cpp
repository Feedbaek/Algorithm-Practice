#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> fatigue[3];

int rec(vector<int>& picks, vector<string>& minerals, int idx) {
	int min_cnt = 775;

	if (idx >= minerals.size())
		return 0;
	for (int i=0; i<3; ++i) {
		if (picks[i] != 0) {
			int pos = idx, cnt = 0;
			while (pos < idx + 5) {
				if (pos == minerals.size())
					break;
				cnt += fatigue[i][minerals[pos++]];
			}
			picks[i] -= 1;
			int fati = rec(picks, minerals, pos);
			picks[i] += 1;
			if (min_cnt > cnt + fati)
				min_cnt = cnt + fati;
		}
	}
	if (min_cnt == 775)
		return 0;
	return min_cnt;
}

int solution(vector<int> picks, vector<string> minerals) {
	int answer = 0;
	fatigue[0]["diamond"] = 1; fatigue[0]["iron"] = 1; fatigue[0]["stone"] = 1;
	fatigue[1]["diamond"] = 5; fatigue[1]["iron"] = 1; fatigue[1]["stone"] = 1;
	fatigue[2]["diamond"] = 25; fatigue[2]["iron"] = 5; fatigue[2]["stone"] = 1;

	return rec(picks, minerals, 0);
}
