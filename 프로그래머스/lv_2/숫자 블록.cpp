#include <vector>

using namespace std;

int find_div(long long n) {
	int answer = 1;
	for (int i=2; i*i<=n; ++i) {
		if (n % i == 0) {
			if (n / i <= 10000000)
				return n / i;
			if (i > answer)
				answer = i;
		}
	}
	if (n == 1)
		return 0;
	return answer;
}

vector<int> solution(long long begin, long long end) {
	vector<int> answer;

	for (int i=begin; i<=end; ++i)
		answer.push_back(find_div(i));

	return answer;
}
