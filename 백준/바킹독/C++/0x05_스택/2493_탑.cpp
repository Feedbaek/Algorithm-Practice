/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2493_탑.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:28:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/26 21:21:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	stack<int> stack_a;
	stack<int> stack_b;
	vector<int> v;
	map<int, int> map;
	cin >> n;
	for (int i=0, x; i<n; i++) {
		cin >> x;
		stack_a.push(x);
		v.push_back(x);
	}
	for (int i=0, a, b; i<n; i++) {
		a = stack_a.top();
		stack_a.pop();
		if (!stack_b.empty())
			b = stack_b.top();
		while (!stack_b.empty() && a > b) {
			map.insert({b, n-i});
			stack_b.pop();
			if (stack_b.empty())
				break;
			b = stack_b.top();
		}
		stack_b.push(a);
	}
	while (!stack_b.empty()) {
		map.insert({stack_b.top(), 0});
		stack_b.pop();
	}
	for (auto i:v)
		cout << map.find(i)->second << " ";
	return (0);
}
