#include "합승_택시_요금.h"
#include <iostream>
#include <vector>

using namespace std;

합승_택시_요금_BEGIN

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
    
    // floyd warshall 사용.
    // floyd warshall의 시간 복잡도는 n^3이다.
    // 지점의 개수는 최대 200이기 때문에 floyd warshall의 최대 시간 복잡도는 8000000(8백만)이다.
    // floyd warshall로 모든 지점부터 다른 모든 지점까지의 최단 경로를 구한 후
    // 각 지점 x마다 x->S + x->a + x->b 시간을 구해서 최소값을 구하면 답이다.

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

합승_택시_요금_END