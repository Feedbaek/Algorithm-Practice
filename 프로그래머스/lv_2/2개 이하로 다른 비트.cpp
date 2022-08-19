/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2개 이하로 다른 비트.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:07:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/19 11:44:42 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

int where_zero_bit(long long num) {
	int i = 0;
	long long d = 1;
	while (num >= d) {
		if ((num & d) == d) {
			++i;
			d <<= 1;
		} else
			break;
	}
	return i;
}

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	int mov;
	long long tmp;
	for (int i=0; i<numbers.size(); ++i) {
		tmp = 1;
		mov = where_zero_bit(numbers[i]);
		if (mov > 1)
			tmp <<= (mov - 1);
		answer.push_back(numbers[i] + tmp);
	}
	return answer;
}
