/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   할인 행사.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:22:31 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/11 10:22:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

bool check_number(vector<int>& number) {
	for (int i=0; i<number.size(); ++i) {
		if (number[i] > 0)
			return false;
	}
	return true;
}
void find_want(vector<string>& want, vector<int>& number, string target, int value) {
	for (int i=0; i<want.size(); ++i) {
		if (want[i] == target)
			number[i] += value;
	}
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	for (int i=0; i<10; ++i)
		find_want(want, number, discount[i], -1);
	if (check_number(number))
		++answer;
	for (int i=0; i+10<discount.size(); ++i) {
		find_want(want, number, discount[i], 1);
		find_want(want, number, discount[i+10], -1);
		if (check_number(number))
			++answer;
	}
	return answer;
}
