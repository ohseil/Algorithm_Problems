#include "���¸���_�ѷ�_������.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

���¸���_�ѷ�_������_BEGIN

int solution(int n, vector<vector<int>> wires) {
    
    // ��� wire�� �߶󺻴�.
    // �ڸ� wire�� �� ���� ��带 ��������
    // �� �������� bfs�� ���� ����� ������ ���ؼ� ����Ѵ�.
    
    int answer = 100;
    
    unordered_map<int, vector<int>> edge_m;

    for (vector<int> wire : wires) {
        edge_m[wire[0]].emplace_back(wire[1]);
        edge_m[wire[1]].emplace_back(wire[0]);
    }

    for (vector<int> wire : wires) {

        int start1 = wire[0];
        int start2 = wire[1];

        queue<int> q;
        vector<bool> validation_v(n + 1, false);

        q.push(start1);
        validation_v[start1] = validation_v[start2] = true;

        int count1 = 1;
        int count2 = 1;

        while (q.empty() == false) {

            int data = q.front();
            q.pop();

            for (int next : edge_m[data]) {

                if (validation_v[next] == true)
                    continue;

                q.push(next);
                validation_v[next] = true;
                count1++;
            }
        }

        q = queue<int>();
        validation_v = vector<bool>(n + 1, false);

        q.push(start2);
        validation_v[start1] = validation_v[start2] = true;

        while (q.empty() == false) {

            int data = q.front();
            q.pop();

            for (int next : edge_m[data]) {

                if (validation_v[next] == true)
                    continue;

                q.push(next);
                validation_v[next] = true;
                count2++;
            }
        }

        if (answer > abs(count1 - count2))
            answer = abs(count1 - count2);
    }

    return answer;
}

void service() {

    int n = 9;
    vector<vector<int>> w = { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    cout << solution(n, w) << endl;
}

���¸���_�ѷ�_����_END