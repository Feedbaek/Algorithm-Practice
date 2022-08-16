/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   타겟 넘버.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:21:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/16 21:27:12 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int target, int dept, int sum) {
	if (dept == numbers.size()) {
		if (sum == target)
			++answer;
		return ;
	}
	dfs(numbers, target, dept+1, sum + numbers[dept]);
	dfs(numbers, target, dept+1, sum - numbers[dept]);
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0);
	return answer;
}
