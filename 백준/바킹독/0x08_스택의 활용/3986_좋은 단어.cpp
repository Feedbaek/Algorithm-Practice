/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3986_좋은 단어.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:07:10 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/05 09:21:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	int	ret = 0;
	string str;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> str;
		vector<char> v;
		for (char c:str) {
			if (v.empty() || c != v.back())
				v.push_back(c);
			else
				v.pop_back();
		}
		if (v.empty())
			ret++;
	}
	cout << ret << '\n';
	return (0);
}
