#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> relation) {
	int answer = 0;
	// 컬럼의 조합을 저장하는 벡터
	vector<vector<bool>> pk;
	// 후보키로 사용하는 컬럼의 개수를 i로 두고
	for (int i=1; i<=relation[0].size(); ++i) {
		vector<bool> check(relation[0].size()-i, false);
		check.insert(check.end(), i, true);
		do {
			// 후보키로 사용할 수 있는 조합인지 확인하는 셋
			unordered_set<string> us;
			bool flag = true;
			// 다른 후보키를 포함하는지 확인
			for (int j=0; j<pk.size(); ++j) {
				bool dup = true;
				for (int k=0; k<pk[j].size(); ++k) {
					if (pk[j][k] && !check[k]) {
						dup = false;
						break;
					}
				}
				if (dup) {
					flag = false;
					break;
				}
			}
			// 다른 후보키를 포함해 최소성을 만족하지 못하는 조합이면 패스
			if (!flag)
				continue;
			// 후보키로 사용할 수 있는지 확인
			for (int row=0; row<relation.size(); ++row) {
				string key = "";
				// 후보키로 사용할 컬럼을 뽑아서 키를 만듦
				for (int col=0; col<relation[0].size(); ++col) {
					if (check[col])
						key += relation[row][col] + " ";
				}
				// 이미 존재하는 키라면 패스
				if (us.insert(key).second == false) {
					flag = false;
					break;
				}
			}
			// 후보키로 사용할 수 있는 조합이면 후보키로 추가
			if (flag) {
				pk.push_back(check);
				++answer;
			}
		// 다음 조합을 구함
		} while(next_permutation(check.begin(), check.end()));
	}

	return answer;
}
