/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   기능개발.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:36:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/19 11:58:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int cnt = 0;
	for (int i=1, idx=0; idx < progresses.size() ;) {
		if (progresses[idx] + (speeds[idx] * i) < 100) {
			if (cnt != 0)
				answer.push_back(cnt);
			cnt = 0;
			++i;
			continue;
		}
		++cnt;
		++idx;
	}
	answer.push_back(cnt);
	return answer;
}
