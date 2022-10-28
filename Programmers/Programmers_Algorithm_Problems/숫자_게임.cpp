#include "����_����.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

����_����_BEGIN

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
    
    // B���� ������ ���� �̾��� �� ���� ȿ�������� ������,
    // ���� ���� ���̷� �̱�� ���̴�.
    
    // A�� B�� ���ڵ��� ������������ �����Ѵ�.
    // A�� ���ڸ� ���� ���ں��� ���ʴ�� �̱� �� �ִ��� Ȯ���Ѵ�.
    // B���� Ȯ���� ���� ���������� ���� ���ں��� Ȯ���ϰ�
    // �ѹ� �Ϸ����� ���� ���� ���� ��ġ�� ����ؼ� ���� Ž�� �� �̿��Ѵ�.
    // A�� ���ں��� ū ���ڸ� B���� ã�Ҵٸ�,
    // B���� �� ���ں��� ���� ���ڵ��� �ʿ䰡 ����.
    // ���� Ȯ���ϴ� A�� ���ڰ� ������ Ȯ���ؾ� �� ���ڵ� �� ���� ���� �����̱� ������
    // �� ���ں��ٵ� ���� ���ڵ��� ������ � ���ڿ� �پ ���� �����̴�.

    // B�� ���ڸ� ��� Ž������ �� Ž���� �����Ѵ�.

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

����_����_END