#include "�������_��_����_����.h"
#include <iostream>
#include <vector>

using namespace std;

�������_��_����_����_BEGIN

void compress(vector<int>& ans, vector<vector<int>>& p, pair<int, int> pos1, pair<int, int> pos2) {

    int x1 = pos1.first, y1 = pos1.second, x2 = pos2.first, y2 = pos2.second;

    int width = (x2 - x1 + 1) * (y2 - y1 + 1);
    int value = p[y2][x2] - p[y1 - 1][x2] - p[y2][x1 - 1] + p[y1 - 1][x1 - 1];

    if (value == 0) {
        ans[0]++;
        return;
    }

    if (value == width) {
        ans[1]++;
        return;
    }

    compress(ans, p, { x1, y1 }, { (x1 + x2) / 2, (y1 + y2) / 2 });
    compress(ans, p, { (x1 + x2) / 2 + 1, y1 }, { x2, (y1 + y2) / 2 });
    compress(ans, p, { x1, (y1 + y2) / 2 + 1 }, { (x1 + x2) / 2, y2 });
    compress(ans, p, { (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1 }, { x2, y2 });
}

vector<int> solution(vector<vector<int>> arr) {
    
    // �׳� ����ϸ� �ð� �ʰ��� �� ���̶�� �����ؼ�,
    // ���� ��(prefix sum) �˰��� ���.
    // 2���� ���� �� �迭�� ���ؼ� ��ͷ� ���.

    vector<int> answer(2, 0);
    
    int size = arr.size();
    vector<vector<int>> cal_v(size + 1, vector<int>(size + 1, 0));

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cal_v[i][j] = cal_v[i][j - 1] + arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            cal_v[j][i] += cal_v[j - 1][i];
        }
    }

    compress(answer, cal_v, { 1, 1 }, { size, size });

    return answer;
}

void service() {

    vector<vector<int>> arr = { {1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1} };
    vector<int> ans = solution(arr);

    cout << ans[0] << " " << ans[1] << endl;
}

�������_��_����_����_END