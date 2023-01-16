#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int i=0; i<course.size(); ++i) {
		int uni[26] = {};
		for (int j=0; j<course[i]; ++j) {
			uni[j] = 1;
		}
		int _max = 0;
		for (int o=0; o<orders.size(); ++o) {
			if (orders[o].size() < course[i])
				continue;
			int cnt = 0;
			do {
				int com[26] = {};
				for (int l=0; l<orders[o].size(); ++l) {
					com[orders[o][l] - 'A'] = 1;
				}
				bool flag = true;
				for (int l=0; l<26; ++l) {
					if (uni[l] == 1 && com[l] == 0) {
						flag = false;
						break;
					}
				}
				if (flag)
					++cnt;
				if (cnt >= _max && cnt > 1) {
					string tmp = "";
					for (int l=0; l<26; ++l) {
						if (uni[l] == 1)
							tmp.push_back('A' + l);
					}
					if (_max != 0 && cnt > _max) {
						while (answer.back().size() == tmp.size())
							answer.pop_back();
					}
					answer.push_back(tmp);
					_max = cnt;
				}
			} while (prev_permutation(uni, uni + orders[o].size()));
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
