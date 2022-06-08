#include "소수_찾기.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void search(int& count, string num, string numbers, vector<bool> used, int depth, set<int>& num_set) {

	if (depth != 0) {

		int n = stoi(num);

		if (n > 1 && num_set.count(n) == 0 && isPrime(n) == true) {
			count++;
			num_set.insert(n);
		}
	}

	for (int i = 0; i < numbers.length(); i++) {
		if (used[i] == false) {
			used[i] = true;
			search(count, num + numbers[i], numbers, used, depth + 1, num_set);
			used[i] = false;
		}
	}
}

int solution(string numbers) {

	int answer = 0;
	set<int> num_set;

	search(answer, "", numbers, vector<bool>(numbers.length(), false), 0, num_set);

	return answer;
}

void 소수_찾기::service() {

    string n = "011";
    cout << solution(n) << endl;

}