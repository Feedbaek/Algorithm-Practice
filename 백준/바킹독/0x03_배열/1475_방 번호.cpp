/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1475_방 번호.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:44:07 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/23 22:13:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string N;
	int max = 0;
	vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	cin >> N;
	for (char c:N)
		v[c-'0']++;
	v[6] = ((v[6] + v[9]) / 2) + ((v[6] + v[9]) % 2);
	v[9] = v[6];
	for (int i:v)
		if (i > max)
			max = i;
	cout << max;
	return (0);
}
