/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11726_2*n 타일링.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:42:41 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/20 12:24:35 by minskim2         ###   ########.fr       */
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
	arr[1] = 2;
	for (int i=2; i<n; i++)
		arr[i] = (arr[i-1] + arr[i-2]) % 10007;
	cout << arr[n-1];
}
