#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
	long long answer = 0;
	for (int x=0; x<=r2; ++x) {
		int y2 = (int) sqrt(((long long)r2 * r2) - ((long long)x * x));
		answer += y2 + 1;
		if (x >= r1)
			continue;
		int y1 = ceil(sqrt(((long long)r1 * r1) - ((long long)x * x)));
		answer -= y1;
	}
	return 4 * (answer - (r2 - r1 + 1));
}
