/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   택배상자.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:48:37 by minskim2          #+#    #+#             */
/*   Updated: 2023/02/08 11:06:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	vector<int> _sub_belt;

	for (int box=1; box<=order.size(); ++box) {
		_sub_belt.push_back(box);

		while (!_sub_belt.empty() && _sub_belt.back() == order[answer]) {
			_sub_belt.pop_back();
			++answer;
		}
	}

	return answer;
}
