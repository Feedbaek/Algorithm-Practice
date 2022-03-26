/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1874_스택 수열.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:45:46 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/26 11:43:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<string> v;
	int stack[100000];
	int last_idx = -1;
	cin >> n;
	for (int i=0, x=0, flag=0; i<n; i++) {
		int c;
		cin >> c;
		for (; x<c; x++) {
			v.push_back("+");
			stack[++last_idx] = x+1;
		}
		if (stack[last_idx] != c) {
			cout << "NO" << '\n';
			return (0);
		}
		v.push_back("-");
		last_idx--;
	}
	for (string s:v)
		cout << s << '\n';
	return (0);
}
