#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;

	cin >> input;
	int cnt_0 = 0, cnt_1 = 0;
	int prev = input[0];

	if (prev == '0')
		++cnt_0;
	else
		++cnt_1;

	for (int i=1; i<input.size(); ++i) {
		if (input[i] == '0' && prev == '1')
			++cnt_0;
		else if (input[i] == '1' && prev == '0')
			++cnt_1;
		prev = input[i];
	}

	cout << min(cnt_0, cnt_1) << endl;
}
