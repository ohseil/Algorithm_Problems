#include "�ս�_�ý�_���.h"
#include <iostream>
#include <vector>

using namespace std;

�ս�_�ý�_���_BEGIN

#define MAX_TOTAL_FARE 20000000

void floydWarshall(int (*edgeMap)[201], int n) {
    
    for (int mid = 1; mid <= n; mid++)
        for (int start = 1; start <= n; start++)
            for (int end = 1; end <= n; end++)
                if (edgeMap[start][end] > edgeMap[start][mid] + edgeMap[mid][end]) {
                    edgeMap[start][end] = edgeMap[start][mid] + edgeMap[mid][end];
                }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    // floyd warshall ���.
    // floyd warshall�� �ð� ���⵵�� n^3�̴�.
    // ������ ������ �ִ� 200�̱� ������ floyd warshall�� �ִ� �ð� ���⵵�� 8000000(8�鸸)�̴�.
    // floyd warshall�� ��� �������� �ٸ� ��� ���������� �ִ� ��θ� ���� ��
    // �� ���� x���� x->S + x->a + x->b �ð��� ���ؼ� �ּҰ��� ���ϸ� ���̴�.

    int answer = MAX_TOTAL_FARE;
    
    int edgeMap[201][201];
    
    for (int start = 1; start <= n; start++)
        for (int end = 1; end <= n; end++)
            if (start == end)
                edgeMap[start][end] = 0;
            else
                edgeMap[start][end] = MAX_TOTAL_FARE;

    for (vector<int> fare : fares)
        edgeMap[fare[0]][fare[1]] = edgeMap[fare[1]][fare[0]] = fare[2];

    floydWarshall(edgeMap, n);

    for (int node = 1; node <= n; node++)
        if (edgeMap[node][s] + edgeMap[node][a] + edgeMap[node][b] < answer)
            answer = edgeMap[node][s] + edgeMap[node][a] + edgeMap[node][b];

    return answer;
}

void service() {

    int n = 7;
    int s = 3;
    int a = 4;
    int b = 1;
    vector<vector<int>> fares = { {5,7,9},{4,6,4},{3,6,1},{3,2,3},{2,1,6} };

    cout << solution(n, s, a, b, fares) << endl;
}

�ս�_�ý�_���_END