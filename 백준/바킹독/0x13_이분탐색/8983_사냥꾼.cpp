/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8983_사냥꾼.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:34:24 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/22 20:04:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
using namespace std;

int m, n, l;
vector<int> v_m;
vector<pair<int, int>> animal;

bool check_n(int num) {
	int cnt = 0;
	int st, en, mid;
	for (auto p : animal) {
		st = 0;
		en = m-1;
		while (st < en) {
			mid = (st+en+1) / 2;
			if (v_m[mid] <= p.first)
				st = mid;
			else
				en = mid - 1;
		}
		if (abs(v_m[st] - p.first) + p.second <= l || abs(v_m[st+1] - p.first) + p.second <= l)
			cnt++;
		if (cnt >= num)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> l;
	int x, y;
	for (int i=0; i<m; i++) {
		cin >> x;
		v_m.push_back(x);
	}
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		animal.push_back(pair<int, int>(x, y));
	}
	sort(v_m.begin(), v_m.end());
	int st = 0;
	int en = n;
	int mid;
	while (st < en) {
		mid = (st+en+1) / 2;
		if (check_n(mid))
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
	return 0;
}
