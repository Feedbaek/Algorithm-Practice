/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10845_큐.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:58:03 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/28 23:22:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int			n;
	string		input;
	queue<int>	q;
	cin >> n;
	for (int i=0, x; i<n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> x;
			q.push(x);
		}
		else if (input == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (input == "size") {
			cout << q.size() << '\n';
		}
		else if (input == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (input == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}
