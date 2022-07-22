#include "��_�̵�_�ùķ��̼�.h"
#include <iostream>
#include <vector>

using namespace std;

��_�̵�_�ùķ��̼�_BEGIN

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    
    // ���� ������ �������� ������ query�� �����Ͽ� ����Ѵ�.
    // ������ ��ġ�� ������ ������ ���簢�� �����̴�.
    
    // ���� �̵� ������ ����ϴ� ��츦 ���� ���,
    // ���� ������ ���� �پ����� ���� ����
    // ���� �پ��ִ� ��� 2������ ������ ������ �� �ִ�.

    // ���� �پ����� ���� ��쿡��
    // ������ �̵� �Ÿ���ŭ ���������� �̵��� ������ �ȴ�.
    // ������ �̶� ������ ���� ����� ��쿡�� �� ������ �ذ��� �� ���� ������ �Ǵ��Ѵ�.

    // ���� �پ��ִ� ��쿡��
    // ���� �ݴ�Ǵ� ���̳� ������ �̵� �Ÿ���ŭ ���� ������ �ȴ�.
    // ���� �پ������� �̵� �Ÿ����� ���� ������ ������ ������ �̵��� �� �ֱ� �����̴�.

    long long answer = -1;

    long long x1, y1, x2, y2;

    x1 = x2 = x;
    y1 = y2 = y;


    for (int i = queries.size() - 1; i >= 0; i--) {

        int movement = queries[i][0];
        int value = queries[i][1];

        if (movement == 0) {
            // ���� �̵�
            if (y1 == 0) {
                // ���� ���� ���
                y2 = (y2 + value >= m) ? (m - 1) : y2 + value;
            }
            else {
                
                if (y1 + value >= m) {
                    answer = 0;
                    return answer;
                }

                y1 += value;
                y2 = (y2 + value >= m) ? (m - 1) : y2 + value;

            }
        }
        else if (movement == 1) {
            // ������ �̵�
            if (y2 == m - 1) {
                // ���� ���� ���
                y1 = (y1 - value < 0) ? 0 : y1 - value;
            }
            else {

                if (y2 - value < 0) {
                    answer = 0;
                    return answer;
                }

                y2 -= value;
                y1 = (y1 - value < 0) ? 0 : y1 - value;

            }
        }
        else if (movement == 2) {
            // ���� �̵�
            if (x1 == 0) {
                // ���� ���� ���
                x2 = (x2 + value >= n) ? (n - 1) : x2 + value;
            }
            else {

                if (x1 + value >= n) {
                    answer = 0;
                    return answer;
                }

                x1 += value;
                x2 = (x2 + value >= n) ? (n - 1) : x2 + value;

            }
        }
        else if (movement == 3) {
            // �Ʒ��� �̵�
            if (x2 == n - 1) {
                // ���� ���� ���
                x1 = (x1 - value < 0) ? 0 : x1 - value;
            }
            else {

                if (x2 - value < 0) {
                    answer = 0;
                    return answer;
                }

                x2 -= value;
                x1 = (x1 - value < 0) ? 0 : x1 - value;

            }
        }
    }
    
    answer = (long long)(x2 - x1 + 1) * (y2 - y1 + 1);

    return answer;
}

void service() {

    int n = 2;
    int m = 2;
    int x = 0;
    int y = 0;
    vector<vector<int>> q = { {2,1},{0,1},{1,1},{0,1},{2,1} };
    cout << solution(n, m, x, y, q) << endl;
}

��_�̵�_�ùķ��̼�_END