/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   영어 끝말잇기.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:07:32 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/22 11:24:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	set<string> s;
	string tmp(1, words[0].front());
	for (int i=0; i<words.size(); i++) {
		if (s.insert(words[i]).second == false || tmp.back() != words[i].front())
			return {(i%n)+1, (i/n)+1};
		tmp = words[i];
	}
	return {0, 0};
}
