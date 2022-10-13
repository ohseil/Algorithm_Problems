#include "¡�˴ٸ�_�ǳʱ�.h"
#include <iostream>
#include <vector>

using namespace std;

¡�˴ٸ�_�ǳʱ�_BEGIN

#define MAX_PEOPLE 200000000

bool canCross(vector<int>& stones, int k, int crossCount) {

    int maxLength = 0;
    int zeroSequenceLength = 0;

    for (int stone : stones) {
        if (stone - crossCount < 0) {
            zeroSequenceLength++;
            if (zeroSequenceLength > maxLength)
                maxLength = zeroSequenceLength;
        }
        else
            zeroSequenceLength = 0;
    }

    return maxLength < k;
}

int solution(vector<int> stones, int k) {
    
    // �̺� Ž�� ���.
    // �ǳ� �� �ִ� �ִ� ģ�� ���� ã�´�.
    // �˻� ������,
    // �ǳʴ� ģ�� �� x�� �ǳʹٰ� ������ ��,
    // ¡�˴ٸ��� ��ȸ�ϸ鼭 ���� ���� �� �ִ� ���ڿ��� x�� ���� ��,
    // 0�� �Ǵ� ���� �ִ� �󸶳� ���ӵǴ��� ã�´�.
    // ���ӵǴ� �ִ� ���ڰ� k ���϶�� x���� �ǳ� �� �ִٴ� �ǹ̴�.

    // ���⼭ ���ӵǴ� �ִ� ���ڰ� k�� ���ԵǴ� ������,
    // ���� ���� ���� ��Ȯ�ϰ� 0�� �Ǵ� ��츸 ���� ������,
    // �ᱹ x���� ������ ���Ŀ� ���ӵǴ� ������ k���� �Ǵ� ���̱� ������
    // �ǳ� �� �ִ� ������ �� �� �ִ�.

    int answer = 0;

    int start = 1, end = MAX_PEOPLE, mid;

    while (start <= end) {

        mid = (start + end) / 2;

        if (canCross(stones, k, mid) == true) {
            start = mid + 1;
            if (answer < mid)
                answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    return answer;
}

void service() {

    vector<int> stones = { 2, 4, 5, 3, 2, 1, 5, 2, 5, 1 };
    int k = 3;

    cout << solution(stones, k) << endl;
}

¡�˴ٸ�_�ǳʱ�_END