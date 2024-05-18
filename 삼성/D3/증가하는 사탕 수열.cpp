#include<iostream>

using namespace std;

void println(int test_case, int answer) {
	cout << "#" << test_case << " " << answer << "\n";
}

int main(int argc, char** argv) {
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case) {
		int A, B, C;
		int answer = 0;
		cin >> A >> B >> C;
		if (C < 3 || B < 2) {
			println(test_case, -1);
			continue;
		}

		if (B >= C) {
			answer += B - C + 1;
			B = C - 1;
		}
		if (A >= B) {
			answer += A - B + 1;
		}
		println(test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
