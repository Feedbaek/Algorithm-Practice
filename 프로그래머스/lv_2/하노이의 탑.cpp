/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   하노이의 탑.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:51:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/09/25 22:09:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

void rec(int n, vector<vector<int>>& answer, int st, int en, int tmp) {
	if (n == 1) {
		answer.push_back({st, en});
		return;
	}
	rec(n-1, answer, st, tmp, en);
	rec(1, answer, st, en, tmp);
	rec(n-1, answer, tmp, en, st);
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	rec(n, answer, 1, 3, 2);
	return answer;
}
