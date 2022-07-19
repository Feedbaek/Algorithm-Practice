#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i=0; i<skill_trees.size(); ++i) {
		int pos = 0, flag = 1;
		for (int idx=0; idx<skill_trees[i].size(); ++idx) {
			if (skill.find(skill_trees[i][idx]) == string::npos)
				continue;
			if (pos != skill.find(skill_trees[i][idx])) {
				flag = 0;
				break;
			}
			pos = skill.find(skill_trees[i][idx]) + 1;
		}
		if (flag)
			++answer;
	}
	return answer;
}
