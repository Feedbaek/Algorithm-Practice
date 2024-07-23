/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15688_수 정렬하기 5.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:27:24 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/11 10:52:05 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int arr[2000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		arr[x+1000000]++;
	}
	for (int i=0, cnt=0; cnt<n; ) {
		if (arr[i] == 0)
			i++;
		else {
			cout << i-1000000 << "\n";
			arr[i]--;
			cnt++;
		}
	}
	return 0;
}
