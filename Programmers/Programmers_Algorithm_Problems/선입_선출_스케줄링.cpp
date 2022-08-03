#include "����_����_�����ٸ�.h"
#include <iostream>
#include <vector>

using namespace std;

����_����_�����ٸ�_BEGIN

long long getHandleCount(vector<int>& cores, int t) {

    long long count = 0;

    for (int core : cores)
        count += ((long long)t / core);

    return count;
}

int solution(int n, vector<int> cores) {
    
    // �̺� Ž�� ���.
    
    // �ð� t�� �־����� ��,
    // t�ð� ���� ó���� �� �ִ� �۾� ���� ���Ѵ�.
    // ó�� ������ �۾� ���� n�̶� ���� ����� �ð��� ���Ѵ�.

    // ���� ������ �ð� rt�� ���ߴٸ�,
    // rt �ð��� �۾��� �ð� �� core ����Ʈ�� ���Ѵ�.
    // ���� ������ �ð��� ���߱� ������ �ش� �ð��� �ð� �� core�� �� ������ ������ �ִ�.
    // rt �ð��� ó���Ǵ� �۾����� ����ϸ鼭 n���� ����.
    // ������ rt �ð��� �ðԵ� �ھ���� �ð� �� �۾��� ���� ����Ѵ�.
    // ������ ��� ��� �Ŀ� ���� n�� ������ rt �ð��� ���� �ھ�� ��
    // ������ �ðԵǴ� �ھ��� ������ �˱� �����̴�.

    if (n <= cores.size())
        return n;

    int answer = 0;
    
    int maxTime = cores[0];

    for (int coreTime : cores)
        if (coreTime > maxTime)
            maxTime = coreTime;

    int start = 1, end = maxTime * (n / cores.size()), mid;

    n -= cores.size();

    int smallestTime = end;

    while (start <= end) {
        
        mid = (start + end) / 2;

        if (getHandleCount(cores, mid) >= n) {
            
            if (mid < smallestTime)
                smallestTime = mid;

            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    vector<int> v;

    for (int i = 0; i < cores.size(); i++) {

        if (smallestTime % cores[i] == 0) {
            n -= (smallestTime / cores[i] - 1);
            v.emplace_back(i + 1);
        }
        else {
            n -= (smallestTime / cores[i]);
        }
    }

    answer = v[n - 1];

    return answer;
}

void service() {

    int n = 6;
    vector<int> cores = { 1,2,3 };

    cout << solution(n, cores) << endl;
}

����_����_�����ٸ�_END