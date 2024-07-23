/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3273_두 수의 합.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:19:28 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/23 22:42:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, x, answer = 0;
	int arr[2000001] = {};
	vector<int> input;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		input.push_back(a);
		arr[a]++;
	}
	cin >> x;
	for (int i:input)
		if (x-i > 0 && arr[x-i])
			answer++;
	cout << answer / 2;
}
