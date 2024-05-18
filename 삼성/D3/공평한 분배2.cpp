#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case) {
		vector<int> v;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			int input;
			cin >> input;
			v.push_back(input);
		}

		sort(v.begin(), v.end());

		int diff = 1000000001;
		for (int i = 0; i + k - 1 < v.size(); ++i) {
			if (v[i + k - 1] - v[i] < diff) {
				diff = v[i + k - 1] - v[i];
			}
		}
		cout << "#" << test_case << " " << diff << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
