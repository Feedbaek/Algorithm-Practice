#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
	long long answer = 0;

	sort(weights.begin(), weights.end());

	for (int i = 0; i < weights.size(); i++) {
		int st = i;
		int en = weights.size() - 1;
		int mid = (st + en + 1) / 2;

		while (st <= en) {
			mid = (st + en) / 2;
			if (weights[mid] < weights[i] * 2) {
				st = mid + 1;
			}
			else {
				en = mid - 1;
			}
		}

		while (st <= en) {
			mid = (st + en) / 2;
			if (weights[mid] < weights[i] * 2) {
				st = mid + 1;
			}
			else {
				en = mid - 1;
			}
		}

		while (st <= en) {
			mid = (st + en) / 2;
			if (weights[mid] < weights[i] * 2) {
				st = mid + 1;
			}
			else {
				en = mid - 1;
			}
		}
	}
	return answer;
}
