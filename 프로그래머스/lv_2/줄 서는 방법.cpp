#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void test(int n, long long k) {
	vector<int> answer;
	for (int i=1; i<=n; ++i)
		answer.push_back(i);

	for (long long i=0; i<k-1; ++i)
		next_permutation(answer.begin(), answer.end());

	cout << "+=+=+++=+=+ real answer +=+=+=+=++++=+\n";
	for (int i=0; i<answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n\n";
}

vector<int> solution(int n, long long k) {
	vector<int> answer;
	long long count = 0;
	long long factorial[21];
	bool check = false;

	factorial[0] = 1;
	for (int i=1; i<21; ++i) {
		factorial[i] = factorial[i-1] * i;
	}

	for (int i=0; i<n; ++i) {
		for (int j=1; j<n-i; ++j) {
			if (count + factorial[n-i-1] >= k) {
				check = true;
				break;
			}
			count += factorial[n-i-1];
		}
		if (check)
			break;
		answer.push_back(n-i);
	}
	for (int i=0; answer.size()<n; ++i) {
		answer.push_back(i+1);
	}
	k -= count;
	for (long long i=0; i<k-1; ++i)
		next_permutation(answer.begin(), answer.end());

	cout << "+=+=+=+=++=+= my answer +=++=+=+=++=+=\n";
	for (int i=0; i<answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n\n";

	return answer;
}

int main() {
	int n = 4;
	int k = 24;
	solution(n, k);
	test(n, k);
	return 0;
}
