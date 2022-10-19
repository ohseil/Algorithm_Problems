#include "����_���_����Ŭ.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

����_���_����Ŭ_BEGIN

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int maxR, maxC;

vector<vector<vector<int>>> validations;

class Node {
public:
    int r;
    int c;
    int fromDirection;
    Node(int r, int c, int d) : r(r), c(c), fromDirection(d) {}
};

int findNextDirection(int fromDirection, char flag) {
    if (flag == 'S') return fromDirection;
    else if (flag == 'L') {
        if (fromDirection == 0) return 3;
        if (fromDirection == 1) return 2;
        if (fromDirection == 2) return 0;
        if (fromDirection == 3) return 1;
    }
    else if (flag == 'R') {
        if (fromDirection == 0) return 2;
        if (fromDirection == 1) return 3;
        if (fromDirection == 2) return 1;
        if (fromDirection == 3) return 0;
    }
}

int moveR(int r, int direction) {
    int nr = r + dr[direction];
    if (nr < 0) return (nr + maxR);
    return nr % maxR;
}
int moveC(int c, int direction) {
    int nc = c + dc[direction];
    if (nc < 0) return (nc + maxC);
    return nc % maxC;
}

int searchRoute(int startR, int startC, int startD, vector<string>& grid) {

    int cycleSize = 0;

    Node node(startR, startC, startD);

    while (validations[node.r][node.c][node.fromDirection] == 0) {

        validations[node.r][node.c][node.fromDirection] = 1;
        cycleSize++;

        int direction = findNextDirection(node.fromDirection, grid[node.r][node.c]);

        int nr = moveR(node.r, direction);
        int nc = moveC(node.c, direction);

        Node nextNode(nr, nc, direction);
        node = nextNode;
    }

    return cycleSize;
}

vector<int> solution(vector<string> grid) {
    
    // �� ��帶�� 4���� �������κ��� ���� �� �ִ�.
    // ����� ��ġ�� �� 4���� ���� ��Ʈ�� �����Ѵ�.
    // ��� ��带 �������� 4���� ���۷�Ʈ�� �����ؼ� ����Ŭ�� Ž���Ѵ�.
    
    // ��� ���� ��Ʈ�� �������� ������ ����Ŭ�� �����Ѵ�.
    // � ���� ��Ʈ�� �������� Ž���� �� ��,
    // ��ο� ���ԵǴ� ��忡 �ٽ� �� �� ����. �ֳ��ϸ� �� ���� ������ �� �ִ� ��δ� �ϳ��̱� ����.
    // �׸��� grid�� �ܺ� ���� ���� ������ ���� � ���ѵ� ���ٸ� �������� �̵��� �����ϴ�.
    // �׷��ٸ� ������ ó�� ���� ��Ʈ�� ������ �� �ۿ� ���� ������ � ���� ��Ʈ�� �������� �ص� ����Ŭ�� �����Ѵ�.

    vector<int> answer;
    
    maxR = grid.size();
    maxC = grid[0].length();

    validations.assign(maxR, vector<vector<int>>(maxC, vector<int>(4, 0)));

    for (int r = 0; r < maxR; r++) {
        for (int c = 0; c < maxC; c++) {
            for (int d = 0; d < 4; d++) {

                int cycleSize = searchRoute(r, c, d, grid);

                if (cycleSize == 0)
                    continue;

                answer.push_back(cycleSize);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

void service() {

    vector<string> grid = { "SL","LR" };

    vector<int> ans = solution(grid);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

����_���_����Ŭ_END