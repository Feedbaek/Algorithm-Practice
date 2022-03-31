/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5430_AC.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:25:59 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/31 19:27:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
using namespace std;

int	P(deque<int>& dq, string& p, int& direct) {
	for (int i=0; i<p.size(); i++) {
		if (p.at(i) == 'R')
			direct *= -1;
		else if (p.at(i) == 'D') {
			if (dq.empty())
				return (0);
			if (direct == 1)
				dq.pop_front();
			else
				dq.pop_back();
		}
	}
	return (1);
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	t;
	string p;
	int	n;
	string arr;
	deque<int> dq;
	int	direct = 1;
	cin >> t;
	for (int i=0; i<t; i++) {
		direct = 1;
		cin >> p >> n >> arr;
		dq.clear();
		for (int j=0, sum=0, x=0; j<arr.size(); j++) {
			if (arr.at(j) >= '0' && arr.at(j) <= '9')
				x = x * 10 + arr.at(j) - '0';
			else if (x != 0) {
				dq.push_back(x);
				x = 0;
			}
		}
		if (!P(dq, p, direct)) {
			cout << "error\n";
			continue;
		}
		cout << '[';
		if (direct == 1)
			for (int i=0; i<dq.size(); i++) {
				cout << dq[i];
				if (i != dq.size()-1)
					cout << ',';
			}
		else
			for (int i=dq.size()-1; i>=0; i--) {
				cout << dq[i];
				if (i != 0)
					cout << ',';
			}
		cout << "]\n";
	}
	return (0);
}
