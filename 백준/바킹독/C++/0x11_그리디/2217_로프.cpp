/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2217_로프.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:54:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/08 12:01:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[100000];
	int n, ret=0;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	for (int i=n-1; i>=0; i--)
		ret = max(ret, arr[i] * (n-i));
	cout << ret;
}
