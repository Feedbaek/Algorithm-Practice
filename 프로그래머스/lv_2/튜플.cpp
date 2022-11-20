#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2) {
	return v1.size() < v2.size();
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> v;
	int value, i = 1;

	while (s.find('{', i) != string::npos) {
		i = s.find('{', i) + 1;
		vector<int> tmp;
		while (s.find(',', i) < s.find('}', i)) {
			value = stoi(s.substr(i, s.find(',', i)-i));
			tmp.push_back(value);
			i = s.find(',', i) + 1;
		}
		value = stoi(s.substr(i, s.find('}', i)-i));
		tmp.push_back(value);
		v.push_back(tmp);
		i = s.find('}', i) + 1;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i=0; i<v.size(); ++i) {
		for (int j=0; j<v[i].size(); ++j)
			if (find(answer.begin(), answer.end(), v[i][j]) == answer.end()) {
				answer.push_back(v[i][j]);
				break;
			}
	}
	return answer;
}
