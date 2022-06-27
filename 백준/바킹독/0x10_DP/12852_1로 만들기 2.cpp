/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12852_1로 만들기 2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:19 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/27 12:10:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int arr[1000001];
int num[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=2; i<=n; i++) {
		arr[i] = arr[i-1] + 1;
		num[i] = i - 1;
		if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
			arr[i] = arr[i / 3] + 1;
			num[i] = i / 3;
		}
		if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
			arr[i] = arr[i / 2] + 1;
			num[i] = i / 2;
		}
	}
	cout << arr[n] << '\n';
	cout << n << " ";
	for (int i=n; i!=1; i=num[i])
		cout << num[i] << ' ';
}
