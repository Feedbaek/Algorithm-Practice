/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   연속 부분 수열 합의 개수.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:01:12 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/06 10:55:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
	unordered_set<int> ret;
	int elem[1001] = {};

	elem[0] = elements[0];
	for (int i=1; i<elements.size(); ++i) {
		elem[i] = elem[i-1] + elements[i];
	}
	for (int len=1; len<=elements.size(); ++len) {
		for (int idx=0; idx<elements.size(); ++idx) {
			int sum = 0;
			if (idx + len >= elements.size()) {
				sum = elem[elements.size()-1] - elem[idx];
				sum += elem[(idx + len) % elements.size()];
			}
			else
				sum = elem[idx + len] - elem[idx];
			ret.insert(sum);
		}
	}
	return ret.size();
}

// 처음에 시도한 느린 방식

//int solution(vector<int> elements) {
//	unordered_set<int> ret;

//	for (int len=1; len<=elements.size(); ++len) {
//		for (int idx=0; idx<elements.size(); ++idx) {
//			int sum = 0;
//			for (int i=0; i<len; ++i) {
//				sum += elements[(idx+i) % elements.size()];
//			}
//			ret.insert(sum);
//		}
//	}
//	return ret.size();
//}
