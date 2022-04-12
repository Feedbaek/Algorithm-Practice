/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4179_불!.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 09:15:46 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 10:05:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> Q;
queue<pair<int, int>> Q1;
int	f_vis[1001][1001];
int	vis[1001][1001];
int	map[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt_min;

void	fire_bfs(int n, int m) {
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (f_vis[nx][ny] != 0 || map[nx][ny] != '.')
				continue;
			f_vis[nx][ny] = f_vis[cur.first][cur.second] + 1;
			Q.push({nx,ny});
		}
	}
}

void	jihoon_bfs(int n, int m) {
	while (!Q1.empty()) {
		pair<int, int> cur = Q1.front();
		Q1.pop();
		if (cur.first == n-1 || cur.second == m-1) {
			if (vis[cur.first][cur.second] < cnt_min)
				cnt_min = vis[cur.first][cur.second];
			return ;
		}
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] != 0 || map[nx][ny] != '.' || vis[cur.first][cur.second] + 1 >= f_vis[nx][ny])
				continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q1.push({nx,ny});
		}
	}
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, m;
	string input;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> input;
		for (int j=0; j<m; j++) {
			map[i][j] = input[j];
			if (input[j] == 'F')
				Q.push({i, j});
			if (input[j] == 'J')
				Q1.push({i, j});
		}
	}
	fire_bfs(n, m);
	cnt_min = n * m + 10;
	jihoon_bfs(n, m);
	if (cnt_min == n * m + 10)
		cout << "IMPOSSIBLE";
	else
		cout << cnt_min + 1;
}
