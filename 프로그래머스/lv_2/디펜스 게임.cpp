#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> my_enemy;

struct cmp {
	bool operator()(int a, int b) {
		return my_enemy[a] > my_enemy[b];
	}
};

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	my_enemy = enemy;
	priority_queue<int,vector<int>, cmp> pq;
	for (int i=0; i<my_enemy.size(); ++i) {
		if (pq.size() < k) {
			pq.push(i);
		} else if (my_enemy[pq.top()] < my_enemy[i]) {
			if (n - my_enemy[pq.top()] < 0)
				break;
			n -= my_enemy[pq.top()];
			pq.pop();
			pq.push(i);
		} else {
			if (n - my_enemy[i] < 0)
				break;
			n -= my_enemy[i];
		}
		answer++;
	}
	return answer;
}
