/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   숫자 변환하기.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:59:15 by minskim2          #+#    #+#             */
/*   Updated: 2023/02/13 10:59:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <utility>

using namespace std;

int solution(int x, int y, int n) {
	deque<pair<int, int>> q;
	int visited[1000001] = {};

	q.push_back(make_pair(x, 0));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop_front();

		if (p.first == y)
			return p.second;
		if (p.first + n <= y && visited[p.first + n] == 0) {
			q.push_back(make_pair(p.first + n, p.second + 1));
			visited[p.first + n] = 1;
		}
		if (p.first * 3 <= y && visited[p.first * 3] == 0) {
			q.push_back(make_pair(p.first * 3, p.second + 1));
			visited[p.first * 3] = 1;
		}
		if (p.first * 2 <= y && visited[p.first * 2] == 0) {
			q.push_back(make_pair(p.first * 2, p.second + 1));
			visited[p.first * 2] = 1;
		}
	}
	return -1;
}
