#include "입국심사.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long cal(long long time, vector<int> times) {

	long long count = 0;

	for (int t : times) {
		if (time / t == 0)
			break;
		count += time / t;
	}

	return count;
}

long long solution(int n, vector<int> times) {

	long long answer = 0;
	
	sort(times.begin(), times.end());

	long long start = 1;
	long long end = (long long)times[times.size() - 1] * n;
	long long mid;

	answer = end;

	while (start <= end) {

		mid = (start + end) / 2;
	
		long long count = cal(mid, times);

		if (count >= n) {
			end = mid - 1;
			if (mid < answer)
				answer = mid;
		}
		else if (count < n) {
			start = mid + 1;
		}
	}

	return answer;
}

void 입국심사::service() {

	cout << solution(6, { 7, 10 }) << endl;
}