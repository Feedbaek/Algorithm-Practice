/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   N-Queen.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:27:22 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/21 19:58:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

int column[12];
int answer = 0;
char map[12][12];

bool check(int r, int c, int n) {
	if (column[c] == 1)
		return false;
	int i = 0;
	while (r - i >= 0 && c - i >= 0) {
		if (map[r-i][c-i] == 1)
			return false;
		++i;
	}
	i = 0;
	while (r - i >= 0 && c + i < n) {
		if (map[r-i][c+i] == 1)
			return false;
		++i;
	}
	return true;
}

void queen(int dept, int n) {
	if (dept == n) {
		++answer;
		return ;
	}
	for (int i=0; i<n; ++i)
		if (check(dept, i, n)) {
			column[i] = 1;
			map[dept][i] = 1;
			queen(dept+1, n);
			column[i] = 0;
			map[dept][i] = 0;
		}
}

int solution(int n) {
	queen(0, n);
	return answer;
}
