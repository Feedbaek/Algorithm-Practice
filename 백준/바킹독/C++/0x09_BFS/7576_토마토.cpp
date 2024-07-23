/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7576_토마토.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:39:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 09:31:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> Q;
int	vis[1001][1001];
int	map[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cnt_max = 0;

void	bfs(int n, int m) {
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] != 0 || map[nx][ny] != 0)
				continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			if (vis[nx][ny] > cnt_max)
				cnt_max = vis[nx][ny];
			Q.push({nx,ny});
		}
	}
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, m, x;
	cin >> m >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin >> x;
			map[i][j] = x;
			if (x == 1)
				Q.push({i, j});
		}
	bfs(n, m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (map[i][j] == 0 && vis[i][j] == 0) {
				cout << -1;
				return (0);
			}
	cout << cnt_max;
}
