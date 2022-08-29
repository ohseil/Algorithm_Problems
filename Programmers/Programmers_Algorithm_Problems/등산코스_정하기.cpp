#include "����ڽ�_���ϱ�.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

����ڽ�_���ϱ�_BEGIN

#define LIMIT_INTENSITY 10000001
#define umap unordered_map

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    // BFS + ��Ʈ��ŷ
    // �պ��̶�� �ϴ��� �� ��Ʈ�� ���ϸ� �ȴ�.
    // �ּ� intensity�� ��Ʈ�� ã���� ���� ��Ʈ�� ���ƿ��� �Ǳ� ������.
    // ��� ���Ա��� ���������� �ؼ� bfs�� �����Ѵ�.
    // �� ���Ա����� bfs�� �����ϸ� �ð� �ʰ��� �߻��Ѵ�.
    // � ���Ա����� �����ϴ��� �ּ� intensity ��Ʈ�� ã���� �Ǳ� ������
    // ��� ���Ա����� ���ÿ� bfs�� �����ص� �ȴ�.
    
    // ���� ��θ� ���� ���� ���� ��,
    // Ȯ���� �ʿ��� ������ 2������ �ִ�.
    // 1. ���Ա��� �ƴ� ���, 2. ������ ��ġ�� intensity���� ���� ��Ʈ�� intensity�� ���� ���
    // �� ��ġ������ intensity�� ������ �迭�� ����Ѵ�.
    // ���Ա��� intensity�� 0�̰� �������� limit intensity ������ �����Ѵ�.
    // ���� ��ġ�� intensity���� ���� ��Ʈ�� intensity�� ���� ��쿡�� �����ϰ� �Ǹ�
    // 2���� ���� ��� ������ �� �ִ�.

    // ���� ������ �̵��� ���� ���츮�� ����.
    // ���츮�� ��� Ž���� �����Ѵ�.
    
    // bfs �Ŀ� intensity �迭�� ��� Ȯ���ؼ� ���츮�� intensity�� ���Ѵ�.

    vector<int> answer = { n, LIMIT_INTENSITY };

    umap<int, umap<int, int>> edgeMap;
    vector<int> gateMap(n + 1, 0);
    vector<int> summitMap(n + 1, 0);

    for (vector<int> path : paths) {
        edgeMap[path[0]][path[1]] = path[2];
        edgeMap[path[1]][path[0]] = path[2];
    }

    for (int gate : gates)
        gateMap[gate] = 1;
    for (int summit : summits)
        summitMap[summit] = 1;

    vector<int> intensities(n + 1, LIMIT_INTENSITY);

    queue<pair<int, int>> q;

    for (int gate : gates) {
        q.push({ gate, 0 });
        intensities[gate] = 0;
    }

    while (q.empty() == false) {

        int node = q.front().first;
        int intensity = q.front().second;
        q.pop();

        if (summitMap[node] == 1)
            continue;

        for (auto nextInform : edgeMap[node]) {

            int next = nextInform.first;
            int cost = nextInform.second;

            int nIntensity = max(intensity, cost);

            if (intensities[next] <= nIntensity)
                continue;

            q.push({ next, nIntensity });
            intensities[next] = nIntensity;
        }
    }

    for (int node = 1; node <= n; node++) {

        if (summitMap[node] == 0)
            continue;

        if (intensities[node] < answer[1]) {
            answer = { node, intensities[node]};
        }
        else if (intensities[node] == answer[1]) {
            if (node < answer[0])
                answer = { node, intensities[node]};
        }
    }

    return answer;
}

void service() {

    int n = 7;
    vector<vector<int>> p = { {1,4,4},{1,6,1},{1,7,3},{2,5,2},
                              {3,7,4},{5,6,6} };
    vector<int> g = { 1 };
    vector<int> s = { 2,3,4 };

    vector<int> ans = solution(n, p, g, s);
    cout << ans[0] << " " << ans[1] << endl;
}

����ڽ�_���ϱ�_END