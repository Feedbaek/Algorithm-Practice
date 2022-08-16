/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   양궁대회.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:20:27 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/16 13:01:01 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<double, int>& a, pair<double, int>& b) {
	return a.first > b.first;
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	vector<pair<double, int> > eff;
	int cmp_score = 0, arrow = n, score = 0;
	eff.reserve(11);
	answer.resize(11);
	for (int i=0; i<11; ++i) {
		if (info[i] == 0) {
			cmp_score += 10 - i;
			eff[i] = {(10 - i), i};
		} else {
			eff[i] = {2 * (10 - i) / ((double)info[i]+1), i};
		}
	}
	sort(&eff[0], &eff[0] + 11, compare);
	for (int i=0; i<11; ++i) {
		if (arrow <= 0)
			break;
		if (arrow < info[eff[i].second]+1)
			continue;
		arrow -= info[eff[i].second]+1;
		score += 10 - eff[i].second;
		cmp_score -= 10 - eff[i].second;
		answer[eff[i].second] = info[eff[i].second]+1;
	}
	if (arrow != 0)
		answer[10] += arrow;
	if (score > cmp_score)
		return answer;
	return {-1};
}
