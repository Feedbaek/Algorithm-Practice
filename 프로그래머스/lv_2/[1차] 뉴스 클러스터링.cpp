/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1차] 뉴스 클러스터링.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:24:12 by minskim2          #+#    #+#             */
/*   Updated: 2022/12/28 21:42:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <unordered_map>
#include <utility>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
	unordered_map<string, int> m1;
	unordered_map<string, int> m2;
	for (int i=0; i<str1.size() - 1; ++i) {
		if (isalpha(str1[i]) && isalpha(str1[i+1])) {
			string word = str1.substr(i, 2);
			if ('A' <= str1[i] && str1[i] <= 'Z')  // 대문자면 소문자로 변환
				word[0] += 32;
			if ('A' <= str1[i+1] && str1[i+1] <= 'Z')
				word[1] += 32;

			if (m1.insert(make_pair(word, 1)).second == false) // 중복이면
				m1[word] += 1;  // 기존 값 1 증가
		}
	}
	for (int i=0; i<str2.size() - 1; ++i) {
		if (isalpha(str2[i]) && isalpha(str2[i+1])) {
			string word = str2.substr(i, 2);
			if ('A' <= str2[i] && str2[i] <= 'Z')  // 대문자면 소문자로 변환
				word[0] += 32;
			if ('A' <= str2[i+1] && str2[i+1] <= 'Z')
				word[1] += 32;

			if (m2.insert(make_pair(word, 1)).second == false) // 중복이면
				m2[word] += 1;  // 기존 값 1 증가
		}
	}

	double _union = 0, _inter = 0;

	for (auto p : m1) {
		if (m2.find(p.first) != m2.end()) {
			if (p.second < m2[p.first]) {
				_union += m2[p.first];
				_inter += p.second;
			}
			else {
				_union += p.second;
				_inter += m2[p.first];
			}
		}
		else
			_union += p.second;
	}
	for (auto p : m2)
		if (m1.find(p.first) == m1.end())
			_union += p.second;

	if (_union == 0)
		return 65536;
	return (int)((_inter / _union) * 65536);
}
