/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1463_1로 만들기.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:48:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/19 18:02:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int v[1000001];
	cin >> n;
	v[0] = 0;
	for (int i=2; i<=n; i++) {
		v[i] = v[i - 1] + 1;
		if (i % 3 == 0)
			v[i] = min(v[i], v[i / 3] + 1);
		if (i % 2 == 0)
			v[i] = min(v[i], v[i / 2] + 1);
	}
	cout << v[n];
}
