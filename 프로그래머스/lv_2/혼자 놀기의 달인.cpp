#include <string>
#include <vector>

using namespace std;

int rec(vector<int> &box, bool *check, int n, int count) {
	int card = box[n-1];
	check[n] = true;
	count++;
	if (check[card])
		return count;
	return rec(box, check, card, count);
}

int solution(vector<int> box) {
	int answer = 0;
	for (int i=0; i<box.size(); ++i) {
		bool check[101] = {};
		int a_group = rec(box, check, i+1, 0);
		for (int j=0; j<box.size(); ++j) {
			if (!check[j+1]) {
				int b_group = rec(box, check, j+1, 0);
				if (a_group * b_group > answer)
					answer = a_group * b_group;
			}
		}
	}
	return answer;
}
