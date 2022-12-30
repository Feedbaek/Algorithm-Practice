/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [3차] 압축.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:13:14 by minskim2          #+#    #+#             */
/*   Updated: 2022/12/30 22:40:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> v;

	for (int i=0; i<26; ++i) {
		string tmp = "A";
		tmp[0] += i;
		v.push_back(tmp);
	}

	int idx = 0, pos = 0, cnt = 1;
	while (cnt <= msg.size()) {
		if (find(v.begin(), v.end(), msg.substr(pos, cnt)) == v.end()) {
			answer.push_back(idx);
			v.push_back(msg.substr(pos, cnt));
			pos += cnt - 1;
			cnt = 1;
		}
		else {
			idx = find(v.begin(), v.end(), msg.substr(pos, cnt)) - v.begin() + 1;
			++cnt;
		}
	}
	answer.push_back(idx);
	return answer;
}
