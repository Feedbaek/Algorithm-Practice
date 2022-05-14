/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   스티커 붙이기.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:07:32 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/14 10:40:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	map[40][40];
int	seal[10][10];
int n, m;

void	print_map() {
	cout << "map \n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
void	print_seal(int r, int c) {
	cout << "seal \n";
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout << seal[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

void	rotate_seal(int& r, int& c) {
	int tmp[10][10];
	int t;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			tmp[j][r-1-i] = seal[i][j];
	t = r;
	r = c;
	c = t;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			seal[i][j] = tmp[i][j];
	//print_seal(r, c);
}

bool	attachable(int x, int y, int r, int c) {
	if (x+r > n || y+c > m)
		return false;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			if (seal[i][j] == 1 && map[x+i][y+j] == 1)
				return false;
	return true;
}

void	attach(int x, int y, int r, int c) {
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			if (seal[i][j] == 1)
				map[x+i][y+j] = seal[i][j];
}

void	attach_try(int r, int c) {
	for (int k=0; k<4; k++) {
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (attachable(i, j, r, c)) {
					//cout << "before " << i << " " << j << "\n";
					//print_map();
					//print_seal(r, c);
					attach(i, j, r, c);
					//cout << "after \n";
					//print_map();
					return;
				}
		rotate_seal(r, c);
	}
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, r, c, cnt = 0;
	cin >> n >> m >> k;
	for (int i=0; i<k; i++) {
		cin >> r >> c;
		for (int a=0; a<r; a++)
			for (int b=0; b<c; b++)
				cin >> seal[a][b];
		attach_try(r, c);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (map[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt;
}
