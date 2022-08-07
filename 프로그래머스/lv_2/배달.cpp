/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   배달.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:55:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/07 12:51:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#define INIT_VALUE 1000000
using namespace std;
int visit_cost[51];

int solution(int n, vector<vector<int>> road, int k) {
	int answer = 1;  // 1번 마을은 무조건 가능해서 1
	for (int i=2; i<=n; ++i)  // 다른 마을까지의 방문비용 초기 설정
		visit_cost[i] = INIT_VALUE;
	deque<int> q;  // 현재 위치를 저장하는 큐
	q.push_back(1);  // 초기 위치 1 설정
	int currnet_vil; // 현재 마을위치 저장 변수
	while (!q.empty()) {
		currnet_vil = q.front();
		for (int i=0; i<road.size(); ++i) {
			if (road[i][2] + visit_cost[currnet_vil] > k)
				continue;  // 갈 수없는 도로면 넘김
			if (road[i][0] == currnet_vil && visit_cost[road[i][1]] > visit_cost[currnet_vil] + road[i][2]) {
				q.push_back(road[i][1]);
				visit_cost[road[i][1]] = visit_cost[currnet_vil] + road[i][2];
			}  // 현재 마을에서 갈 수있는 도로의 경우 기존의 방문 비용과 비교해서 재설정
			else if (road[i][1] == currnet_vil && visit_cost[road[i][0]] > visit_cost[currnet_vil] + road[i][2]) {
				q.push_back(road[i][0]);
				visit_cost[road[i][0]] = visit_cost[currnet_vil] + road[i][2];
			} // 위와 같은데 현재 마을이 road[1]인 경우
		}
		q.pop_front();
	}
	for (int i=2; i<=n; ++i)  // 방문 비용이 초기값과 다르면 방문했다는 뜻
		if (visit_cost[i] != INIT_VALUE)
			++answer;
	return answer;
}
