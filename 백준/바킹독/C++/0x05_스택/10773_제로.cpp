/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10773_제로.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:08:15 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/26 08:39:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <numeric>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int stack[100005];
	int last = -1;
	cin >> n;
	for (int i=0, x; i<n; i++) {
		cin >> x;
		if (x == 0 && last != -1)
			last--;
		else
			stack[++last] = x;
	}
	int sum = accumulate(stack, stack+last+1, 0);
	cout << sum;
	return (0);
}
