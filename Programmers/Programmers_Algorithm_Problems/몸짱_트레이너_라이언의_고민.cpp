#include "��¯_Ʈ���̳�_���̾���_���.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

��¯_Ʈ���̳�_���̾���_���_BEGIN

int solution(int n, int m, vector<vector<int>> timetable) {
    
    // ���� �� �Ÿ��� �ּ� ���� �־����� ��,
    // ��ġ�� �� �ִ� �ִ� ȸ�� �� ���ϱ�            
    // �׷����� dfs ���            
    // ���� �ϳ��� ���� ����             
    // ���� �� �Ÿ��� �־��� �ּ� �� �̻���            
    // ��θ� �����ؼ� �׷����� �����            
    // bfs�� ���� ���� ���� ���ڸ� ������ ��θ� Ž���Ѵ�.

    if (n <= 1 || m <= 1)
        return 0;

    int answer = 0;
    
    vector<int> time_line(1322, 0);

    for (vector<int> time : timetable) {
        time_line[time[0]]++;
        time_line[time[1] + 1]--;
    }

    int max_count = 0;
    int cur_count = 0;

    for (int t = 600; t <= 1321; t++) {
        cur_count += time_line[t];
        if (cur_count > max_count)
            max_count = cur_count;
    }

    if (max_count == 1) {
        answer = 0;
    }
    else if (max_count == 2) {
        answer = 2 * (n - 1);
    }
    else {

        for (int dist = 2 * (n - 1); dist > 0; dist--) {

            map<pair<int, int>, vector<pair<int, int>>> m;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < n; jj++) {

                            int len = abs(i - ii) + abs(j - jj);
                            if (len >= dist) {
                                m[{i, j}].emplace_back(ii, jj);
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    stack<pair<int, int>> st;
                    vector<vector<bool>> validation_v(n, vector<bool>(n, false));

                    pair<int, int> start(i, j);
                    st.push(start);
                    validation_v[i][j] = true;

                    while (st.empty() == false) {

                        if (st.size() == max_count) {
                            answer = dist;
                            return answer;
                        }

                        pair<int, int> data = st.top();

                        bool isNext = false;

                        for (auto next : m[data]) {
                            if (validation_v[next.first][next.second] == true)
                                continue;

                            stack<pair<int, int>> temp = st;
                            
                            while (temp.empty() == false) {
                                pair<int, int> top = temp.top();
                                if (abs(next.first - top.first) + abs(next.second - top.second) < dist) {
                                    break;
                                }
                                temp.pop();
                            }

                            if (temp.empty() == false)
                                continue;

                            st.push(next);
                            isNext = true;
                            validation_v[next.first][next.second] = true;
                            break;
                        }

                        if (isNext == false)
                            st.pop();
                    }


                }
            }

        }

    }

    return answer;
}

void service() {

    int n = 4;
    int m = 5;
    vector<vector<int>> tt = { {1140, 1200},{1150, 1200},{1100, 1200},{1210, 1300},{1220, 1280} };
    cout << solution(n, m, tt) << endl;
}

��¯_Ʈ���̳�_���̾���_���_END