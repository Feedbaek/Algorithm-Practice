/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   거리두기 확인하기.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:20:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/26 11:12:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

bool is_valid(int i, int j, vector<string>& map) {
	if (i>0 && map[i-1][j] == 'P')
		return false;
	if (i<4 && map[i+1][j] == 'P')
		return false;
	if (j>0 && map[i][j-1] == 'P')
		return false;
	if (j<4 && map[i][j+1] == 'P')
		return false;
	if (i>0 && j>0 && map[i-1][j-1] == 'P' && (map[i][j-1] != 'X' || map[i-1][j] != 'X'))
		return false;
	if (i>0 && j<4 && map[i-1][j+1] == 'P' && (map[i][j+1] != 'X' || map[i-1][j] != 'X'))
		return false;
	if (i<4 && j>0 && map[i+1][j-1] == 'P' && (map[i+1][j] != 'X' || map[i][j-1] != 'X'))
		return false;
	if (i<4 && j<4 && map[i+1][j+1] == 'P' && (map[i+1][j] != 'X' || map[i][j+1] != 'X'))
		return false;
	if (i>1 && map[i-2][j] == 'P' && map[i-1][j] != 'X')
		return false;
	if (i<3 && map[i+2][j] == 'P' && map[i+1][j] != 'X')
		return false;
	if (j>1 && map[i][j-2] == 'P' && map[i][j-1] != 'X')
		return false;
	if (j<3 && map[i][j+2] == 'P' && map[i][j+1] != 'X')
		return false;
	return true;
}

int check_map(vector<string>& map) {
	for (int i=0; i<5; ++i)
		for (int j=0; j<5; ++j)
			if (map[i][j] == 'P' && !is_valid(i, j, map))
				return 0;
	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int n=0; n<5; ++n)
		answer.push_back(check_map(places[n]));
	return answer;
}
