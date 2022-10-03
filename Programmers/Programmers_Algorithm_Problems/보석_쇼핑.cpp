#include "����_����.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

����_����_BEGIN

#define hashMap unordered_map
#define hashSet unordered_set

vector<int> solution(vector<string> gems) {
    
    // ����� ������ ������ start, end�� ����ؼ� index�� �����Ѵ�.
    // ��� ������ ������ �� ������ end�� �̵���Ų��.
    // ��� ������ ������ �� �� �ִٸ�,
    // start�� �̵���Ű�鼭 ������ �ϳ��� ����.
    // �ٽ� ��� ������ ������ �� �� ���ٸ� �� �ٽ� end�� �̵���Ų��.
    // �̷������� ������ �ݺ��ϸ鼭
    // ��� ������ ������ �� �� ���� ������ ������ ���ؼ� �ּ� ������ ã�´�.

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

����_����_END