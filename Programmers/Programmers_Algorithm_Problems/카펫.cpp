#include "ī��.h"
#include <iostream>
#include <vector>

using namespace std;

ī��_BEGIN

vector<int> solution(int brown, int yellow) {
    
    // ���� * 2 + ���� * 2 - 4 = brown����
    // (���� + ����) = (brown���� + 4) / 2
    // ���� x ���� = brown���� + yellow���� �� �����ϴ�
    // ���ο� ���θ� ã�´�.

    vector<int> answer;
    
    int row_col = (brown + 4) / 2;

    for (int row = 1; row <= (row_col / 2); row++) {

        int col = row_col - row;

        if (row * col == brown + yellow) {
            answer = { col, row };
            break;
        }
    }

    return answer;
}

void service() {

    int brown = 24;
    int yellow = 24;
    vector<int> ans = solution(brown, yellow);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

ī��_END