/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1149_RGB거리.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:56:12 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/20 11:26:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, g, b;
	int rgb[3] = {0,};
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> r >> g >> b;
		r += min(rgb[1], rgb[2]);
		g += min(rgb[0], rgb[2]);
		b += min(rgb[0], rgb[1]);
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	}
	cout << min(rgb[0], min(rgb[1], rgb[2]));
}
