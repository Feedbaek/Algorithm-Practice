/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17245_서버실.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:30:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/19 21:22:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int arr[1000][1000];
int n;
long long full_cnt;

bool	check_half(int height) {
	long long cnt = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (arr[i][j] < height)
				cnt += arr[i][j];
			else
				cnt += height;
		}
	}
	if (cnt >= (full_cnt + 1) / 2)
		return true;
	return false;
}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, max = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> arr[i][j];
			full_cnt += arr[i][j];
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	int st = 0;
	int en = max;
	int mid;
	int ret;
	while (st < en) {
		mid = (st+en+1) / 2;
		if (check_half(mid)) {
			en = mid - 1;
			ret = mid;
		}
		else {
			st = mid;
		}
	}
	cout << ret;
	return 0;
}
