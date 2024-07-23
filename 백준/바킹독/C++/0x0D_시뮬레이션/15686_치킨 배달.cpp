/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15686_치킨 배달.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:04:59 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/27 20:04:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

int n, m, min_distance;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int get_chickenDistance() {
	int min, ret = 0;
	for (auto p1 : home) {
		min = n * n;
		for (auto p2 : chicken) {
			if (min > abs(p1.first - p2.first) + abs(p1.second - p2.second))
				min = abs(p1.first - p2.first) + abs(p1.second - p2.second);
		}
		ret += min;
	}
	return ret;
}

void delete_chicken(vector<pair<int, int>>::iterator prev) {
	if (chicken.end() == prev) {
		if (chicken.size() == m && get_chickenDistance() < min_distance)
			min_distance = get_chickenDistance();
		return ;
	}
	pair<int, int> tmp = *prev;
	chicken.erase(prev);
	delete_chicken(prev);
	prev = chicken.insert(prev, tmp);
	delete_chicken(++prev);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int x, ret;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> x;
			if (x == 1)
				home.push_back(make_pair(i, j));
			else if (x == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	min_distance = 2100000000;
	delete_chicken(chicken.begin());
	cout << min_distance;
	return 0;
}
