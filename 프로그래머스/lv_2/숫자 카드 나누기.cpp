#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int gcd_numA, gcd_numB;

	if (arrayA.size() > 1)
		gcd_numA = gcd(arrayA[0], arrayA[1]);
	else
		gcd_numA = arrayA[0];
	for (int i=2; i<arrayA.size(); i++) {
		gcd_numA = gcd(gcd_numA, arrayA[i]);
	}

	if (arrayB.size() > 1)
		gcd_numB = gcd(arrayB[0], arrayB[1]);
	else
		gcd_numB = arrayB[0];
	for (int i=2; i<arrayB.size(); i++) {
		gcd_numB = gcd(gcd_numB, arrayB[i]);
	}

	int m_a = gcd_numA, m_b = gcd_numB;

	printf("%d %d\n", m_a, m_b);
	bool flag = false;
	while (m_a != 1 && m_b != 1 && !flag) {
		for (int i=0; i<arrayA.size(); i++) {
			if (arrayA[i] > m_b && arrayA[i] % m_b == 0)
				break;
			if (i == arrayA.size() - 1)
				flag = true;
		}
		m_b /= 2;
	}

	flag = false;
	while (m_a != 1 && m_b != 1 && !flag) {
		for (int i=0; i<arrayB.size(); i++) {
			if (arrayB[i] > m_a && arrayB[i] % m_a == 0)
				break;
			if (i == arrayB.size() - 1)
				flag = true;
		}
		m_a /= 2;
	}

	printf("%d %d\n", m_a, m_b);

	if (m_a == 1 && m_b == 1)
		return 0;

	return m_a > m_b ? m_a : m_b;
}
