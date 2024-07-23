/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10799_쇠막대기.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:25:30 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 09:43:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	vector<char> v;
	int	ret = 0;
	int	cnt = 0;
	cin >> str;
	for (char c:str) {
		if (c == '(') {
			v.push_back(c);
			cnt++;
			ret++;
		}
		else {
			if (v.back() == '(') {
				cnt--;
				ret--;
				ret += cnt;
				v.push_back(c);
			}
			else
				cnt--;
		}
	}
	cout << ret << '\n';
	return (0);
}
