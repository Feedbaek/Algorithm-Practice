/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12100_2048 (Easy).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:07:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/16 11:32:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int map[20][20];
int n;

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> map[i][j];
	return 0;
}
