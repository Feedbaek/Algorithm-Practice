/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1026_보물.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:19:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/09 20:26:20 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum=0;
	int A[50];
	int B[50];
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i];
	for (int i=0; i<n; i++)
		cin >> B[i];
	sort(A, A+n);
	sort(B, B+n);
	for (int i=0; i<n; i++)
		sum += A[i] * B[n-1-i];
	cout << sum;
}
