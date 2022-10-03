#include "보석_쇼핑.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

보석_쇼핑_BEGIN

#define hashMap unordered_map
#define hashSet unordered_set

vector<int> solution(vector<string> gems) {
    
    // 사려는 보석의 범위를 start, end를 사용해서 index를 저장한다.
    // 모든 종류의 보석을 살 때까지 end를 이동시킨다.
    // 모든 종류의 보석을 살 수 있다면,
    // start를 이동시키면서 보석을 하나씩 뺀다.
    // 다시 모든 종류의 보석을 살 수 없다면 또 다시 end를 이동시킨다.
    // 이런식으로 끝까지 반복하면서
    // 모든 종류의 보석을 살 수 있을 때마다 범위를 비교해서 최소 범위를 찾는다.

    vector<int> answer(2, 0);
    int answerSize = gems.size();
    
    hashSet<string> gemList;
    hashMap<string, int> gemCounts;

    int start = 0, end = -1;
    int size = 0;

    for (string gem : gems)
        gemList.insert(gem);

    do {

        if (gemCounts.size() < gemList.size()) {
            end++;
            gemCounts[gems[end]]++;
        }
        else {
            gemCounts[gems[start]]--;
            if (gemCounts[gems[start]] == 0)
                gemCounts.erase(gems[start]);
            start++;
        }

        if (gemCounts.size() == gemList.size()) {
            if (end - start < answerSize) {
                answerSize = end - start;
                answer = { start + 1, end + 1 };
            }
        }

    } while ((end == gems.size() - 1 && gemCounts.size() < gemList.size()) == false);

    
    return answer;
}

void service() {

    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    
    vector<int> ans = solution(gems);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

보석_쇼핑_END