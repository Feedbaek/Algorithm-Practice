#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b) {
	int tmp, n; //a에 큰 값을 위치시키기 위한 조건문입니다.
	if(a<b){
		tmp = a;
		a = b;
		b = tmp;
	}
	//유클리드 알고리즘 부분입니다.
	//b가 0이 될때까지(a%b), 반복문을 돌게되고, b가 0인 순간의 a를 GCD로 판단하고 리턴합니다.
	while(b!=0){
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int arr[1051][1051];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/

	for (int i = 1; i <= 1050; ++i) {
		for (int j = i; j <= 1050; ++j) {
			if (gcd(j, i) == 1) {
				arr[i][j] = 1;
				arr[j][i] = 1;
			} else {
				arr[i][j] = -1;
				arr[j][i] = -1;
			}
		}
	}

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; ++i) {
			string input;
			cin >> input;
			v.push_back(input);
		}
		bool answer = false;
		for (int k = 0; k <= 1000; ++k) {
			bool flag = false;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (v[i][j] == '1' && arr[i + k][j + k] != 1) {
						flag = true;
						break;
					}
					else if (v[i][j] == '?' && arr[i + k][j + k] != -1) {
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (!flag) {
				cout << "#" << test_case << " YES\n";
				answer = true;
				break;
			}
		}
		if (!answer) {
			cout << "#" << test_case << " NO\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
