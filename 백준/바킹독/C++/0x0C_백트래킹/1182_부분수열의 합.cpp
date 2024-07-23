/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1182_부분수열의 합.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 08:52:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/23 09:40:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int	ret = 0;

void	rec(int dept, int sum, int n, int s) {
	if (dept == n) {
		if (sum == s)
			ret++;
		return ;
	}
	rec(dept+1, sum+v[dept], n, s);
	rec(dept+1, sum, n, s);
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i=0, x; i<n; i++) {
		cin >> x;
		v.push_back(x);
	}
	rec(0, 0, n, s);
	if (s == 0)
		ret--;
	cout << ret;
	return (0);
}
