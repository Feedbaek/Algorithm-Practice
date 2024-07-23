/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11931_수 정렬하기 4.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:04:03 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/11 10:29:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

/*
퀵 정렬

int arr[1000000];

void swap(int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

void q_sort(int st, int en) {
	if (st + 1 >= en)
		return ;
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;
	while (1) {
		while (l <= r && arr[l] > pivot)
			l++;
		while (l <= r && arr[r] < pivot)
			r--;
		if (l > r)
			break;
		swap(l, r);
	}
	swap(st, r);
	q_sort(st, r);
	q_sort(r+1, en);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	q_sort(0, n);
	for (int i=0; i<n; i++)
		cout << arr[i] << "\n";
	return 0;
}
*/

int arr[1000000];
int tmp[1000000];

void merge(int st, int en, int mid) {
	int lidx = st;
	int ridx = mid;
	for (int i=st; i<en; i++) {
		if (lidx != mid && (ridx == en || arr[lidx] > arr[ridx]))
			tmp[i] = arr[lidx++];
		else
			tmp[i] =  arr[ridx++];
	}
	for (int i=st; i<en; i++)
		arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
	if (st + 1 == en)
		return ;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en, mid);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	merge_sort(0, n);
	for (int i=0; i<n; i++)
		cout << arr[i] << "\n";
	return 0;
}
