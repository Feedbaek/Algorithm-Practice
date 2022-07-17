/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   모음사전.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:11:21 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/17 11:30:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

char arr[5] = {'A', 'E', 'I', 'O', 'U'};

void rec(int dept, int& cnt, int& answer, string word, string origin) {
	if (word == origin || dept == 5) {
		if (word == origin)
			answer = cnt;
		return ;
	}
	for (int i=0; i<5; ++i)
		rec(dept+1, ++cnt, answer, word+arr[i], origin);
}

int solution(string word) {
	int answer = 0;
	int cnt = 0;
	string tmp = "";
	rec(0, cnt, answer, tmp, word);
	return answer;
}
