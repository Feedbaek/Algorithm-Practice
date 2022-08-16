/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   양궁대회.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:20:27 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/16 21:13:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

int diff_max = 0;
vector<int> diff_v;

int get_scorecmp(vector<int>& info, vector<int>& answer) {
	int score = 0, cmp_score = 0;
	for (int i=0; i<11; ++i) {
		if (info[i] != 0) {
			cmp_score += 10 - i;
			if (info[i] < answer[i]) {
				cmp_score -= 10 - i;
				score += 10 - i;
			}
		} else if (answer[i] != 0)
			score += 10 - i;
	}
	return score - cmp_score;
}

void check_diff_v(vector<int>& answer) {
	for (int i=10; i>=0; --i) {
		if (answer[i] > diff_v[i]) {
			diff_v = answer;
			return ;
		} else if (answer[i] < diff_v[i])
			return ;
	}
}

void dfs(int dept, int n, vector<int>& info, vector<int>& answer) {
	if (n == 0 || dept == 11) {
		if (n != 0)
			answer[10] += n;
		int diff = get_scorecmp(info, answer);
		if (diff > diff_max) {
			diff_max = diff;
			diff_v = answer;
		} else if (diff == diff_max)
			check_diff_v(answer);
		return ;
	}
	dfs(dept+1, n, info, answer);
	if (n > info[dept]) {
		answer[dept] = info[dept] + 1;
		dfs(dept+1, n-info[dept]-1, info, answer);
	}
	answer[dept] = 0;
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;
	answer.resize(11);
	diff_v.resize(11);
	dfs(0, n, info, answer);
	if (diff_max == 0)
		return {-1};
	return diff_v;
}
