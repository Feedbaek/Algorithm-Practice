/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   전화번호 목록.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:45:10 by minskim2          #+#    #+#             */
/*   Updated: 2022/09/18 21:57:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

bool ft_strcmp(string& s1, string& s2) {
	for (int i=0; i<s1.length() && i<s2.length(); ++i)
		if (s1[i] != s2[i])
			return false;
	return true;
}

bool solution(vector<string> phone_book) {
	unordered_map<string, string> m;
	int min = 20;
	for (int i=0; i<phone_book.size(); ++i) {
		if (phone_book[i].size() < min)
			min = phone_book[i].size();
	}
	for (int i=0; i<phone_book.size(); ++i) {
		for (int j=0; j<=phone_book[i].size() - min; ++j) {
			string m_key = phone_book[i].substr(0, min+j);
			if (m.insert(make_pair(m_key, phone_book[i])).second)
				break;
			if (ft_strcmp(m[m_key], phone_book[i]))
				return false;
		}
	}
	return true;
}
