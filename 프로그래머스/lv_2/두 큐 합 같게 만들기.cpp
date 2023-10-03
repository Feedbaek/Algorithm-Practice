/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   두 큐 합 같게 만들기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:15:16 by minskim2          #+#    #+#             */
/*   Updated: 2023/10/03 22:03:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
	long long total = 0;
	long long sum = 0;
	int answer = 0;
	// 전체 합 구하기
	vector<int> queue;
	for (int i=0; i<queue1.size(); i++) {
		queue.push_back(queue1[i]);
		sum += queue1[i];
	}
	total = sum;
	for (int i=0; i<queue2.size(); i++) {
		queue.push_back(queue2[i]);
		total += queue2[i];
	}
	// 두 큐의 합이 같아질 때까지 돌리기
	int st = 0; // 큐1의 시작 인덱스
	int en = queue1.size() - 1; // 큐2의 끝 인덱스
	while (st < en && en < queue.size()) {
		if (sum < total / 2)
			sum += queue[++en];
		else if (sum > total / 2)
			sum -= queue[st++];
		else
			break;
		answer++;
	}
	// 결과 반환
	if (sum == total / 2)
		return answer;
	return -1;
}
