/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11047_동전 0.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:29:39 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/01 11:51:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[10];
	int n, k, cnt=0;
	cin >> n >> k;

	for (int i=0; i<n; i++)
		cin >> arr[i];
	for (int i=n-1; i>=0; i--) {
		cnt += k / arr[i];
		k %= arr[i];
	}
	cout << cnt;
}
