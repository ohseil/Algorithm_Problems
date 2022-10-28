#include "숫자_게임.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

숫자_게임_BEGIN

void sortTeammateNums(vector<int>& aTeamNums, vector<int>& bTeamNums) {
    sort(aTeamNums.begin(), aTeamNums.end());
    sort(bTeamNums.begin(), bTeamNums.end());
}

bool isBiggerNumInBTeam(int aNum, vector<int>& bTeamNums, int& startIdx) {

    for (int i = startIdx; i < bTeamNums.size(); i++) {

        startIdx = i + 1;

        int bNum = bTeamNums[i];

        if (aNum < bNum)
            return true;
    }

    return false;
}

int solution(vector<int> A, vector<int> B) {
    
    // B에서 임의의 수를 뽑았을 때 가장 효율적으로 쓰려면,
    // 가장 적은 차이로 이기는 것이다.
    
    // A와 B의 숫자들을 오름차순으로 정렬한다.
    // A의 숫자를 작은 숫자부터 차례대로 이길 수 있는지 확인한다.
    // B에서 확인할 때는 마찬가지로 작은 숫자부터 확인하고
    // 한번 완료했을 때는 다음 시작 위치를 기억해서 다음 탐색 때 이용한다.
    // A의 숫자보다 큰 숫자를 B에서 찾았다면,
    // B에서 이 숫자보다 작은 숫자들은 필요가 없다.
    // 현재 확인하는 A의 숫자가 앞으로 확인해야 할 숫자들 중 가장 작은 숫자이기 때문에
    // 이 숫자보다도 작은 숫자들은 앞으로 어떤 숫자와 붙어도 지기 때문이다.

    // B의 숫자를 모두 탐색했을 때 탐색을 종료한다.

    int answer = 0;
    
    int searchStartIdx = 0;

    sortTeammateNums(A, B);

    for (int aNum : A) {

        if (searchStartIdx >= B.size())
            break;

        if (isBiggerNumInBTeam(aNum, B, searchStartIdx) == true)
            answer++;
    }

    return answer;
}

void service() {

    vector<int> A = { 5,1,3,7 };
    vector<int> B = { 2,2,6,8 };

    cout << solution(A, B) << endl;
}

숫자_게임_END