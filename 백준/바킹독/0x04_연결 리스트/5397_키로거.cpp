/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5397_키로거.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:47:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/23 23:06:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	cin >> n;
	for (int i=0; i<n; i++) {
		list<char> li;
		list<char>::iterator iter = li.end();
		cin >> str;
		for (char c:str) {
			if (c == '<') {
				if (iter != li.begin())
					iter--;
			}
			else if (c == '>') {
				if (iter != li.end())
					iter++;
			}
			else if (c == '-') {
				if (iter != li.begin())
					iter = li.erase(--iter);
			}
			else {
				li.insert(iter, c);
			}
		}
		for (char c:li)
			cout << c;
		cout << '\n';
	}
	return (0);
}
