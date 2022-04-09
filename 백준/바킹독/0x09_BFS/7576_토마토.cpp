/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7576_토마토.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:39:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/09 19:39:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> Q;
int	vis[501][501];
int	map[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void	bfs(int x, int y, int n, int m) {
	Q.push({x, y});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		if (cur.first == n-1 && cur.second == m-1)
			return ;
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] != 0 || map[nx][ny] != 1)
				continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({nx,ny});
		}
	}
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, m, x;
	string input;
	cin >> n >> m;
}
