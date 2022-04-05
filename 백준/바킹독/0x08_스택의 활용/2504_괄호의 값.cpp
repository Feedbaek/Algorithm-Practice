/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2504_괄호의 값.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:56:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 12:42:43 by minskim2         ###   ########.fr       */
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
	vector<char> ret;
	cin >> str;
	for (char c:str) {
		if (c == ')') {
			if (!v.empty() && v.back()=='(')
		}
	}
	return (0);
}
