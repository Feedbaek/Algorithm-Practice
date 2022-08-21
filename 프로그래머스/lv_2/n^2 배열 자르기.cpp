/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n^2 배열 자르기.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:45:13 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/21 12:42:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	int r = left / n, c = left % n;
	for (long long i=left; i<=right; ++i) {
		if (c <= r)
			answer.push_back(r+1);
		else
			answer.push_back(c+1);
		++c;
		if (c == n) {
			r += 1;
			c = 0;
		}
	}
	return answer;
}

