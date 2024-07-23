/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17478_재귀함수가 뭔가요?.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:58:19 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/14 11:22:32 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

void	print_underBar(int n) {
	for (int i=0; i<n; i++)
		cout << "____";
}

void	rec(int n, int dept) {
	print_underBar(dept);
	cout << "\"재귀함수가 뭔가요?\"\n";
	if (n == dept) {
		print_underBar(dept);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	}
	else {
		print_underBar(dept);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		print_underBar(dept);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		print_underBar(dept);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		rec(n, dept+1);
	}
	print_underBar(dept);
	cout << "라고 답변하였지.\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	rec(n, 0);
	return 0;
}
