#include "스타_수열.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

스타_수열_BEGIN

int solution(std::vector<int> a) {
    
    // a를 스타 수열로 만드는 방법은 원소를 지우는 방법 밖에 없다.
    // a에 포함 된 각 숫자의 개수와 해당 숫자들의 위치를 따로 저장한다.
    // 각 숫자들은 스타 수열의 부분 집합의 원소가 될 수 있다.
    // 숫자의 개수를 기준으로 내림차순 정렬을 한 후
    // 가장 많은 개수의 숫자부터 해당 숫자를 기준으로 스타 수열을 만들 수 있는지 확인한다.

    // 확인하는 방법은 숫자들의 index를 이용해서 확인한다.
    // 위치를 따로 저장하는 과정에서 자연스럽게 index는 오름차순 정렬된다.
    // 현재 확인하는 숫자를 num이라고 할때,
    // 각 위치마다 해당 위치의 바로 앞과 뒤의 숫자가 num과 다른 숫자인지 확인한다.
    // 다른 숫자가 있는 경우에는 이 위치의 숫자는 스타 수열에 포함될 수 있다는 것을 의미한다.
    // 이때 num과 다른 숫자의 index를 계속 갱신한다. 최신 index를 가지고 있는다.
    // 이유는 이전 위치의 num과 세트가 된 숫자는 이후의 num과 세트가 될 수 없기 때문에
    // 이것을 확인하기 위해 num과 세트가 된 숫자의 최신 index의 정보를 가지고 있는다.

    if (a.size() < 2)
        return 0;

    int answer = 0;
    
    map<int, int> count_m;
    map<int, vector<int>> idx_m;

    for (int i = 0; i < a.size(); i++) {
        count_m[a[i]]++;
        idx_m[a[i]].push_back(i);
    }

    map<int, int> sorted_m;

    for (auto count : count_m)
        sorted_m[-count.second] = count.first;

    for (auto data : sorted_m) {

        int num = data.second;
        vector<int> idx_v = idx_m[num];

        int count = 0;
        int cur_idx = -1;

        for (int idx : idx_v) {

            if (idx == 0) {
                
                if (a[idx + 1] != num) {
                    count += 2;
                    cur_idx = idx + 1;
                }
            }
            else {

                if (idx - 1 > cur_idx && a[idx - 1] != num) {
                    count += 2;
                    cur_idx = idx - 1;
                }
                else if (idx + 1 < a.size() && a[idx + 1] != num) {
                    count += 2;
                    cur_idx = idx + 1;
                }
            }
        }

        if (answer < count)
            answer = count;
    }

    return answer;
}

void service() {

    vector<int> a = { 0,3,3,0,7,2,0,2,2,0 };
    cout << solution(a) << endl;
}

스타_수열_END