#include <cmath>

using namespace std;

long long solution(int k, int d) {
	long long answer = 0;
	long long ld = d;
	for (long long x=0; x<=d; x+=k) {
		answer += (floor(sqrt(ld * ld - x * x)) / k) + 1 ;
	}
	return answer;
}
