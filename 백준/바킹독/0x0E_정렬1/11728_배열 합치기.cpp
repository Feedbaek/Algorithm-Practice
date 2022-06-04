/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11728_배열 합치기.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:00:07 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/04 12:00:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	vector<int> A;
	vector<int> B;
	vector<int> C;
	for (int i=0; i<n; i++) {
		cin >> x;
		A.push_back(x);
	}
	for (int i=0; i<m; i++) {
		cin >> x;
		B.push_back(x);
	}
	int aidx = 0, bidx = 0;
	for (int i=0; i<n+m; i++) {
		if (aidx != n && (bidx == m || A[aidx] < B[bidx]))
			C.push_back(A[aidx++]);
		else
			C.push_back(B[bidx++]);
	}
	for (auto a : C)
		cout << a << " ";
	return 0;
}
