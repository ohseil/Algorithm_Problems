#include "이중우선순위큐.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

이중우선순위큐_BEGIN

vector<int> solution(vector<string> operations) {
	
	vector<int> answer = {0, 0};
	
	map<int, int> m;

	for (string operation : operations) {

		char instruction = operation[0];
		int num = stoi(operation.substr(operation.find(" ") + 1));

		if (instruction == 'I') {
			m[num]++;
		}
		else if (instruction == 'D') {

			if (m.empty() == true)
				continue;

			map<int, int>::iterator it;

			if (num == 1)
				it = --m.end();
			else
				it = m.begin();

			if (it->second - 1 == 0)
				m.erase(it);
		}
	}

	if (m.empty() == false) {
		answer[0] = (--m.end())->first;
		answer[1] = m.begin()->first;
	}

	return answer;
}

void service() {

	vector<string> op = { "I 7","I 5","I -5","D -1" };
	vector<int> ans = solution(op);
	for (auto a : ans)
		cout << a << " ";
	cout << endl;

}

이중우선순위큐_END