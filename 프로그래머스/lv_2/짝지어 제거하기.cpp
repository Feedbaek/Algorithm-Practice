/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   짝지어 제거하기.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:18:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/09/25 21:29:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	vector<char> v;
	for (int i=0; i<s.size(); ++i) {
		v.push_back(s[i]);
		if (v.size() > 1 && v[v.size()-1] == v[v.size()-2]) {
			v.pop_back();
			v.pop_back();
		}
	}
	if (v.empty())
		return 1;
	return 0;
}
