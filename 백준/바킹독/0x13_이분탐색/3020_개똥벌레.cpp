/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3020_개똥벌레.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:04:07 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/22 22:20:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int n, h, ret_sum;
vector<int> v;

bool check_n(int mid) {
	int cnt = 0;
	bool fg = false;
	int ret = 0;
	for (int j=0; j<h; j++) {
		cnt = 0;
		for (int i=0; i<n; i++) {
			if (i % 2 == 0) {
				if (j <= v[i])
					cnt++;
			}
			else {
				if (j > h - v[i])
					cnt++;
			}
			if (cnt > mid)
				break;
		}
		if (cnt <= mid) {
			if (cnt == mid)
				ret++;
			fg = true;
		}
	}
	if (fg)
		ret_sum = ret;
	return fg;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h;
	int x;
	for (int i=0; i<n; i++) {
		cin >> x;
		v.push_back(x);
	}
	int st = 0;
	int en = n;
	int mid;
	while (st <= en) {
		mid = (st+en+1) / 2;
		if (check_n(mid)) {
			en = mid - 1;
		} else {
			st = mid + 1;
		}
	}
	en++;
	//int cnt = 0;
	//int ret = 0;
	//for (int j=0; j<h; j++) {
	//	cnt = 0;
	//	for (int i=0; i<n; i++) {
	//		if (i % 2 == 0) {
	//			if (j <= v[i])
	//				cnt++;
	//		}
	//		else {
	//			if (j > h - v[i])
	//				cnt++;
	//		}
	//		if (cnt > en)
	//			break;
	//	}
	//	if (cnt == en)
	//		ret++;
	//}
	cout << en << " " << ret_sum;
	return 0;
}
