/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   행렬 테두리 회전하기.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:36:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/26 12:39:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

int map[100][100];

int rotate(int r1, int c1, int r2, int c2) {
	int tmp = map[r1-1][c1-1], min = map[r1-1][c1-1];
	for (int i=r1-1; i<r2-1; ++i) {
		map[i][c1-1] = map[i+1][c1-1];
		if (map[i][c1-1] < min)
			min = map[i][c1-1];
	}
	for (int j=c1-1; j<c2-1; ++j) {
		map[r2-1][j] = map[r2-1][j+1];
		if (map[r2-1][j] < min)
			min = map[r2-1][j];
	}
	for (int i=r2-1; i>r1-1; --i) {
		map[i][c2-1] = map[i-1][c2-1];
		if (map[i][c2-1] < min)
			min = map[i][c2-1];
	}
	for (int j=c2-1; j>c1-1; --j) {
		map[r1-1][j] = map[r1-1][j-1];
		if (map[r1-1][j] < min)
			min = map[r1-1][j];
	}
	map[r1-1][c1] = tmp;
	return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	int cnt = 0;
	for (int i=0; i<rows; ++i)
		for (int j=0; j<columns; ++j)
			map[i][j] = ++cnt;

	for (int n=0; n<queries.size(); ++n)
		answer.push_back(rotate(queries[n][0], queries[n][1], queries[n][2], queries[n][3]));
	return answer;
}
