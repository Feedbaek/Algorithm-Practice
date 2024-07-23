/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1158_요세푸스 문제.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 08:21:40 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/24 09:37:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int	main (void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	list<int> li;
	list<int>::iterator iter;
	vector<int> v;
	cin >> n >> k;
	for (int i=0; i<n; i++)
		li.push_back(i+1);
	iter = li.begin();
	while (!li.empty()) {
		for (int i=0; i<k-1; i++) {
			iter++;
			if (iter == li.end())
				iter = li.begin();
		}
		v.push_back(*iter);
		iter = li.erase(iter);
		if (iter == li.end())
			iter = li.begin();
	}
	cout << '<';
	for (int i=0; i<n; i++) {
		cout << v[i];
		if (i != n-1)
			cout << ", ";
	}
	cout << '>';
	return (0);
}
