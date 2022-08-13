#include "�ϳ�����_ž.h"
#include <iostream>
#include <vector>

using namespace std;

�ϳ�����_ž_BEGIN

// n���� ������ from���� to���� �ű�� �Լ�
void hanoi(int n, int from, int to, vector<vector<int>>& ans) {

    if (n == 0) {
        return;
    }

    int restCol = 1;

    for (int col = 1; col <= 3; col++)
        if (col != from && col != to) {
            restCol = col;
            break;
        }

    hanoi(n - 1, from, restCol, ans);
    ans.emplace_back(vector<int>({ from, to }));
    hanoi(n - 1, restCol, to, ans);
    
}

vector<vector<int>> solution(int n) {
    
    // n��° ������ ���3���� �ű�� ���ؼ���
    // n-1���� ������ ���2�� �ű� �� n��° ������ �ű��
    // �ٽ� n-1���� ������ ���3���� �Űܾ� �Ѵ�.

    // �� �������� n-1��° ������ �� ��� 2�� �ű�� ���ؼ�
    // n-2���� ������ ���3���� �ű� �� n-1��° ������ �ű��
    // �ٽ� n-2���� ������ ���2�� �Űܾ� �Ѵ�.

    // �̷� ������ ��������� ����ǵ��� �����Ѵٸ�,
    // hanoi(n, from, to) : n���� ������ from���� to���� �ű�� �Լ�
    // �� �����Ѵٸ�,
    // hanoi(n, from, to) ���� ���������� from�� to�� �ƴ� ����� x��� �� ��,
    // 1. hanoi(n - 1, from, x)
    // 2. n��° ���� from -> x �̵�
    // 3. hanoi(n - 1, x, to)
    // �������� ������ �� �ִ�.

    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, answer);

    return answer;
}

void service() {

    int n = 2;

    vector<vector<int>> ans = solution(n);
    for (auto a : ans)
        cout << a[0] << "->" << a[1] << " ";
    cout << endl;
}

�ϳ�����_ž_END