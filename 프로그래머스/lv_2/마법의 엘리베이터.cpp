/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   마법의 엘리베이터.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:51:18 by minskim2          #+#    #+#             */
/*   Updated: 2023/08/16 22:51:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
#include <vector>

using namespace std;

int button[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
	100000000};

int solution(int storey) {
	int answer = 0;
	int c = 0;

	while (button[c] <= storey) c++;

	while (storey != 0) {
		if (storey >= button[c]) {
			storey -= button[c];
			answer++;
		}
		else if (abs(storey - button[c]) < storey - button[c - 1]) {
			storey = abs(storey - button[c]);
			answer++;
		}
		else c--;
	}

	return answer;
}
