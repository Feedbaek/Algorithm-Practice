/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   푸드 파이트 대회.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:15:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/11/05 10:15:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

string solution(vector<int> food) {
	string answer = "";
	for (int i=1; i<food.size(); ++i)
		for (int j=0; j<food[i]/2; ++j)
			answer += i + '0';
	answer += '0';
	for (int i=food.size()-1; i>0; --i)
		for (int j=0; j<food[i]/2; ++j)
			answer += i + '0';
	return answer;
}
