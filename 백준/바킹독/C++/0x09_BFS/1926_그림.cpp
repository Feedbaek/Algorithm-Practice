/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1926_그림.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:51:29 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/09 17:02:52 by minskim2         ###   ########.fr       */
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

int	bfs(int x, int y, int n, int m) {
	int size = 1;
	Q.push({x, y});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir=0; dir<4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] != 0 || map[nx][ny] != 1)
				continue;
			vis[nx][ny] = 1;
			size++;
			Q.push({nx,ny});
		}
	}
	return (size);
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, m, x, cnt = 0, max = 0;
	cin >> n >> m;
	for (int i=0; i<n; i++)		// map 설정
		for (int j=0; j<m; j++) {
			cin >> x;
			map[i][j] = x;
		}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (vis[i][j] == 0 && map[i][j] == 1) {
				vis[i][j] = 1;
				cnt++;
				x = bfs(i, j, n, m);
				if (x > max)
					max = x;
			}
	cout << cnt << '\n' << max << '\n';
	return (0);
}
