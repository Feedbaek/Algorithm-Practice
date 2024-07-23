/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1629_곱셈.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:40:47 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 09:27:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	rec(long long a, long long b, long long c) {
	if (b == 1)
		return (a);
	if (b % 2 == 0)	// 짝수일 때
		return (rec((a * a) % c, b / 2, c) % c);
	return ((a * rec((a * a) % c, b / 2, c)) % c);	// 홀수일 때
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << rec(a % c, b, c);
	return (0);
}
