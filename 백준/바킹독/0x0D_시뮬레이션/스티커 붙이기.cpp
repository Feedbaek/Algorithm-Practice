/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   스티커 붙이기.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:07:32 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/07 10:04:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	map[40][40];
int	seal[10][10];

void	attach(int r, int c) {

}

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, r, c;
	cin >> n >> m >> k;
	for (int i=0; i<k; i++) {
		cin >> r >> c;
		for (int a=0; a<r; a++) {
			for (int b=0; b<c; b++) {
				cin >> seal[a][b];
				attach(r, c);
			}
		}
	}
}
