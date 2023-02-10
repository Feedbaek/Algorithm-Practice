/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   뒤에 있는 큰 수 찾기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:03:09 by minskim2          #+#    #+#             */
/*   Updated: 2023/02/10 11:04:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer, stack;

	answer.resize(numbers.size());
	for (int i=0; i<numbers.size(); ++i) {
		while (!stack.empty() && numbers[stack.back()] < numbers[i]) {
			answer[stack.back()] = numbers[i];
			stack.pop_back();
		}
		stack.push_back(i);
	}

	for (int i=0; i<stack.size(); ++i)
		answer[stack[i]] = -1;

	return answer;
}
