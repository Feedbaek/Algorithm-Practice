/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1074_Z.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:24:16 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/19 09:30:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int r, c, ret;

void	z(int n, int x, int y) {
	if (n == 0) {
		if (x == r && y == c)
			cout << ret;
		return ;
	}
	int mov = 1 << (n-1);
	if (x+mov > r) {
		if (y+mov > c)
			z(n-1, x, y);
		else {
			ret += mov * mov;
			z(n-1, x, y+mov);
		}
	}
	else {
		ret += (2 * mov * mov);
		if (y+mov > c)
			z(n-1, x+mov, y);
		else  {
			ret += mov * mov;
			z(n-1, x+mov, y+mov);
		}
	}
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N >> r >> c;
	z(N, 0, 0);
	return (0);
}
