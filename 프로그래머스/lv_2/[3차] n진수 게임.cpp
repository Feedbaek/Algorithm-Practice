/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [3차] n진수 게임.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:54:52 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/04 10:15:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char dict[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string dton(int n, int d) {
	string ret = "";

	if (d == 0)
		return "0";
	while (d) {
		ret.push_back(dict[d % n]);
		d /= n;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string solution(int n, int t, int m, int p) {
	string answer = "";

	int order = 1;
	for (int d_num=0; answer.size() < t; ++d_num) {
		string n_num = dton(n, d_num);
		for (int i=0; i<n_num.size() && answer.size() < t; ++i) {
			if (order % m == p % m)
				answer.push_back(n_num[i]);
			++order;
		}
	}
	return answer;
}
