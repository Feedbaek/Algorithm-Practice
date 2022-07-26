/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   삼각 달팽이.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:13:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/26 12:05:43 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

using namespace std;

int arr[1000][1000];

vector<int> solution(int n) {
	vector<int> answer;
	int num = 1, tmp;
	for (int step=0; ; ++step) {
		tmp = num;
		for (int i=2*step; i<n-step; ++i)
			arr[i][step] = num++;
		for (int i=step+1; i<n-2*step; ++i)
			arr[n-step-1][i] = num++;
		for (int i=n-step-2; i>2*step; --i)
			arr[i][i-step] = num++;
		if (tmp == num)
			break;
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<=i; ++j)
			answer.push_back(arr[i][j]);
	return answer;
}
