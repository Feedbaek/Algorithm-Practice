/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1932_정수 삼각형.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:26:32 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/19 20:48:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp, ret = 0;
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<=i; j++) {
			cin >> tmp;
			arr[i][j] += tmp;
			arr[i+1][j] = max(arr[i][j], arr[i+1][j]);
			arr[i+1][j+1] = max(arr[i][j], arr[i+1][j+1]);
		}
	for (int i=0; i<n; i++)
		if (arr[n-1][i] > ret)
			ret = arr[n-1][i];
	cout << ret;
}
