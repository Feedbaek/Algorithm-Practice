/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   전력망을 둘로 나누기.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:22:47 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/17 13:33:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void rec(int st, int& cnt, vector<vector<int>>& wires) {
	if (wires.size() == 0)
		return ;
	for (int i=0; i<wires.size(); ++i) {
		if (wires[i][0] == st || wires[i][1] == st) {
			vector<int> tmp = wires[i];
			wires.erase(wires.begin() + i);
			if (tmp[0] == st)
				rec(tmp[1], ++cnt, wires);
			else
				rec(tmp[0], ++cnt, wires);
			wires.insert(wires.begin() + i, tmp);
		}
	}
}

int solution(int n, vector<vector<int>> wires) {
	int answer = n + 1;
	for (int i=0; i<wires.size(); ++i) {
		vector<int> tmp = wires[i];
		wires.erase(wires.begin() + i);
		int cnt1 = 0, cnt2 = 0;
		rec(tmp[0], cnt1, wires);
		rec(tmp[1], cnt2, wires);
		if (abs(cnt1 - cnt2) < answer)
			answer = abs(cnt1 - cnt2);
		wires.insert(wires.begin() + i, tmp);
	}
	return answer;
}
