/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   게임 맵 최단거리.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:37:08 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/02 10:31:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<vector>
#include<deque>
using namespace std;

int visited[100][100];

int solution(vector<vector<int> > maps)
{
	int n = maps.size(), m = maps[0].size();
	deque<vector<int> > q;
	q.push_back({0, 0, 0});
	vector<int> tmp;
	visited[0][0] = 1;
	while (!q.empty()) {
		tmp = q.front();
		if (tmp[0] == n-1 && tmp[1] == m-1)
			return tmp[2]+1;
		if (tmp[0]+1<n && !visited[tmp[0]+1][tmp[1]] && maps[tmp[0]+1][tmp[1]] == 1) {
			q.push_back({tmp[0]+1, tmp[1], tmp[2]+1});
			visited[tmp[0]+1][tmp[1]] = 1;
		}
		if (tmp[0]>0 && !visited[tmp[0]-1][tmp[1]] && maps[tmp[0]-1][tmp[1]] == 1) {
			q.push_back({tmp[0]-1, tmp[1], tmp[2]+1});
			visited[tmp[0]-1][tmp[1]] = 1;
		}
		if (tmp[1]+1<m && !visited[tmp[0]][tmp[1]+1] && maps[tmp[0]][tmp[1]+1] == 1) {
			q.push_back({tmp[0], tmp[1]+1, tmp[2]+1});
			visited[tmp[0]][tmp[1]+1] = 1;
		}
		if (tmp[1]>0 && !visited[tmp[0]][tmp[1]-1] && maps[tmp[0]][tmp[1]-1] == 1) {
			q.push_back({tmp[0], tmp[1]-1, tmp[2]+1});
			visited[tmp[0]][tmp[1]-1] = 1;
		}
		q.pop_front();
	}
	return -1;
}
