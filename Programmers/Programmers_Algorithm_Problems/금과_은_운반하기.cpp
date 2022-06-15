#include "�ݰ�_��_����ϱ�.h"
#include <iostream>
#include <vector>

using namespace std;

�ݰ�_��_����ϱ�_BEGIN

bool canCarry(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long time) {

    int amount_g = 0;
    int amount_s = 0;
    int amount_all = 0;

    for (int i = 0; i < g.size(); i++) {

        long long one_way_time = (long long)t[i];
        long long two_way_time = one_way_time * 2;

        long long count = (time < one_way_time) ? (0) : (1 + (time - one_way_time) / two_way_time);

        amount_g += min((long long)g[i], w[i] * count);
        amount_s += min((long long)s[i], w[i] * count);
        amount_all += min((long long)g[i] + s[i], w[i] * count);
    }

    return amount_g >= a && amount_s >= b && amount_all >= (a + b);
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    
    // �̺� Ž�� ���.
    // �ð� t�� �־����� ��, �ʿ��� �ݰ� ���� �縸ŭ �ű� �� �ִ��� Ȯ��.
    
    // �ݸ� �Ű��� �� �ʿ��� ���� ���� ä�� �� �ְ�
    // ���� �Ű��� �� �ʿ��� ���� ���� ä�� �� �ְ�
    // �ݰ� �� ��� ���� �Ű��� �� �ʿ��� �ݰ� ���� ������ �縸ŭ ä�� �� �ִٸ�
    // �ð� t���� �ʿ��� �ڿ��� ��� ä�� �� ������ �ǹ��Ѵ�.

    long long answer = 10e14 * 4;
    
    long long start = 1, end = 10e14 * 4, mid;

    while (start <= end) {

        mid = (start + end) / 2;

        if (canCarry(a, b, g, s, w, t, mid) == true) {

            if (mid < answer)
                answer = mid;

            end = mid - 1;
        }
        else {
            start = mid + 1;
        }

    }

    return answer;
}

void service() {

    int a = 90;
    int b = 500;
    vector<int> g = { 70,70,0 };
    vector<int> s = { 0,0,500 };
    vector<int> w = { 100,100,2 };
    vector<int> t = { 4,8,1 };

    cout << solution(a, b, g, s, w, t) << endl;
}

�ݰ�_��_����ϱ�_END