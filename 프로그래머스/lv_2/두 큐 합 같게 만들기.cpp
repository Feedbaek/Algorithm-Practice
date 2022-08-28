/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   두 큐 합 같게 만들기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:15:16 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/28 12:43:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

void A_to_B(vector<int>& A, vector<int>& B) {
	B.push_back(A.front());
	A.erase(A.begin());
}

int get_sum(vector<int>& v) {
	int sum = 0;
	for (int i=0; i<v.size(); ++i)
		sum += v[i];
	return sum;
}

int solution(vector<int> queue1, vector<int> queue2) {
	queue<pair<vector<int>, int>> a;
	queue<pair<vector<int>, int>> b;
	a.push({queue1, 0});
	b.push({queue2, 0});
	int sum_a = 0, sum_b = 0;
	int cnt = 0;
	while (cnt < 100000000) {
		vector<int> tmp1 = a.front().first;
		vector<int> tmp2 = b.front().first;
		if (get_sum(tmp1) == get_sum(tmp2))
			break;
		int c = a.front().second;
		A_to_B(tmp1, tmp2);
		a.push({tmp1, c+1});
		b.push({tmp2, c+1});
		A_to_B(b.front().first, a.front().first);
		a.push({a.front().first, c+1});
		b.push({b.front().first, c+1});
		a.pop();
		b.pop();
		++cnt;
	}
	return a.front().second;
}

int main() {
	cout << solution({1, 2, 1, 2}, {1, 10, 1, 2}) << "\n";
}
