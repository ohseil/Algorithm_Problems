#include "���_����.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

���_����_BEGIN

#define uset unordered_set

int solution(vector<int> info, vector<vector<int>> edges) {
    
    // ���� Ž�� + ��Ʈ��ŷ�� ����ߴ�.
    // �ϴ� ��Ʈ������ �����Ѵ�.
    // ��Ʈ ��忡 ��ġ�� ���¿��� ���� ���� 1�̰� ���� ���� 0�̴�.
    // ��Ʈ�� �ڽ� ����� �̵��� �����ϴ�.
    // ���Ŀ��� ���� ������� �湮�ߴ� ������ �ڽ� ������ ��� Ȯ���ؼ� �̵��� �� �ִ� ��� ������ �̵��Ѵ�.
    
    // �� ��, �̵� ������ ��带 ã�� �����
    // �̵� ��Ʈ���� ������ �湮�� ��带 hash set ���·� ������ ���� ����Ѵ�.
    // ����Ʈ�� �ִ� ������ ��� ��ȸ�ؼ� �ڽĵ��� ��� Ȯ���Ѵ�.
    // �� ��, �̹� ��� ����Ʈ�� ���� �� �ڽ� ���δ� �̵��� �� ����,
    // �̵����� �� ���� ���� ���� �� �̻��� �Ǵ� ��쵵 �̵��� �� ����.

    int answer = 0;
    
    map<int, vector<int>> tree;

    for (vector<int> edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }

    // <�湮��� ����Ʈ, <��, ����>>
    queue<pair<uset<int>, pair<int, int>>> q;

    q.push({ { 0 }, { 1, 0 } });

    while (q.empty() == false) {

        pair<uset<int>, pair<int, int>> data = q.front();
        q.pop();

        uset<int> nodeSet = data.first;
        int sheepCount = data.second.first;
        int wolfCount = data.second.second;

        if (sheepCount > answer)
            answer = sheepCount;

        for (int node : nodeSet) {
            for (int child : tree[node]) {
                
                if (nodeSet.count(child) > 0)
                    continue;
                if (info[child] == 1 && sheepCount <= wolfCount + 1)
                    continue;

                uset<int> nextSet = nodeSet;
                nextSet.insert(child);

                if (info[child] == 0)
                    q.push({ nextSet, { sheepCount + 1, wolfCount } });
                else
                    q.push({ nextSet, { sheepCount, wolfCount + 1 } });

            }
        }
    }

    return answer;
}

void service() {

    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> e = { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},
                                {9,11},{4,3},{6,5},{4,6},{8,9} };

    cout << solution(info, e) << endl;
}

���_����_END