#include "다단계_칫솔_판매.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

다단계_칫솔_판매_BEGIN

void makeTree(vector<string>& enroll, vector<string>& referral, map<string, string>& reverseTree) {
    for (int i = 0; i < enroll.size(); i++)
        reverseTree[enroll[i]] = referral[i];
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    // 판매자들은 트리 구조로 되어있다.
    // 하지만 이익 계산 과정을 봤을 때, child -> parent 방향의 단방향으로만 움직인다.
    // 단방향 edge 정보들만 저장한다.

    // 판매 정보 순서대로 판매자를 시작점으로 저장한 edge 정보를 참고하여 탐색을 시작한다.
    // 탐색하면서 계산되는 이익을 각 판매자의 총 이익 정보를 관리하는 자료구조에 저장한다.
    // 탐색 종료 조건은 계산된 이익이 0원이거나 다음 edge가 없는 경우다.

    vector<int> answer;
    
    map<string, string> reverseTree;
    map<string, int> profits;

    makeTree(enroll, referral, reverseTree);

    for (int i = 0; i < seller.size(); i++) {

        string name = seller[i];
        int profit = amount[i] * 100;
        int commission = profit / 10;

        while (true) {

            profits[name] += profit - commission;

            if (commission == 0 || reverseTree.count(name) == 0)
                break;

            name = reverseTree[name];
            profit = commission;
            commission = profit / 10;
        }
    }

    for (string person : enroll)
        answer.push_back(profits[person]);

    return answer;
}

void service() {

    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> seller = { "young", "john", "tod", "emily", "mary" };
    vector<int> amount = { 12, 4, 2, 5, 10 };

    vector<int> ans = solution(enroll, referral, seller, amount);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

}

다단계_칫솔_판매_END