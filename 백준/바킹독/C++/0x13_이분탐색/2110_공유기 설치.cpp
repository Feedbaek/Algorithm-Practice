/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2110_공유기 설치.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:20:03 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/19 22:43:12 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int arr[200000];

bool check_d(int d) {
	for (int i=0; i<n-1; i++) {
		if (arr[i+1] - arr[i] >=)
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int st = 0;
	int en = arr[n-1];
	int d, ret;
	while (st < en) {
		d = (st + en + 1) / 2;
		if (check_d(d)) {
			st = d + 1;
			ret = d;
		}
		else {
			en = d;
		}
	}
	cout << d;
	return 0;
}
