/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   괄호 변환.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:30:05 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/25 09:28:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

// 문자열 p에서 문자열 v의 시작 인덱스 찾아서 반환
int split_uv(string& p) {
	int pos=0, sum=0;

	do {
		if (p[pos] == '(')
			++sum;
		else if (p[pos] == ')')
			--sum;
		++pos;
	} while (sum != 0);
	return pos;
}
// 문자열이 올바른 괄호 문자열인지 검사
bool is_valid(string &str) {
	int sum = 0;

	for (int i=0; i<str.size(); ++i) {
		if (str[i] == '(')
			++sum;
		else if (str[i] = ')')
			--sum;
		if (sum < 0)
			return false;
	}
	if (sum != 0)
		return false;
	return true;
}

string solution(string p) {
	string answer = "";
	string u, v = p;
	int pos;

	while (v != "") {
		pos = split_uv(v);
		// 문자열 v의 시작 인덱스를 찾아서 u, v 분리
		u = v.substr(0, pos);
		v = v.substr(pos);
		// u가 올바른 괄호 문자열이 아닌 경우 재귀 호출 후 종료
		if (!is_valid(u)) {
			answer += "(" + solution(v) + ")";
			u = u.substr(1, u.size()-2); // 첫 번째와 마지막 문자 제거
			for (int i=0; i<u.size(); ++i) { // 괄호 방향을 뒤집어서 answer에 붙이기
				if (u[i] == '(')
					answer += ")";
				else if (u[i] == ')')
					answer += "(";
			}
			return answer;
		}
		// u가 올바른 괄호 문자열이면 answer에 붙이고 반복
		answer += u;
	}
	return answer;
}
