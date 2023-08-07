#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer = {0, 0};
	int sum=sequence[0], st=0, en=1;
	int minSize = 1111111;
	if (sum == k)
		return answer;

	while(en < sequence.size()) {
		while (sequence[en] > k) {
			sum = 0;
			st = ++en;
		}
		while(sum + sequence[en] > k) {
			sum -= sequence[st];
			st++;
		}
		sum += sequence[en];
		en++;
		if (sum == k && en - st < minSize) {
			answer[0] = st;
			answer[1] = en - 1;
			minSize = en - st;
		}
	}
	return answer;
}
