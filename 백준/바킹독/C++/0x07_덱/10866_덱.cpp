/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10866_덱.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:22:15 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/31 08:47:08 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

const int	MX = 1000005;
int	deq[2*MX+1];
int	head = MX;
int	tail = MX;

void	push_front(int x) {
	deq[head--] = x;
}
void	push_back(int x) {
	deq[++tail] = x;
}
void	pop_front(void) {
	if (tail == head)
		cout << -1 << '\n';
	else
		cout << deq[++head] << '\n';
}
void	pop_back(void) {
	if (tail == head)
		cout << -1 << '\n';
	else
		cout << deq[tail--] << '\n';
}
void	size(void) {
	cout << tail - head << '\n';
}
void	empty(void) {
	if (tail == head)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}
void	front(void) {
	if (tail == head)
		cout << -1 << '\n';
	else
		cout << deq[head+1] << '\n';
}
void	back(void) {
	if (tail == head)
		cout << -1 << '\n';
	else
		cout << deq[tail] << '\n';
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;
	string	input;
	cin >> n;
	for (int i=0, x; i<n; i++) {
		cin >> input;
		if (input == "push_front") {
			cin >> x;
			push_front(x);
		}
		else if (input == "push_back") {
			cin >> x;
			push_back(x);
		}
		else if (input == "pop_front")
			pop_front();
		else if (input == "pop_back")
			pop_back();
		else if (input == "size")
			size();
		else if (input == "empty")
			empty();
		else if (input == "front")
			front();
		else if (input == "back")
			back();
	}
	return (0);
}
