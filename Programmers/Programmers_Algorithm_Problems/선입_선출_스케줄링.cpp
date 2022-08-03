#include "선입_선출_스케줄링.h"
#include <iostream>
#include <vector>

using namespace std;

선입_선출_스케줄링_BEGIN

long long getHandleCount(vector<int>& cores, int t) {

    long long count = 0;

    for (int core : cores)
        count += ((long long)t / core);

    return count;
}

int solution(int n, vector<int> cores) {
    
    // 이분 탐색 사용.
    
    // 시간 t가 주어졌을 때,
    // t시간 동안 처리할 수 있는 작업 수를 구한다.
    // 처리 가능한 작업 수가 n이랑 가장 가까운 시간을 구한다.

    // 가장 적합한 시간 rt를 구했다면,
    // rt 시간에 작업을 맡게 된 core 리스트를 구한다.
    // 가장 적합한 시간을 구했기 때문에 해당 시간에 맡게 된 core들 중 마지막 순서가 있다.
    // rt 시간에 처리되는 작업들을 계산하면서 n에서 뺀다.
    // 하지만 rt 시간에 맡게된 코어들은 맡게 된 작업은 빼고 계산한다.
    // 이유는 모든 계산 후에 남은 n의 개수로 rt 시간에 맡은 코어들 중
    // 마지막 맡게되는 코어의 순서를 알기 위함이다.

    if (n <= cores.size())
        return n;

    int answer = 0;
    
    int maxTime = cores[0];

    for (int coreTime : cores)
        if (coreTime > maxTime)
            maxTime = coreTime;

    int start = 1, end = maxTime * (n / cores.size()), mid;

    n -= cores.size();

    int smallestTime = end;

    while (start <= end) {
        
        mid = (start + end) / 2;

        if (getHandleCount(cores, mid) >= n) {
            
            if (mid < smallestTime)
                smallestTime = mid;

            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    vector<int> v;

    for (int i = 0; i < cores.size(); i++) {

        if (smallestTime % cores[i] == 0) {
            n -= (smallestTime / cores[i] - 1);
            v.emplace_back(i + 1);
        }
        else {
            n -= (smallestTime / cores[i]);
        }
    }

    answer = v[n - 1];

    return answer;
}

void service() {

    int n = 6;
    vector<int> cores = { 1,2,3 };

    cout << solution(n, cores) << endl;
}

선입_선출_스케줄링_END