/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   성격 유형 검사하기.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:16:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/28 10:56:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	int ret[8] = {};
	for (int i=0; i<survey.size(); ++i) {
		if (choices[i] < 4) {
			if (survey[i][0] == 'R')
				ret[0] += 4 - choices[i];
			if (survey[i][0] == 'T')
				ret[1] += 4 - choices[i];
			if (survey[i][0] == 'C')
				ret[2] += 4 - choices[i];
			if (survey[i][0] == 'F')
				ret[3] += 4 - choices[i];
			if (survey[i][0] == 'J')
				ret[4] += 4 - choices[i];
			if (survey[i][0] == 'M')
				ret[5] += 4 - choices[i];
			if (survey[i][0] == 'A')
				ret[6] += 4 - choices[i];
			if (survey[i][0] == 'N')
				ret[7] += 4 - choices[i];
		} else {
			if (survey[i][1] == 'R')
				ret[0] += choices[i] - 4;
			if (survey[i][1] == 'T')
				ret[1] += choices[i] - 4;
			if (survey[i][1] == 'C')
				ret[2] += choices[i] - 4;
			if (survey[i][1] == 'F')
				ret[3] += choices[i] - 4;
			if (survey[i][1] == 'J')
				ret[4] += choices[i] - 4;
			if (survey[i][1] == 'M')
				ret[5] += choices[i] - 4;
			if (survey[i][1] == 'A')
				ret[6] += choices[i] - 4;
			if (survey[i][1] == 'N')
				ret[7] += choices[i] - 4;
		}
	}
	if (ret[0] >= ret[1])
		answer += "R";
	else
		answer += "T";
	if (ret[2] >= ret[3])
		answer += "C";
	else
		answer += "F";
	if (ret[4] >= ret[5])
		answer += "J";
	else
		answer += "M";
	if (ret[6] >= ret[7])
		answer += "A";
	else
		answer += "N";
	return answer;
}
