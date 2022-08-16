/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k진수에서 소수 개수 구하기.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:11:01 by minskim2          #+#    #+#             */
/*   Updated: 2022/08/16 11:12:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
using namespace std;

string make_n(int n, int k) {
	string ret = "";
	while (n) {
		ret += (n % k) + '0';
		n /= k;
	}
	return ret;
}

bool is_prime(long long n) {
	if (n == 0 || n == 1)
		return false;
	for (long long i=2; i*i<=n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int solution(int n, int k) {
	int answer = 0;
	string tmp = "0";
	string new_n = make_n(n, k);
	for (int i=new_n.size()-1; i>=0; --i) {
		if (new_n[i] != '0') {
			tmp += new_n[i];
		} else {
			if (is_prime(stol(tmp)))
				++answer;
			tmp = "0";
		}
	}
	if (is_prime(stol(tmp)))
		++answer;
	return answer;
}
