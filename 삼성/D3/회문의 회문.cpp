#include<iostream>

using namespace std;

// 제네릭 메소드로 결과 출력
template<class T>
void println(int test_case, T answer) {
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
		string S;
		cin >> S;
		int arr[100][100] = {};
		int len = S.size();

		// 크기 1, 2 회문 전처리
		for (int i=0; i<len; ++i) {
			arr[i][i] = 1;
			if (i + 1 < len && S[i] == S[i+1]) {
				arr[i][i+1] = 1;
			}
		}
		// 크기 3 이상 회문 처리
		for (int size=3; size <= len; ++size) {
			for (int i=0; i+size<=len; ++i) {
				if (arr[i+1][i+size-2] && S[i] == S[i+size-1]) {
					arr[i][i+size-1] = 1;
				}
			}
		}
		// 조건에 맞으면 YES, 아니면 NO
		if (arr[0][len-1] && arr[0][(len/2) - 1] && arr[(len/2) + 1][len - 1]) {
			println(test_case, "YES");
		} else {
			println(test_case, "NO");
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
