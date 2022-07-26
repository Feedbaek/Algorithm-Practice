/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   이진 변환 반복하기.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:34:21 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/26 13:25:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
	int cnt = 0, sum = 0, tmp;
	while (1) {
		++cnt;
		tmp = s.size();
		s.erase(remove(s.begin(), s.end(), '0'), s.end());
		sum += tmp - s.size();
		if (s == "1")
			break;
		s = bitset<32> (s.size()).to_string();
		s.erase(s.begin(), s.begin() += s.find('1'));
	}
	return {cnt, sum};
}
