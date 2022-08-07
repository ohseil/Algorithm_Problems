#include "��_����_���.h"
#include <iostream>
#include <vector>

using namespace std;

��_����_���_BEGIN

vector<int> solution(int n, long long k) {
    
    // ��Ģ�� ã�Ƽ� �ذ��ߴ�.

    // ��Ģ�� ã�ƺ���,
    // ó�� ���ڸ��� �����̴� ��츦 ���� 1�����̰�
    // �� �ڸ��� �����̴� ��츦 ���� 2�����̴�.
    // �׸��� �� �ڸ��� �����̴� ��츦 ���� 6�����̴�.
    // n���� �ڸ��� ���ڵ��� ��� ������ �������� n! �����̴�.
    // �׷� n��° �ڸ��� �����Ǿ� �ִ� ��츦 ������ ����,
    // �� ���� �ڸ����� ��� ������ ������ (n-1)! �����̴�.
    // (n-1)! ������ ���� �Ŀ� n�ڸ� ���� ���� ���ڷ� �ٲ�ٴ� ���̴�.
    // �� ��Ģ�� �����ؼ� ó���� k�� (n-1)!���� ���� ���� index�� �ؼ�
    // ���ĵǾ� �ִ� �迭�� ������ ��ġ�� ã�´�.
    // �� ��, ã�� ���ڴ� �迭���� �����Ѵ�.
    // k�� ���� k %= (n-1)!�� �ȴ�.
    // �� ������ ���ؼ� ù��° �ڸ��� ���ں��� ������ �ڸ��� ���ڱ��� ������ ������.
    // ���߿� k�� 0�� �Ǵ� ���� �迭�� �����ִ� ���ڸ� �״�� �����ϸ� �ȴ�.

    vector<int> answer;
    vector<int> numV;
    long long factorial = 1;
    int facLastNum = n - 1;

    for (int i = 1; i <= n; i++)
        numV.push_back(i);

    for (int i = 2; i <= facLastNum; i++)
        factorial *= i;

    k--;

    while (k > 0) {

        int quotient = k / factorial;
        
        answer.push_back(numV[quotient]);

        numV.erase(numV.begin() + quotient);
    
        k %= factorial;
        factorial /= facLastNum;
        facLastNum--;
    }

    if (numV.empty() == false)
        for (int num : numV)
            answer.push_back(num);

    return answer;
}

void service() {

    int n = 3;
    int k = 5;

    vector<int> ans = solution(n, k);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

��_����_���_END