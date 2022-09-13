#include "�ܺ�_����.h"
#include <iostream>
#include <vector>

using namespace std;

�ܺ�_����_BEGIN

void checkPoints(vector<int>& dist, vector<int>& weak, int& n, int& answer) {

    for (int i = 0; i < weak.size(); i++) {

        int idx = i;
        int count = 0;

        for (int friendIdx = 0; friendIdx < dist.size(); friendIdx++) {

            int friendDist = dist[friendIdx];
            int nextIdx = idx;

            while (count < weak.size()) {

                int next = weak[nextIdx];

                if (next < weak[idx]) next += n;

                if (next - weak[idx] > friendDist)
                    break;

                count++;
                nextIdx = (nextIdx + 1) % weak.size();
            }

            if (count >= weak.size()) {
                if (friendIdx + 1 < answer) answer = friendIdx + 1;
                break;
            }

            idx = nextIdx;
        }

    }
}

void permutation(vector<int> dist, vector<int>& weak, int& n, int& answer, int depth) {

    if (depth == dist.size()) {
        checkPoints(dist, weak, n, answer);
        return;
    }

    for (int i = depth; i < dist.size(); i++) {
        swap(dist[i], dist[depth]);
        permutation(dist, weak, n, answer, depth + 1);
        swap(dist[i], dist[depth]);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    
    // �˻縦 ������ ��, ������ ��������� �����ϴ� ���� ����.
    // ģ���� ���Ե� �� �ִ� ��� ������ Ȯ���Ѵ�.
    // ģ���� �ִ� 8���̹Ƿ� ��� ������ ����ص� �����ٰ� �Ǵ��ߴ�.
    
    // Ž�� ������ ��� ������� ���������� ���
    // ������� ģ���� �ð� �������� ���� ��Ų��.
    // ���� ��ų���� ������ ����� ��ġ�� ���Խ�Ų��.

    int answer = 9;

    permutation(dist, weak, n, answer, 0);

    if (answer == 9)
        answer = -1;

    return answer;
}

void service() {

    int n = 12;
    vector<int> weak = { 1,5,6,10 };
    vector<int> dist = { 1,2,3,4 };

    cout << solution(n, weak, dist) << endl;
}

�ܺ�_����_END