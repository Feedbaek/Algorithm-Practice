/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   쿼드압축 후 개수 세기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:03:30 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/21 10:37:14 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

vector<int> answer = {0, 0};

void rec(int r, int c, int size, vector<vector<int>>& arr) {
	for (int i=r; i<r+size; ++i)
		for (int j=c; j<c+size; ++j)
			if (arr[i][j] != arr[r][c]) {
				rec(r, c, size / 2, arr);
				rec(r, c+(size/2), size / 2, arr);
				rec(r+(size/2), c, size / 2, arr);
				rec(r+(size/2), c+(size/2), size / 2, arr);
				return ;
			}
	answer[arr[r][c]] += 1;
}

vector<int> solution(vector<vector<int>> arr) {
	rec(0, 0, arr.size(), arr);
	return answer;
}
