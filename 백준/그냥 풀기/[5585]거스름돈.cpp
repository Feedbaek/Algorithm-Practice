#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int input, change;
	int count = 0;

	cin >> input;

	change = 1000 - input;
	count += change / 500;
	count += (change % 500) / 100;
	count += (change % 100) / 50;
	count += (change % 50) / 10;
	count += (change % 10) / 5;
	count += (change % 5) / 1;

	cout << count << endl;

	return 0;
}
