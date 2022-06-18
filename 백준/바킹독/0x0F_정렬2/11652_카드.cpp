/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11652_카드.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:19:35 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/18 11:19:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long x;
	vector<long long> input;
	vector<pair<long long, int>> v;
	cin >> n;
	input.reserve(n);
	for (int i=0; i<n; i++) {
		cin >> x;
		input.push_back(x);
	}
	sort(input.begin(), input.end());
	long long prev = 0;
	for (int i=0; i<input.size(); i++) {
		if (input[i] != prev) {
			v.push_back(make_pair(input[i], 1));
			prev = input[i];
		} else
			v.back().second++;
	}
	pair<long long, int> max = make_pair(0, 0);
	for (int i=0; i<v.size(); i++)
		if (max.second < v[i].second)
			max = v[i];
	cout << max.first;
}
