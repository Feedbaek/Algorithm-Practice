/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3020_개똥벌레.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:04:07 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/29 15:39:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int arr1[500001];	// 석순
int arr2[500001];	// 종유석
int hit[500001];	// 높이 별 충돌 수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, h, x;
	cin >> n >> h;
	for (int i=0; i<n; ++i) {
		cin >> x;
		if (i % 2 == 0)
			++arr1[x];
		else
			++arr2[x];
	}
	for (int i=1; i<=h; ++i) {
		arr1[i] += arr1[i-1];
		arr2[i] += arr2[i-1];
	}
	int min = n, cnt = 0;
	for (int i=1; i<=h; ++i) {
		hit[i] = n - (arr1[i-1] + arr2[h-i]);
		if (hit[i] <= min) {
			if (hit[i] == min)
				++cnt;
			else {
				cnt = 1;
				min = hit[i];
			}
		}
	}
	cout << min << " " << cnt;
	return 0;
}
