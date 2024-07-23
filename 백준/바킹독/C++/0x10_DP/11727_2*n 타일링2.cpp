/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11727_2*n 타일링2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:41:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/20 12:43:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[1000];
	int n;
	cin >> n;
	arr[0] = 1;
	arr[1] = 3;
	for (int i=2; i<n; i++)
		arr[i] = (arr[i-1] + 2 * arr[i-2]) % 10007;
	cout << arr[n-1];
}
