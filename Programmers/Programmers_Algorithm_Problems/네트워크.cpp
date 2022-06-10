#include "��Ʈ��ũ.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

��Ʈ��ũ_BEGIN

int solution(int n, vector<vector<int>> computers) {
    
    // bfs�� ����ؼ� ��Ʈ��ũ Ž��

    int answer = 0;
    
    vector<bool> visited(n, false);

    for (int com = 0; com < n; com++) {

        if (visited[com] == true)
            continue;

        queue<int> q;
        q.push(com);

        while (q.empty() == false) {

            int data = q.front();
            q.pop();

            for (int next = 0; next < n; next++) {
                
                if (next == data)
                    continue;
                if (computers[data][next] == 0)
                    continue;
                if (visited[next] == true)
                    continue;

                q.push(next);
                visited[next] = true;
            }
        }

        answer++;
    }

    return answer;
}

void service() {

    int n = 3;
    vector<vector<int>> c = { {1,1,0},{1,1,0},{0,0,1} };
    cout << solution(n, c) << endl;
}

��Ʈ��ũ_END