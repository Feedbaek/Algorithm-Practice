/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3020_개똥벌레.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:04:07 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/23 17:37:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int n, h, min_sum;
vector<int> v;
vector<int> ret_sum;

bool check_n(int mid) {
	if (mid >= min_sum)
		return true;
	int cnt = 0;
	for (int height=1; height<=h; height++) {
		cnt = 0;
		if (ret_sum[height - 1] != -1) {
			if (ret_sum[height - 1] > mid)
				continue;
			return true;
		}
		for (int i=0; i<n; i++) {
			if (i % 2 == 0) {
				if (height <= v[i])
					cnt++;
			} else {
				if (height > h - v[i])
					cnt++;
			}
		}
		ret_sum[height - 1] = cnt;
		if (cnt < min_sum)
			min_sum = cnt;
		if (cnt <= mid)
			return true;
	}
	return false;
}

int find_ret() {
	int cnt = 0;
	for (int i=0; i<h; i++)
		if (ret_sum[i] == min_sum)
			cnt++;
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h;
	int x;
	v.reserve(n);
	ret_sum.resize(h, -1);
	min_sum = n;
	for (int i=0; i<n; i++) {
		cin >> x;
		v.push_back(x);
	}
	int st = -1;
	int en = n;
	int mid;
	while (st < en) {
		mid = (st+en+1) / 2;
		if (check_n(mid))
			en = mid - 1;
		else
			st = mid;
	}
	x = find_ret();
	cout << min_sum << " " << x;
	return 0;
}
