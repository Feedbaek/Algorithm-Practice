/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2579_계단 오르기.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:23:01 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/19 22:24:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[300][2];
	int n;
	cin >> n;
	cin >> arr[0][0];
	for (int i=1; i<n; i++) {
		cin >> arr[i][0];
		arr[i][1] = arr[i][0] + arr[i-1][0];
		if (i > 1)
			arr[i][0] += max(arr[i-2][0], arr[i-2][1]);
	}
	cout << max(arr[n-1][0], arr[n-1][1]);
}
