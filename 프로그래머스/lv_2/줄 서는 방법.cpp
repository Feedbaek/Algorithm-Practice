/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   줄 서는 방법.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:32:43 by minskim2          #+#    #+#             */
/*   Updated: 2023/02/07 00:32:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	long long count = 0;
	long long factorial[21] = {1};
	bool visited[21] = {};

	for (int i=1; i<=20; ++i)
		factorial[i] = factorial[i-1] * i;

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			if (visited[j])
				continue;
			if (count + factorial[n-i] >= k) {
				answer.push_back(j);
				visited[j] = true;
				break;
			}
			count += factorial[n-i];
		}
	}
	return answer;
}
