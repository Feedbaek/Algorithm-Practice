/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   수식 최대화.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:34:21 by minskim2          #+#    #+#             */
/*   Updated: 2023/01/25 11:34:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>

using namespace std;

long long oper(long long a, long long b, char op) {
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	return a * b;
}

string new_expression(string& expression, char op) {
	string new_exp = "";
	bool flag = false;
	int st=0;
	long long prev=0;

	for (int i=1; i<expression.size(); ++i) {
		if (st != i && (expression[i] < '0' || expression[i] > '9')) { // 연산자 나오면
			if (flag) {
				prev = oper(prev, stoll(&(expression[st])), op);
				if (expression[i] != op) {
					new_exp += to_string(prev);
					new_exp.push_back(expression[i]);
					flag = false;
				}
			}
			else {
				if (expression[i] == op) {
					prev = stoll(&(expression[st]));
					flag = true;
				}
				else
					new_exp += expression.substr(st, i-st+1);
			}
			st = i + 1;
		}
	}
	if (flag) {
		prev = oper(prev, stoll(&(expression[st])), op);
		new_exp += to_string(prev);
	}
	else
		new_exp += expression.substr(st, expression.size()-st);
	return new_exp;
}

long long fine_reward(string& expression, string opers) {
	string new_exp = expression;

	for (int i=0; i<3; ++i) {
		if (new_exp.find(opers[i]) != string::npos)
			new_exp = new_expression(new_exp, opers[i]);
	}
	return abs(stoll(new_exp));
}

long long solution(string expression) {
	long long answer = 0, ret = 0;
	string opers[6] = {"*+-", "*-+", "+*-", "+-*", "-*+", "-+*"};

	for (int i=0; i<6; ++i) {
		ret = fine_reward(expression, opers[i]);
		if (ret > answer)
			answer = ret;
	}
	return answer;
}
