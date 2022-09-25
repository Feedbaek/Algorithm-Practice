/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   더 맵게.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:38:30 by minskim2          #+#    #+#             */
/*   Updated: 2022/09/25 21:13:01 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0, min1, min2;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i=0; i<scoville.size(); ++i)
		q.push(scoville[i]);
	while (q.top() < K && q.size() > 1) {
		min1 = q.top();
		q.pop();
		min2 = q.top();
		q.pop();
		q.push(min1 + min2 * 2);
		++answer;
	}
	if (q.top() < K)
		return -1;
	return answer;
}
