/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   방문 길이.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:46:28 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/27 13:12:10 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

vector<vector<int> > v;

bool is_valid(int x1, int y1, int x2, int y2) {
	for (int i=0; i<v.size(); ++i) {
		if (v[i][0] == x1 && v[i][1] == y1 && v[i][2] == x2 && v[i][3] == y2)
			return false;
	}
	return true;
}

vector<int> make_vector(int x1, int y1, int x2, int y2) {
	vector<int> tmp;
	tmp.push_back(x1);
	tmp.push_back(y1);
	tmp.push_back(x2);
	tmp.push_back(y2);
	return tmp;
}

int solution(string dirs) {
	int x = 0, y = 0;
	for (int i=0; i<dirs.size(); ++i) {
		if (dirs[i] == 'U') {
			if (x == 5)
				continue;
			if (is_valid(x, y, x+1, y))
				v.push_back(make_vector(x, y, x+1, y));
			++x;
		} else if (dirs[i] == 'D') {
			if (x == -5)
				continue;
			if (is_valid(x-1, y, x, y))
				v.push_back(make_vector(x-1, y, x, y));
			--x;
		} else if (dirs[i] == 'R') {
			if (y == 5)
				continue;
			if (is_valid(x, y, x, y+1))
				v.push_back(make_vector(x, y, x, y+1));
			++y;
		} else if (dirs[i] == 'L') {
			if (y == -5)
				continue;
			if (is_valid(x, y-1, x, y))
				v.push_back(make_vector(x, y-1, x, y));
			--y;
		}
	}
	return v.size();
}
