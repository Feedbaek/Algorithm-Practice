/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1431_시리얼 번호.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:07:35 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/11 14:18:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dic_order(const string& s1, const string& s2) {
	for (int i=0; i<s1.length(); i++) {
		if (s1[i] < s2[i])
			return true;
		if (s1[i] > s2[i])
			return false;
	}
	return false;
}

int sum(const string& s) {
	int ret = 0;
	for (int i=0; i<s.length(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			ret += s[i] - '0';
	return ret;
}

bool cmp(const string& s1, const string& s2) {
	if (s1.length() < s2.length())
		return true;
	if (s1.length() > s2.length())
		return false;
	if (sum(s1) < sum(s2))
		return true;
	if (sum(s1) > sum(s2))
		return false;
	return dic_order(s1, s2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	cin >> n;
	vector<string> v;
	for (int i=0; i<n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto answer : v)
		cout << answer << "\n";
}
