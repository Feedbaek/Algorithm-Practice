/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   주차 요금 계산.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:51:03 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/09 14:29:29 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	map<int, int> total;
	map<int, int> car_in;
	int m_time, car_num, new_value, time, f_sum;
	string rec[3];
	for (int i=0; i<records.size(); ++i) {
		rec[0] = records[i].substr(0, 5);
		rec[1] = records[i].substr(6, 4);
		rec[2] = records[i].substr(11, records[i].size() - 11);
		m_time = (rec[0][0]-'0') * 600 + (rec[0][1]-'0') * 60 + (rec[0][3]-'0') * 10 + (rec[0][4]-'0');
		car_num = stoi(rec[1]);
		if (rec[2] == "IN") {
			car_in[car_num] = m_time;
		} else {
			total[car_num] = total[car_num] + m_time - car_in[car_num];
			car_in.erase(car_num);
		}
	}
	while (!car_in.empty()) {
		total[(*car_in.begin()).first] = total[(*car_in.begin()).first] + 1439 - (*car_in.begin()).second;
		car_in.erase((*car_in.begin()).first);
	}
	map<int, int>::iterator iter = total.begin();
	for (int i=0; i<total.size(); ++i) {
		time = (*iter++).second;
		f_sum = fees[1];
		if (time > fees[0]) {
			time -= fees[0];
			while (time > 0) {
				f_sum += fees[3];
				time -= fees[2];
			}
		}
		answer.push_back(f_sum);
	}
	return answer;
}
