#include "ķ��.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ķ��_BEGIN

int solution(int n, vector<vector<int>> data) {
    
    // ���� ��ǥ�� ������������ �����Ѵ�.
    // �׷��� x��ǥ�� �������� �����ϰ� �ȴ�.

    // ù ��ǥ���� ���ʴ�� 2���� ���⸦ �����ؼ� Ȯ���Ѵ�.
    // Ȯ�� ������ �ʺ� 0�� �ƴϾ�� �ϰ�,
    // ���簢�� �ȿ� ���Ⱑ ����� �Ѵ�.

    // ���簢�� �ȿ� ���Ⱑ ������ Ȯ���ϴ� ������
    // ���õ� 2���� ���Ⱑ i,j��� ���� ��
    // i + 1 ~ j - 1 ���� Ȯ���Ѵ�.
    // ������ x�� �������� ���ĵǾ� �ֱ� ������
    // ���簢���� ����� ���ٸ�, i���� ������ ������ �������
    // i�� ���� x�࿡ �ְų� i���� ���� x�࿡ �ֱ� ������
    // i,j�� ������� ���簢�� �ȿ� ���� �� ����.
    // j���� ū ����鵵 �������� ������ Ȯ���� �ʿ䰡 ����.

    int answer = 0;
    
    int len = data.size();

    sort(data.begin(), data.end());

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {

            int x1 = data[i][0], y1 = data[i][1];
            int x2 = data[j][0], y2 = data[j][1];

            // ���簢�� �ʺ� 0
            if (x1 == x2 || y1 == y2)
                continue;

            int min_x, max_x, min_y, max_y;

            min_x = min(x1, x2);
            max_x = max(x1, x2);
            min_y = min(y1, y2);
            max_y = max(y1, y2);

            bool isContained = false;

            for (int k = i + 1; k < j; k++) {

                if (min_x < data[k][0] && data[k][0] < max_x
                    && min_y < data[k][1] && data[k][1] < max_y) {
                    isContained = true;
                    break;
                }
            }

            if (isContained == false)
                answer++;
        }
    }

    return answer;
}

void service() {

    int n = 4;
    vector<vector<int>> d = { {0,0},{1,1},{0,2},{2,0} };
    cout << solution(n, d) << endl;
}

ķ��_END