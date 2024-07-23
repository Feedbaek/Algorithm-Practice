/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1654_랜선 자르기.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:49:58 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/19 20:19:54 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int k, n;
ll len;
vector<ll> v;

bool check_n() {
	int cnt = 0;
	for (int i=0; i<k; i++) {
		cnt += (v[i] / len);
	}
	if (cnt >= n)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	int x;
	ll max = 0;
	for (int i=0; i<k; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	ll st = 0;
	ll en = v.back();
	while (st < en) {
		len = (st + en + 1) / 2;
		if (check_n()) {
			max = len;
			st = len;
		}
		else {
			en = len - 1;
		}
	}
	cout << max;
	return 0;
}
