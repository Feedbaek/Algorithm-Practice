/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15654_N과 M (5).cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:15:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/23 16:19:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int	main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	int	*arr = new int[n];
	int	*pick = new int[n];
	for (int i=0; i<n; i++) {
		cin >> x;
		arr[i] = x;
		if (n-m <= i)
			pick[i] = 0;
		else
			pick[i] = 1;
	}
	sort(arr, arr+n);
	do {

	} while(next_permutation(arr, arr+n));
}
