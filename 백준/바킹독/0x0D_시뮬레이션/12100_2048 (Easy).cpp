/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12100_2048 (Easy).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:07:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/21 22:35:34 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21];
int n, big_block;

void	pull_up_map() {
	for (int j=0; j<n; j++)
		for (int i=0; i<n; i++)
			if (arr[i][j] == 0)
				for (int k=i+1; k<n; k++)
					if (arr[k][j] != 0) {
						arr[i][j] = arr[k][j];
						arr[k][j] = 0;
						break;
					}
}

void	pull_down_map() {
	for (int j=0; j<n; j++)
		for (int i=n-1; i>=0; i--)
			if (arr[i][j] == 0)
				for (int k=i-1; k>=0; k--)
					if (arr[k][j] != 0) {
						arr[i][j] = arr[k][j];
						arr[k][j] = 0;
						break;
					}
}

void	pull_left_map() {
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (arr[i][j] == 0)
				for (int k=j+1; k<n; k++)
					if (arr[i][k] != 0) {
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						break;
					}

}

void	pull_right_map() {
	for (int i=0; i<n; i++)
		for (int j=n-1; j>=0; j--)
			if (arr[i][j] == 0)
				for (int k=j-1; k>=0; k--)
					if (arr[i][k] != 0) {
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						break;
					}
}

void	sum_up_block() {
	for (int j=0; j<n; j++)
		for (int i=0; i<n-1; i++)
			if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j]) {
				arr[i][j] *= 2;
				arr[i+1][j] = 0;
				for (int k=i+1; k<n-1&&arr[k+1][j]!=0; k++) {
					arr[k][j] = arr[k+1][j];
					arr[k+1][j] = 0;
				}
			}
}

void	sum_down_block() {
	for (int j=0; j<n; j++)
		for (int i=n-1; i>0; i--)
			if (arr[i][j] != 0 && arr[i][j] == arr[i-1][j]) {
				arr[i][j] *= 2;
				arr[i-1][j] = 0;
				for (int k=i-1; k>0&&arr[k-1][j]!=0; k--) {
					arr[k][j] = arr[k-1][j];
					arr[k-1][j] = 0;
				}
			}
}

void	sum_left_block() {
	for (int i=0; i<n; i++)
		for (int j=0; j<n-1; j++)
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j+1]) {
				arr[i][j] *= 2;
				arr[i][j+1] = 0;
				for (int k=j+1; k<n-1&&arr[i][k+1]!=0; k++) {
					arr[i][k] = arr[i][k+1];
					arr[i][k+1] = 0;
				}
			}

}

void	sum_right_block() {
	for (int i=0; i<n; i++)
		for (int j=n-1; j>0; j--)
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j-1]) {
				arr[i][j] *= 2;
				arr[i][j-1] = 0;
				for (int k=j-1; k>0&&arr[i][k-1]!=0; k--) {
					arr[i][k] = arr[i][k-1];
					arr[i][k-1] = 0;
				}
			}
}

void	move_up() {
	pull_up_map();
	sum_up_block();
}

void	move_down() {
	pull_down_map();
	sum_down_block();
}

void	move_left() {
	pull_left_map();
	sum_left_block();
}

void	move_right() {
	pull_right_map();
	sum_right_block();
}

void	check_map() {
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (arr[i][j] > big_block)
				big_block = arr[i][j];
}

void	rec(int dept) {
	if (dept == 5) {
		check_map();
		return ;
	}
	int tmp[21][21];
	copy(&arr[0][0], &arr[0][0]+21*21, &tmp[0][0]);
	move_up();
	rec(dept+1);
	copy(&tmp[0][0], &tmp[0][0]+21*21, &arr[0][0]);
	move_down();
	rec(dept+1);
	copy(&tmp[0][0], &tmp[0][0]+21*21, &arr[0][0]);
	move_left();
	rec(dept+1);
	copy(&tmp[0][0], &tmp[0][0]+21*21, &arr[0][0]);
	move_right();
	rec(dept+1);
	copy(&tmp[0][0], &tmp[0][0]+21*21, &arr[0][0]);
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> arr[i][j];
	rec(0);
	cout << big_block;
	return 0;
}
