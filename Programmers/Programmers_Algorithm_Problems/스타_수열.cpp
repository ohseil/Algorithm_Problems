#include "��Ÿ_����.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

��Ÿ_����_BEGIN

int solution(std::vector<int> a) {
    
    // a�� ��Ÿ ������ ����� ����� ���Ҹ� ����� ��� �ۿ� ����.
    // a�� ���� �� �� ������ ������ �ش� ���ڵ��� ��ġ�� ���� �����Ѵ�.
    // �� ���ڵ��� ��Ÿ ������ �κ� ������ ���Ұ� �� �� �ִ�.
    // ������ ������ �������� �������� ������ �� ��
    // ���� ���� ������ ���ں��� �ش� ���ڸ� �������� ��Ÿ ������ ���� �� �ִ��� Ȯ���Ѵ�.

    // Ȯ���ϴ� ����� ���ڵ��� index�� �̿��ؼ� Ȯ���Ѵ�.
    // ��ġ�� ���� �����ϴ� �������� �ڿ������� index�� �������� ���ĵȴ�.
    // ���� Ȯ���ϴ� ���ڸ� num�̶�� �Ҷ�,
    // �� ��ġ���� �ش� ��ġ�� �ٷ� �հ� ���� ���ڰ� num�� �ٸ� �������� Ȯ���Ѵ�.
    // �ٸ� ���ڰ� �ִ� ��쿡�� �� ��ġ�� ���ڴ� ��Ÿ ������ ���Ե� �� �ִٴ� ���� �ǹ��Ѵ�.
    // �̶� num�� �ٸ� ������ index�� ��� �����Ѵ�. �ֽ� index�� ������ �ִ´�.
    // ������ ���� ��ġ�� num�� ��Ʈ�� �� ���ڴ� ������ num�� ��Ʈ�� �� �� ���� ������
    // �̰��� Ȯ���ϱ� ���� num�� ��Ʈ�� �� ������ �ֽ� index�� ������ ������ �ִ´�.

    if (a.size() < 2)
        return 0;

    int answer = 0;
    
    map<int, int> count_m;
    map<int, vector<int>> idx_m;

    for (int i = 0; i < a.size(); i++) {
        count_m[a[i]]++;
        idx_m[a[i]].push_back(i);
    }

    map<int, int> sorted_m;

    for (auto count : count_m)
        sorted_m[-count.second] = count.first;

    for (auto data : sorted_m) {

        int num = data.second;
        vector<int> idx_v = idx_m[num];

        int count = 0;
        int cur_idx = -1;

        for (int idx : idx_v) {

            if (idx == 0) {
                
                if (a[idx + 1] != num) {
                    count += 2;
                    cur_idx = idx + 1;
                }
            }
            else {

                if (idx - 1 > cur_idx && a[idx - 1] != num) {
                    count += 2;
                    cur_idx = idx - 1;
                }
                else if (idx + 1 < a.size() && a[idx + 1] != num) {
                    count += 2;
                    cur_idx = idx + 1;
                }
            }
        }

        if (answer < count)
            answer = count;
    }

    return answer;
}

void service() {

    vector<int> a = { 0,3,3,0,7,2,0,2,2,0 };
    cout << solution(a) << endl;
}

��Ÿ_����_END