/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   옹알이 (2).cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:15:22 by minskim2          #+#    #+#             */
/*   Updated: 2022/11/05 11:04:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
	int answer = 0, idx;
	for (int i=0; i<babbling.size(); ++i) {
		string prev_word = "";  // 이전에 말한 단어 저장
		for (idx=0; idx<babbling[i].size();) {  // 문장을 탐색
			if (idx + 1 < babbling[i].size()) {  // 남은 문장의 길이가 2이상
				string two_word = babbling[i].substr(idx, 2);
				if (prev_word != two_word && (two_word == "ye" || two_word == "ma")) {
					idx += 2;
					prev_word = two_word;
					continue;
				}
			}
			if (idx + 2 < babbling[i].size()) {  // 남은 묹장의 길이가 3이상
				string three_word = babbling[i].substr(idx, 3);
				if (prev_word != three_word && (three_word == "aya" || three_word == "woo")) {
					idx += 3;
					prev_word = three_word;
					continue;
				}
			}
			break;  // 빌음 가능한 단어가 아닌게 나온 경우 탐색을 멈춤
		}
		if (idx == babbling[i].size())  // 문장을 끝까지 탐색한 경우 발음 가능한 상황
			++answer;
	}
	return answer;
}
