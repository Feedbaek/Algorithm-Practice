/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   롤케이크 자르기.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:05:18 by minskim2          #+#    #+#             */
/*   Updated: 2023/02/08 10:50:45 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
	int answer = 0;
	unordered_map<int, int> _bro, _chull;

	for (int i=0; i<topping.size(); ++i)
		_bro[topping[i]] += 1;

	for (int i=0; i<topping.size(); ++i) {
		_chull[topping[i]] += 1;
		_bro[topping[i]] -= 1;

		if (_bro[topping[i]] == 0)
			_bro.erase(topping[i]);

		if (_bro.size() == _chull.size())
			++answer;
	}

	return answer;
}
