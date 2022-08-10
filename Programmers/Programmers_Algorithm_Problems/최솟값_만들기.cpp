#include "�ּڰ�_�����.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

�ּڰ�_�����_BEGIN

int solution(vector<int> A, vector<int> B)
{
    // A�� B�� �� ������ ���� �ּҰ� �Ǵ� ����,
    // �ϳ��� �迭������ ū �������
    // �ٸ� �迭������ ���� �������
    // ���ϴ� ��찡 �ּҰ� �ȴ�.

    int answer = 0;

    int size = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < size; i++)
        answer += (A[i] * B[size - 1 - i]);

    return answer;
}

void service() {

    vector<int> a = { 1,4,2 };
    vector<int> b = { 5,4,4 };

    cout << solution(a, b) << endl;
}

�ּڰ�_�����_END