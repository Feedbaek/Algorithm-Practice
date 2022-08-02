/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   피로도.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:34:41 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/02 11:12:50 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

int visited[8];

int back_tracking(int k, vector<vector<int>>& dungeons) {
	int max = 0, tmp = 0;
	for (int i=0; i<dungeons.size(); ++i)
		if (!visited[i] && k>=dungeons[i][0]) {
			visited[i] = 1;
			tmp = back_tracking(k-dungeons[i][1], dungeons);
			if (tmp > max)
				max = tmp;
			visited[i] = 0;
		}
	tmp = 0;
	for (int i=0; i<dungeons.size(); ++i)
		if (visited[i] == 1)
			++tmp;
	if (max > tmp)
		return max;
	return tmp;
}

int solution(int k, vector<vector<int>> dungeons) {
	return back_tracking(k, dungeons);
}
