/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1874_스택 수열.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:45:46 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/26 12:12:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	char v[200000];
	int v_idx = 0;
	int stack[100000];
	int last_idx = -1;
	cin >> n;
	for (int i=0, x=0, c; i<n; i++) {
		cin >> c;
		for (; x<c; x++) {
			v[v_idx++] ='+';
			stack[++last_idx] = x+1;
		}
		if (stack[last_idx] != c) {
			cout << "NO" << '\n';
			return (0);
		}
		v[v_idx++] = '-';
		last_idx--;
	}
	for (int i=0; i<v_idx; i++)
		cout << v[i] << '\n';
	return (0);
}
