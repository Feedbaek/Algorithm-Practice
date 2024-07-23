/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12865_평범한 배낭.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:05:42 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/10 19:08:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> arr[100];
int sum[101][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			if (j - arr[i].first < 0)
				sum[i][j] = sum[i-1][j];
			else
				sum[i][j] = max(sum[i-1][j], sum[i-1][j-arr[i].first] + arr[i].second);
		}
	}
	cout << sum[n][k] ;
}
