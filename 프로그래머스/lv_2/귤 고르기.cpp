/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   귤 고르기.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:22:27 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/03 09:23:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
using namespace std;

int arr[10000001];

int solution(int k, vector<int> tangerine) {
	int answer = 0;

	for (int i=0; i<tangerine.size(); ++i) {
		++arr[tangerine[i]];
	}
	sort(arr+1, arr+10000001);
	for (int i=10000000; i>1; --i) {
		k -= arr[i];
		++answer;
		if (k <= 0)
			break;
	}
	return answer;
}
