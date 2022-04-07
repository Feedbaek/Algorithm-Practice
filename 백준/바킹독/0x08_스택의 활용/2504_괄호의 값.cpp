/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2504_괄호의 값.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:56:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/07 09:20:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int prev;
	int pprev;
	string str;
	vector<char> v;
	vector<int> ret;
	cin >> str;
	for (char c:str) {
		if (c == ')') {
			if (!v.empty() && v.back()=='(') {
				//prev = 0;
				//if (!ret.empty()) {
				//	prev = ret.back();
				//	ret.pop_back();
				//}
				//ret.push_back(prev+2);
			}
			else if (!v.empty() && (v.back()==')' || v.back()==']')) {
				prev = 1;
				pprev = 1;
				if (!ret.empty()) {
					prev = ret.back();
					ret.pop_back();
				}
				if (!ret.empty()) {
					pprev = ret.back();
					ret.pop_back();
				}
				ret.push_back(prev*pprev);
			}
			else {
				cout << "zero1";
				return (0);
			}
		}
		else if (c == ']') {
			if (!v.empty() && v.back()=='[') {
				//prev = 0;
				//if (!ret.empty()) {
				//	prev = ret.back();
				//	ret.pop_back();
				//}
				//ret.push_back(prev+3);
			}
			else if (!v.empty() && (v.back()==']' || v.back()==')')) {
				prev = 1;
				pprev = 1;
				if (!ret.empty()) {
					prev = ret.back();
					ret.pop_back();
				}
				if (!ret.empty()) {
					pprev = ret.back();
					ret.pop_back();
				}
				ret.push_back(prev*pprev);
			}
			else {
				cout << "zero2";
				return (0);
			}
		}
		else if (c == '(') {
			if (!v.empty() && (v.back()==')' || v.back()==']')) {
				prev = 0;
				if (!ret.empty()) {
					prev = ret.back();
					ret.pop_back();
				}
				ret.push_back(prev+2);
			}
			else
				ret.push_back(2);
		}
		else if (c == '[') {
			if (!v.empty() && (v.back()==')' || v.back()==']')) {
				prev = 0;
				if (!ret.empty()) {
					prev = ret.back();
					ret.pop_back();
				}
				ret.push_back(prev+3);
			}
			else
				ret.push_back(3);
		}
		v.push_back(c);
	}
	//if (ret.size() != 1)
	//	cout << "zero3";
	//else
		cout << ret.back() << '\n';
	return (0);
}
