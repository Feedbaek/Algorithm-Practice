/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11659_구간 합 구하기.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:05:24 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/27 10:48:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[100000];
	int n, m, i, j, ret;
	cin >> n >> m;
	cin >> arr[0];
	for (int k=1; k<n; k++) {
		cin >> arr[k];
		arr[k] += arr[k-1];
	}
	for (int k=0; k<m; k++) {
		cin >> i >> j;
		ret = arr[j-1];
		if (i >= 2)
			ret -= arr[i-2];
		cout << ret << '\n';
	}
}
