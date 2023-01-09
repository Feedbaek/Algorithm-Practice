/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [3차] 파일명 정렬.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:12:45 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/09 11:15:21 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<string, int> pasrsing_head(string f) {
	string head = "";
	int idx = 0;

	for (idx=0; idx<f.size(); ++idx) {
		if (f[idx] >= 'A' && f[idx] <= 'Z')
			f[idx] += 32;
		if (f[idx] >= '0' && f[idx] <= '9') {
			head = f.substr(0, idx);
			break;
		}
	}
	return make_pair(head, idx);
}

int pasrsing_number(string f) {
	int number = 0;
	int idx = 0;

	for (idx=0; idx<f.size() && idx < 5; ++idx) {
		if (f[idx] < '0' || f[idx] > '9')
			break;
		number = number * 10 + f[idx] - '0';
	}
	return number;
}

bool cmp(const string& f1, const string& f2) {
	pair<string, int> f1_head = pasrsing_head(f1);
	pair<string, int> f2_head = pasrsing_head(f2);

	if (f1_head.first != f2_head.first)
		return f1_head.first < f2_head.first;

	int f1_num = pasrsing_number(f1.substr(f1_head.second));
	int f2_num = pasrsing_number(f2.substr(f2_head.second));

	return f1_num < f2_num;
}

vector<string> solution(vector<string> files) {
	stable_sort(files.begin(), files.end(), cmp);
	return files;
}
