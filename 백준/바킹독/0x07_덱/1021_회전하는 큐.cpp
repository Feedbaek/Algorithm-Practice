/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1021_회전하는 큐.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 09:50:52 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/31 10:45:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> dq;
	deque<int>::iterator iter;
	int n, m, x, sum = 0;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		dq.push_back(i+1);
	for (int i=0, cnt_l, cnt_r; i<m; i++) {
		cin >> x;
		cnt_l = 0;
		cnt_r = 0;
		iter = dq.begin();
		while (*iter != x) {
			if (iter == dq.begin())
				iter = dq.end();
			iter--;
			cnt_l++;
		}
		iter = dq.begin();
		while (*iter != x) {
			iter++;
			if (iter == dq.end())
				iter = dq.begin();
			cnt_r++;
		}
		if (cnt_l < cnt_r)
			while (cnt_l--) {
				dq.push_front(dq.back());
				dq.pop_back();
				sum++;
			}
		else
			while (cnt_r--) {
				dq.push_back(dq.front());
				dq.pop_front();
				sum++;
			}
		dq.pop_front();
	}
	cout << sum;
	return (0);
}
