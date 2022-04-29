/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15683_감시.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:45:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/29 18:09:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int map[8][8];
int dir[8][8];
int map_fill[8][8];
int ret = 64;
int	n, m;

void	fill_up(int row, int column) {
	for (int i=row; i>=0; i--) {
		if (map[i][column] == 6)
			break;
		map_fill[i][column] = 1;
	}
}
void	fill_left(int row, int column) {
	for (int i=column; i>=0; i--) {
		if (map[row][i] == 6)
			break;
		map_fill[row][i] = 1;
	}
}
void	fill_down(int row, int column) {
	for (int i=row; i<n; i++) {
		if (map[i][column] == 6)
			break;
		map_fill[i][column] = 1;
	}
}
void	fill_right(int row, int column) {
	for (int i=column; i<m; i++) {
		if (map[row][i] == 6)
			break;
		map_fill[row][i] = 1;
	}
}

void	draw() {
	int cnt = 0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (map[i][j] == 0 || map[i][j] == 6)
				continue;
			if (dir[i][j] == 1) {
				fill_up(i, j);
				if (map[i][j] == 2) {
					fill_down(i, j);
				}
				else if (map[i][j] != 1 && map[i][j] != 2) {
					fill_right(i, j);
					if (map[i][j] != 3) {
						fill_down(i, j);
						if (map[i][j] != 4) {
							fill_left(i, j);
						}
					}
				}
			}
			else if (dir[i][j] == 2) {
				fill_right(i, j);
				if (map[i][j] == 2) {
					fill_left(i, j);
				}
				else if (map[i][j] != 1 && map[i][j] != 2) {
					fill_down(i, j);
					if (map[i][j] != 3) {
						fill_left(i, j);
						if (map[i][j] != 4) {
							fill_up(i, j);
						}
					}
				}
			}
			else if (dir[i][j] == 3) {
				fill_down(i, j);
				if (map[i][j] == 2) {
					continue;
				}
				else if (map[i][j] != 1 && map[i][j] != 2) {
					fill_left(i, j);
					if (map[i][j] != 3) {
						fill_up(i, j);
						if (map[i][j] != 4) {
							fill_right(i, j);
						}
					}
				}
			}
			else if (dir[i][j] == 4) {
				fill_left(i, j);
				if (map[i][j] == 2) {
					continue;
				}
				else if (map[i][j] != 1 && map[i][j] != 2) {
					fill_up(i, j);
					if (map[i][j] != 3) {
						fill_right(i, j);
						if (map[i][j] != 4) {
							fill_down(i, j);
						}
					}
				}
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (map_fill[i][j] == 0 && map[i][j] != 6)
				cnt++;
			else
				map_fill[i][j] = 0;
		}
	}
	if (cnt < ret)
		ret = cnt;
}

void	find_way(int row, int column) {
	if (row == n) {
		draw();
		return ;
	}
	if (map[row][column] == 0 || map[row][column] == 6) {
		find_way(row+((column+1)/m), (column+1)%m);
		return ;
	}

	dir[row][column] = 1;
		find_way(row+((column+1)/m), (column+1)%m);

	if (map[row][column] == 5)
		return ;

	dir[row][column] = 2;
		find_way(row+((column+1)/m), (column+1)%m);

	if (map[row][column] == 2)
		return ;

	dir[row][column] = 3;
		find_way(row+((column+1)/m), (column+1)%m);
	dir[row][column] = 4;
		find_way(row+((column+1)/m), (column+1)%m);
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> x;
			map[i][j] = x;
		}
	}
	find_way(0, 0);
	cout << ret;
}
