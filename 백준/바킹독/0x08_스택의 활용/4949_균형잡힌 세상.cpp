/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4949_균형잡힌 세상.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 08:34:51 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 09:05:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

void	getnextline(string buff) {
	vector<int> v;
	for (char c:buff) {
		if (c == '(')
			v.push_back(1);
		if (c == '[')
			v.push_back(2);
		if (c == ')') {
			if (v.empty() || v.back() != 1) {
				cout << "no\n";
				return;
			}
			v.pop_back();
		}
		if (c == ']') {
			if (v.empty() || v.back() != 2) {
				cout << "no\n";
				return;
			}
			v.pop_back();
		}
	}
	if (!v.empty()) {
		cout << "no\n";
		return ;
	}
	cout << "yes\n";
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string buff;
	while (1) {
		getline(cin, buff);
		if (buff == ".")
			break;
		getnextline(buff);
	}
	return (0);
}
