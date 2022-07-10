/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12865_평범한 배낭.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:05:42 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/09 22:38:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> arr[100];
int sum[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr+n);
	for (int i=0; i<n; i++)
		cout << i+1 <<" : " << arr[i].first << " " << arr[i].second << "\n";
	cout << " ============= \n";
	//for (int w=1, i=0; w<=k; w++) {
	//	sum[w] = sum[w-1];
	//	if (i == n || w - arr[i].first < 0) {
	//		continue;;
	//	}
	//	sum[w] = max(sum[w], sum[w - arr[i].first] + arr[i].second);
	//	i++;
	//	//cout << w <<" : "<< sum[w] << "\n";
	//}
	for (int w=1; w<=k; w++) {
		for (int i=0; i<n; i++) {
			if (w < arr[i].first)
				break;
			if (w - arr[i].first < arr[i].first)
				sum[w] = max(sum[w], sum[w - arr[i].first] + arr[i].second);
		}
	}
	for (int i=0; i<=k; i++) {
		cout << i <<" : " << sum[i] << "\n";
	}
}
