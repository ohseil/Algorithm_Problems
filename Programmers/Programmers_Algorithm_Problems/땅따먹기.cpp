#include "�����Ա�.h"
#include <iostream>
#include <vector>

using namespace std;

�����Ա�_BEGIN

int solution(vector<vector<int>> land)
{
    // dp + greedy�� ����.
    // �� ���� ���� ��, ���� �࿡�� �� �� �ִ� 3���� ��� �� ���� ū ������ �����Ѵ�.

    int answer = 0;
    int size = land.size();

    for (int i = 1; i < size; i++) {

        for (int d = 0; d < 4; d++) {
            land[i][d] += max(land[i - 1][(d + 1) % 4], max(land[i - 1][(d + 2) % 4], land[i - 1][(d + 3) % 4]));
        }
    }

    answer = max(land[size - 1][0], max(land[size - 1][1], max(land[size - 1][2], land[size - 1][3])));

    return answer;
}

void service() {

    vector<vector<int>> land = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };
    cout << solution(land) << endl;
}

�����Ա�_END