/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   징검다리 건너기.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:31:54 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/22 18:33:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
	int n = stones.size();
	int st = 0;
	int en = 200000000;
	int mid, cnt;
	while (st < en) {
		mid = (st + en + 1) / 2;
		cnt = 0;
		for (int i=0; i<n; i++) {
			if (stones[i] - mid < 0)
				cnt++;
			else
				cnt = 0;
			if (cnt == k) {
				break;
			}
		}
		if (cnt == k) {
			en = mid - 1;
		}
		else {
			st = mid;
		}
	}
	return st;
}
