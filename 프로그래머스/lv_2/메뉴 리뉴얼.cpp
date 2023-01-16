/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   메뉴 리뉴얼.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:16:42 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/16 16:16:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int combine[10];
map<string, int> board_menu;
int max_cnt[11];

string make_menu(string order) {
	string menu = "";
	for (int i=0; i<order.size(); ++i) {
		if (combine[i] == 1)
			menu.push_back(order[i]);
	}
	sort(menu.begin(), menu.end());
	return menu;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	// 크기 == course[i] 메뉴
	for (int i=0; i<course.size(); ++i) {
		// 주문들 순환
		for (int j=0; j<orders.size(); ++j) {
			if (orders[j].size() < course[i])
				continue;
			// combine 초기화
			for (int k=0; k<orders[j].size(); ++k) {
				if (k < course[i])
					combine[k] = 1;
				else
					combine[k] = 0;
			}
			// 조합 찾기
			do {
				string menu = make_menu(orders[j]);
				if (!board_menu.insert(make_pair(menu, 1)).second) {
					++board_menu[menu];
					if (board_menu[menu] > max_cnt[course[i]])
						max_cnt[course[i]] = board_menu[menu];
				}
			} while (prev_permutation(combine, combine + orders[j].size()));
		}
	}
	for (auto p : board_menu) {
		if (max_cnt[p.first.size()] == p.second)
			answer.push_back(p.first);
	}
	return answer;
}
