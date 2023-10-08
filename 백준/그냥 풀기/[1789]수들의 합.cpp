#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input, cnt = 0;
	cin >> input

	for (int i=1; input>0; ++i) {
		input -= i;
		++cnt;
	}

	cout << cnt << endl;
}
