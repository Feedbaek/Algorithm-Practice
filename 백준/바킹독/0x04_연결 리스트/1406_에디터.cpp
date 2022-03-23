/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1406_에디터.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:41:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/23 20:41:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <sstream>
using namespace std;

int	main (void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> li;
	list<char>::iterator iter;
	string text;
	string buff;
	string input;
	int n;
	cin >> text;
	cin >> n;
	for (int i=0; i<text.size(); i++)
		li.push_back(text[i]);
	iter = li.end();
	cin.ignore(100, '\n');
	for (int i=0; i<n; i++) {
		getline(cin, input);
		istringstream is(input);
		while (getline(is, buff, ' ')) {
			if (buff == "L") {
				if (iter != li.begin())
					iter--;
			}
			else if (buff == "D") {
				if (iter != li.end())
					iter++;
			}
			else if (buff == "B") {
				if (iter != li.begin())
					iter = li.erase((--iter));
			}
			else if (buff == "P") {
				continue;
			}
			else
				li.insert(iter, buff[0]);
		}
	}
	for (auto i:li)
		cout << i;
	return (0);
}
