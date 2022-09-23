#include "n����_����.h"
#include <iostream>
#include <string>

using namespace std;

n����_����_BEGIN

char baseNums[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string getNumByBasenum(int num, int n) {

    string result = "";

    do {

        result = baseNums[num % n] + result;
        num /= n;

    } while (num != 0);

    return result;
}

string solution(int n, int t, int m, int p) {
    
    // ���ӿ��� ���Ǵ� ���ڸ� num�̶�� �ϰ�, ���� turn�̶�� ����.
    // num = 0, turn = 0���� �ʱ�ȭ�� �ϰ� �� ����� ���� p--�� �� ���·� ����ߴ�.
    // num�� �ϳ��� ������Ű�鼭 ���ʴ�� Ȯ���ߴ�.
    // num�� n������ string���� �ٲ� ��,
    // string�� ���̸�ŭ ���ڸ� Ȯ���ϸ鼭 turn�� ����ߴ�.
    
    // n�������� �ٲٴ� ����� �⺻���� n���� ��� ����� ����ߴ�.
    // �׸��� 10���� �̻��� ���ڰ� ���� ����� ���ؼ� �迭�� ���� ����ߴ�.
    // �迭�� �ϳ� ����� n�� index�� �� ��ġ�� ���� n�������� �� �ڸ����� �Ѿ�� ���ڷ� �����ߴ�.
    // 10 ~ 16������ A ~ F�� �����ߴ�.
    
    // ���� turn�� player�� ������ Ȯ���ϴ� ����� (turn%m == p)�̸� player�� ���̴�.

    string answer = "";
    
    int num = 0;
    int turn = 0;
    p--;

    while (answer.length() < t) {

        string str = getNumByBasenum(num, n);

        for (int i = 0; i < str.length(); i++) {

            if (turn % m == p) {

                answer.push_back(str[i]);

                if (answer.length() == t)
                    break;
            }

            turn++;
        }

        num++;
    }

    return answer;
}

void service() {

    int n = 2;
    int t = 4;
    int m = 2;
    int p = 1;

    cout << solution(n, t, m, p) << endl;
}

n����_����_END