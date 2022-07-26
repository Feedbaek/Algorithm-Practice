/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   방문 길이.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:46:28 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/24 11:46:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <set>
#include <tuple>
using namespace std;

int solution(string dirs) {
	set<tuple<int, int, int, int>> s;
	int x = 0, y = 0;
	for (int i=0; i<dirs.size(); ++i) {
		if (dirs[i] == 'U') {
			if (x == 5)
				continue;
			s.insert({x, y, x+1, y});
			++x;
		} else if (dirs[i] == 'D') {
			if (x == -5)
				continue;
			s.insert({x, y, x-1, y});
			--x;
		} else if (dirs[i] == 'R') {
			if (y == 5)
				continue;
			s.insert({x, y, x, y+1});
			++y;
		} else if (dirs[i] == 'L') {
			if (y == -5)
				continue;
			s.insert({x, y, x, y-1});
			--y;
		}
	}
	return s.size();
}

int main(int argc, char const *argv[])
{
	int ret = solution("UDU");
	cout << ret << "\n";
	return 0;
}
