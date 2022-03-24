/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10808_알파벳 개수.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:03:33 by minskim2          #+#    #+#             */
/*   Updated: 2022/03/24 08:38:09 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
using namespace std;

int	main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string word;
	int alp[26] = {};
	cin >> word;
	for (size_t i=0; i<word.size(); i++)
		alp[word[i]-'a']++;
	for (int i:alp)
		cout << i << " ";
	cout << '\n';
	return (0);
}
