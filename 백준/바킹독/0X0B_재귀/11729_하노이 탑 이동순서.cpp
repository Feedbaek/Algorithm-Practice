/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11729_하노이 탑 이동순서.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 08:17:00 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 08:57:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int cnt = 0;
string	str = "";

void	rec(int a, int b, int c, int n) {
	if (n == 1) {
		str += to_string(a) + " " + to_string(c) + "\n";
		cnt++;
		return ;
	}
	rec(a, c, b, n-1);
	rec(a, b, c, 1);
	rec(b, a, c, n-1);
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	cin >> n;
	rec(1, 2, 3, n);
	cout << cnt << '\n' << str;
	return (0);
}
