/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   멀리뛰기.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:18:20 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/17 11:02:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
	vector<long long> dp;
	dp.resize(n+1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i=3; i<=n; ++i)
		dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
	return dp[n];
}
