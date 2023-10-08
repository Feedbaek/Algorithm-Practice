#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input;

	cin >> input;

	if (input % 10 != 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << input / 300 << " ";
	cout << (input % 300) / 60 << " ";
	cout << (input % 60) / 10 << endl;

	return 0;
}
