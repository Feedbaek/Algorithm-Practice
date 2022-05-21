/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12100_2048 (Easy).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:07:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/21 18:49:12 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int map[20][20];
int n, big_block;

void	pull_up_map(int arr[][20]) {
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

void	pull_down_map(int arr[][20]) {
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

void	pull_left_map(int arr[][20]) {
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (arr[i][j] == 0)
				for (int k=j; k<n; k++)
					if (arr[i][k] != 0) {
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						break;
					}
}

void	pull_right_map(int arr[][20]) {
	for (int i=0; i<n; i++)
		for (int j=n-1; j>=n; j--)
			if (arr[i][j] == 0)
				for (int k=j; k>=0; k--)
					if (arr[i][k] != 0) {
						arr[i][j] = arr[i][k];
						arr[i][k] = 0;
						break;
					}
}

void	sum_up_block(int arr[][20]) {
	for (int j=0; j<n; j++) {
		for (int i=0; i<n-1; i++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j]) {
				arr[i][j] *= 2;
				arr[i+1][j] = 0;
				for (int k=i+1; k<n-1; k++) {
					arr[k][j] = arr[k+1][j];
					arr[k+1][j] = 0;
				}
			}
		}
	}
}

void	sum_down_block(int arr[][20]) {
	for (int j=0; j<n; j++) {
		for (int i=n-1; i>0; i--) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i-1][j]) {
				arr[i][j] *= 2;
				arr[i-1][j] = 0;
				for (int k=i-1; k>0; k--) {
					arr[k][j] = arr[k-1][j];
					arr[k-1][j] = 0;
				}
			}
		}
	}
}

void	sum_left_block(int arr[][20]) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j+1]) {
				arr[i][j] *= 2;
				arr[i][j+1] = 0;
				for (int k=j+1; k<n-1; k++) {
					arr[i][k] = arr[i][k+1];
					arr[i][k+1] = 0;
				}
			}
		}
	}
}

void	sum_right_block(int arr[][20]) {
	for (int i=0; i<n; i++) {
		for (int j=n-1; j>=0; j--) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j-1]) {
				arr[i][j] *= 2;
				arr[i][j-1] = 0;
				for (int k=j-1; k>0; k--) {
					arr[i][k] = arr[i][k-1];
					arr[i][k-1] = 0;
				}
			}
		}
	}
}

void	move_up(int arr[][20]) {
	pull_up_map(arr);
	sum_up_block(arr);
}

void	move_down(int arr[][20]) {
	pull_down_map(arr);
	sum_down_block(arr);
}

void	move_left(int arr[][20]) {
	pull_left_map(arr);
	sum_left_block(arr);
}

void	move_right(int arr[][20]) {
	pull_right_map(arr);
	sum_right_block(arr);
}

void	print_map(int arr[][20]) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << arr[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void	check_map(int arr[][20]) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (arr[i][j] > big_block) {
				big_block = arr[i][j];
				//print_map(arr);
			}
		}
	}
}

void	rec(int dept, int arr[][20]) {
	if (dept == 5) {
		check_map(arr);
		return ;
	}
	int tmp[20][20];
	//cout << "==== " << dept << " ====\n";
	copy(&arr[0][0], &arr[0][0]+400, &tmp[0][0]);
	move_up(tmp);
	rec(dept+1, tmp);
	copy(&arr[0][0], &arr[0][0]+400, &tmp[0][0]);
	move_down(tmp);
	rec(dept+1,tmp);
	copy(&arr[0][0], &arr[0][0]+400, &tmp[0][0]);
	move_left(tmp);
	rec(dept+1,tmp);
	copy(&arr[0][0], &arr[0][0]+400, &tmp[0][0]);
	move_right(tmp);
	rec(dept+1,tmp);
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> map[i][j];
	rec(0, map);
	cout << big_block;
	return 0;
}
