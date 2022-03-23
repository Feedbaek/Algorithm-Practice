/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10871_X보다 작은 수.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:42:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/23 20:55:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, nbr;

	cin >> n >> x;
	while (n--) {
		cin >> nbr;
		if (nbr < x)
			cout << nbr << " ";
	}
	return (0);
}
