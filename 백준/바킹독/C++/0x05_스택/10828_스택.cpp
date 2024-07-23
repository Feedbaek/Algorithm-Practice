/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10828_스택.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:20:51 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/25 20:53:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
using namespace std;

void	push(int *stack, int &pos, int value) {
	stack[++pos] = value;
}
void	pop(int *stack, int &pos) {
	if (pos == -1)
		cout << -1 << '\n';
	else
		cout << stack[pos--] << '\n';
}
void	size(int pos) {
	cout << pos+1 << '\n';
}
void	empty(int pos) {
	if (pos == -1)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}
void	top(int *stack, int pos) {
	if (pos == -1)
		cout << -1 << '\n';
	else
		cout << stack[pos] << '\n';
}

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	stack[100005];
	int	pos = -1;
	int	n;
	int	value;
	string	cmd;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> value;
			push(stack, pos, value);
		}
		else if (cmd == "pop") {
			pop(stack, pos);
		}
		else if (cmd == "size") {
			size(pos);
		}
		else if (cmd == "empty") {
			empty(pos);
		}
		else if (cmd == "top") {
			top(stack, pos);
		}
	}
	return (0);
}
