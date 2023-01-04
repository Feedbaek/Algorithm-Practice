/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1차] 프렌즈4블록.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:49:56 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/04 11:49:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	deque<pair<int, int>> q;

	while (true) {
		for (int r=0; r<m; ++r) {
			for (int c=0; c<n; ++c) {
				char ch = board[r][c];
				if (r>0 && c>0 && ch != '0' && ch == board[r][c-1] && ch == board[r-1][c] && ch == board[r-1][c-1])
					q.push_back(make_pair(r, c));
			}
		}
		if (q.empty())
			break;
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			board[r][c] = '0';
			board[r][c-1] = '0';
			board[r-1][c] = '0';
			board[r-1][c-1] = '0';
			q.pop_front();
		}
		for (int r=m-1; r>=0; --r) {
			for (int c=n-1; c>=0; --c) {
				if(board[r][c] == '0') {
					for (int i=1; r-i >= 0; ++i) {
						if (board[r-i][c] != '0') {
							board[r][c] = board[r-i][c];
							board[r-i][c] = '0';
							break;
						}
					}
				}
			}
		}
	}
	for (int r=0; r<m; ++r) {
		for (int c=0; c<n; ++c) {
			if (board[r][c] == '0')
				++answer;
		}
	}
	return answer;
}
