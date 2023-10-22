#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> arr[4][4][4][4];

vector<string> split(string input, char delimiter) {
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
		answer.push_back(temp);

	return answer;
}

void rec(int lang, int part, int curr, int soul, int idx, int score) {
	if (idx == 4) {
		arr[lang][part][curr][soul].push_back(score);
		return;
	}
	rec(lang, part, curr, soul, idx+1, score);
	if (idx == 0)
		rec(3, part, curr, soul, idx+1, score);
	else if (idx == 1)
		rec(lang, 3, curr, soul, idx+1, score);
	else if (idx == 2)
		rec(lang, part, 3, soul, idx+1, score);
	else
		rec(lang, part, curr, 3, idx+1, score);
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	unordered_map<string, int> m;
	m["cpp"] = 0; m["java"] = 1; m["python"] = 2;
	m["backend"] = 0; m["frontend"] = 1;
	m["junior"] = 0; m["senior"] = 1;
	m["chicken"] = 0; m["pizza"] = 1;
	m["-"] = 3;

	for (int i=0; i<info.size(); ++i) {
		vector<string> temp = split(info[i], ' ');
		int lang = m[temp[0]], part = m[temp[1]], curr = m[temp[2]], soul = m[temp[3]], score = stoi(temp[4]);
		rec(lang, part, curr, soul, 0, score);
	}
	for (int i=0; i<4; ++i)
		for (int j=0; j<4; ++j)
			for (int k=0; k<4; ++k)
				for (int l=0; l<4; ++l)
					sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());
	for (int i=0; i<query.size(); ++i) {
		vector<string> temp = split(query[i], ' ');
		int lang = m[temp[0]], part = m[temp[2]], curr = m[temp[4]], soul = m[temp[6]], score = stoi(temp[7]);
		vector<int> &v = arr[lang][part][curr][soul];
		answer.push_back(v.end() - lower_bound(v.begin(), v.end(), score));
	}
	return answer;
}
