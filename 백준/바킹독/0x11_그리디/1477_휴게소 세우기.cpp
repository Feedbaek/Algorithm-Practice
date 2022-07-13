/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1477_휴게소 세우기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:16:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/13 14:47:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[52];
int n, m, l;
int ret;

bool mid_ok(int mid) {
	int cnt = 0;
	int tmp = 0;
	for (int i=0; i<=n; i++) {
		if (arr[i+1] - arr[i] > mid) {
			int div = 2;
			int diff = arr[i+1] - arr[i];
			int d;
			while (1) {
				d = diff / div;
				if (diff % div > 0)
					++d;
				if (d <= mid)
					break;
				++div;
			}
			cnt += div-1;
			if (tmp < d)
				tmp = d;
			if (cnt > m)
				return false;
		} else {
			if (tmp < arr[i+1] - arr[i])
				tmp = arr[i+1] - arr[i];
		}
	}
	if (ret > tmp)
		ret = tmp;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mid;
	cin >> n >> m >> l;
	for (int i=1; i<=n; i++)
		cin >> arr[i];
	arr[n+1] = l;
	sort(arr, arr+n+2);
	int st = 0, en = l;
	ret = l;
	while (st < en) {
		mid = (st + en + 1) / 2;
		if (mid_ok(mid))
			en = mid - 1;
		else
			st = mid;
	}
	cout << ret;
}
