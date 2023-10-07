#include <string>
#include <vector>

using namespace std;
// 유클리드 호제법
int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int gcdA = arrayA[0], gcdB = arrayB[0];
	// 최대공약수 구하기
	for (int i=1; i<arrayA.size(); ++i) {
		if (arrayA[i] % gcdA != 0)
			gcdA = gcd(gcdA, arrayA[i]);
		if (arrayB[i] % gcdB != 0)
			gcdB = gcd(gcdB, arrayB[i]);
	}
	// 최대공약수로 나누어지는지 확인해서 나누어지면 1로 바꾸기
	for (int i=0; i<arrayA.size(); ++i) {
		if (arrayA[i] % gcdB == 0)
			gcdB = 1;
		if (arrayB[i] % gcdA == 0)
			gcdA = 1;
	}
	// 둘 다 1이면 0 반환
	if (gcdA == 1 && gcdB == 1)
		return 0;
	return gcdA > gcdB ? gcdA : gcdB;
}
