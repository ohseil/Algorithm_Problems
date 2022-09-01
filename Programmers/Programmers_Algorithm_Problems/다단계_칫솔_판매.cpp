#include "�ٴܰ�_ĩ��_�Ǹ�.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

�ٴܰ�_ĩ��_�Ǹ�_BEGIN

void makeTree(vector<string>& enroll, vector<string>& referral, map<string, string>& reverseTree) {
    for (int i = 0; i < enroll.size(); i++)
        reverseTree[enroll[i]] = referral[i];
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    // �Ǹ��ڵ��� Ʈ�� ������ �Ǿ��ִ�.
    // ������ ���� ��� ������ ���� ��, child -> parent ������ �ܹ������θ� �����δ�.
    // �ܹ��� edge �����鸸 �����Ѵ�.

    // �Ǹ� ���� ������� �Ǹ��ڸ� ���������� ������ edge ������ �����Ͽ� Ž���� �����Ѵ�.
    // Ž���ϸ鼭 ���Ǵ� ������ �� �Ǹ����� �� ���� ������ �����ϴ� �ڷᱸ���� �����Ѵ�.
    // Ž�� ���� ������ ���� ������ 0���̰ų� ���� edge�� ���� ����.

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

�ٴܰ�_ĩ��_�Ǹ�_END