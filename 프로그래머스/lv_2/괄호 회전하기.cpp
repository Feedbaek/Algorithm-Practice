/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   괄호 회전하기.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 10:29:36 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/09 11:19:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0, idx;
	bool flag = true;
	vector<char> v_stack;
	for (int i=0; i<s.size(); ++i) {
		v_stack.clear();
		flag = true;
		for (int j=0; j<s.size(); ++j) {
			idx = (i+j) % s.size();
			if (s[idx] == '(')
				v_stack.push_back('(');
			else if (s[idx] == '[')
				v_stack.push_back('[');
			else if (s[idx] == '{')
				v_stack.push_back('{');
			else {
				if (!v_stack.empty() && v_stack.back() == '(' && s[idx] == ')')
					v_stack.pop_back();
				else if (!v_stack.empty() && v_stack.back() == '[' && s[idx] == ']')
					v_stack.pop_back();
				else if (!v_stack.empty() && v_stack.back() == '{' && s[idx] == '}')
					v_stack.pop_back();
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && v_stack.empty())
			++answer;
	}
	return answer;
}
