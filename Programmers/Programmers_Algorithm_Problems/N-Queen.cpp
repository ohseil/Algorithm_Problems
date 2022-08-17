#include "N-Queen.h"
#include <iostream>
#include <queue>

using namespace std;

NQueen_BEGIN

int solution(int n) {
    
    // 1����� n����� �� ���� ���� �� �ִ� ��츦 ��� Ž���Ѵ�.
    // �� ��, ��Ʈ��ŷ ����� ����Ѵ�.
    // ���� �� ���� ���� ���� �࿡�� ���Ҵ� ����� ���� ���� ����
    // ���� �࿡�� ���Ҵ� ���� �� �ϳ��� �������� ��ġ�� �밢���� ��ġ�ϴ� ����.

    if (n == 1)
        return 1;

    int answer = 0;
    
    queue<vector<pair<int, int>>> q;

    for (int pos = 0; pos < n; pos++) {
        vector<pair<int, int>> v(n, { 0, 0 });
        v[pos].first = 1;
        q.push(v);
    }

    for (int count = 1; count < n; count++) {

        int qsize = q.size();

        for (int qi = 0; qi < qsize; qi++) {

            vector<pair<int, int>> data = q.front();
            q.pop();

            for (int pos = 0; pos < n; pos++) {

                if (data[pos].first == 1)
                    continue;

                bool canPos = true;

                for (int before = 0; before < n; before++) {

                    if (data[before].first == 0)
                        continue;

                    if (before == pos)
                        continue;

                    if (abs(pos - before) == abs(count - data[before].second)) {
                        canPos = false;
                        break;
                    }

                }
                
                if (canPos == true) {
                    vector<pair<int, int>> next = data;
                    next[pos] = { 1, count };
                    q.push(next);
                }
            }

        }
    }

    answer = q.size();

    return answer;
}

void service() {

    int n = 4;
    cout << solution(n) << endl;
}

NQueen_End