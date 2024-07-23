/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1931_회의실 배정.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:14:02 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/08 10:51:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pair<int, int>arr[100000];
	int n, time=0, cnt=0;
	cin >> n;
	for (int i=0, x, y; i<n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n, compare);
	for (int i=0; i<n; i++) {
		if (arr[i].first < time)
			continue;
		time = arr[i].second;
		cnt++;
	}
	cout << cnt;
}
