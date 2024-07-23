/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4179_불!.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:15:46 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/01 18:15:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
using namespace std;

int r, c;
string map[1000];
int fire[1000][1000];
queue<vector<int>> q;
queue<vector<int>> f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i=0; i<r; ++i) {
		int pos = 0;
		cin >> map[i];
		for (int j=0; j<c; ++j) {
			if (map[i][j] == 'F') {
				f.push({i, j, 0});
				fire[i][j] = 0;
			}
			else if (map[i][j] == 'J')
				q.push({i, j, 0});
			fire[i][j] = 100000000;
		}
	}
	vector<int> tmp;
	while (!f.empty()) {
		tmp = f.front();
		if (tmp[0] > 0 && map[tmp[0]-1][tmp[1]] != '#' && map[tmp[0]-1][tmp[1]] != 'F' && fire[tmp[0]-1][tmp[1]] > tmp[2]+1) {
			fire[tmp[0]-1][tmp[1]] = tmp[2]+1;
			f.push({tmp[0]-1, tmp[1], tmp[2]+1});
		}
		if (tmp[0] < r-1 && map[tmp[0]+1][tmp[1]] != '#' && map[tmp[0]+1][tmp[1]] != '#' && fire[tmp[0]+1][tmp[1]] > tmp[2]+1) {
			fire[tmp[0]+1][tmp[1]] = tmp[2]+1;
			f.push({tmp[0]+1, tmp[1], tmp[2]+1});
		}
		if (tmp[1] > 0 && map[tmp[0]][tmp[1]-1] != '#' && map[tmp[0]][tmp[1]-1] != '#' && fire[tmp[0]][tmp[1]-1] > tmp[2]+1) {
			fire[tmp[0]][tmp[1]-1] = tmp[2]+1;
			f.push({tmp[0], tmp[1]-1, tmp[2]+1});
		}
		if (tmp[1] < c-1 && map[tmp[0]][tmp[1]+1] != '#' && map[tmp[0]][tmp[1]+1] != '#' && fire[tmp[0]][tmp[1]+1] > tmp[2]+1) {
			fire[tmp[0]][tmp[1]+1] = tmp[2]+1;
			f.push({tmp[0], tmp[1]+1, tmp[2]+1});
		}
		f.pop();
	}
	bool flag = false;
	while (!q.empty()) {
		tmp = q.front();
		if (tmp[0] == 0 || tmp[0] == r-1 || tmp[1] == 0 || tmp[1] == c-1) {
			flag = true;
			break;
		}
		if (tmp[0]+1<r && map[tmp[0]+1][tmp[1]] == '.' && tmp[2]+1 < fire[tmp[0]+1][tmp[1]]) {
			fire[tmp[0]+1][tmp[1]] = tmp[2]+1;
			q.push({tmp[0]+1, tmp[1], tmp[2]+1});
		}
		if (tmp[0]-1>=0 && map[tmp[0]-1][tmp[1]] == '.' && tmp[2]+1 < fire[tmp[0]-1][tmp[1]]) {
			fire[tmp[0]-1][tmp[1]] = tmp[2]+1;
			q.push({tmp[0]-1, tmp[1], tmp[2]+1});
		}
		if (tmp[1]+1<c && map[tmp[0]][tmp[1]+1] == '.' && tmp[2]+1 < fire[tmp[0]][tmp[1]+1]) {
			q.push({tmp[0], tmp[1]+1, tmp[2]+1});
			fire[tmp[0]][tmp[1]+1] = tmp[2]+1;
		}
		if (tmp[1]-1>=0 && map[tmp[0]][tmp[1]-1] == '.' && tmp[2]+1 < fire[tmp[0]][tmp[1]-1]) {
			q.push({tmp[0], tmp[1]-1, tmp[2]+1});
			fire[tmp[0]][tmp[1]-1] = tmp[2]+1;
		}
		q.pop();
	}
	if (flag)
		cout << q.front()[2] + 1;
	else
		cout << "IMPOSSIBLE";
}
