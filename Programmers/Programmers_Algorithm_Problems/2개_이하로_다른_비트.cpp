#include "2��_���Ϸ�_�ٸ�_��Ʈ.h"
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

_2��_���Ϸ�_�ٸ�_��Ʈ_BEGIN

vector<long long> solution(vector<long long> numbers) {
    
    // ���ڸ� ��Ʈ�� ǥ������ �� ��Ʈ ���� 1�� �ڸ� �� ���� ���� �ڸ� x�� ��������
    // ������ �Ʒ� �ڸ��� ���ڸ� Ȯ���Ѵ�.
    // �̶� 2���� ���� ������.
    
    // 1. �Ʒ� �ڸ��� ��Ʈ ���� ��� 1�� ���
    // 2. �Ʒ� �ڸ��� ��Ʈ �� �� �ּ� �ϳ� �̻��� 0�� ���
    
    // 1���� ��쿡�� x���� �ϳ� ���� �ڸ��� ��Ʈ�� 0���� 1�� �ٲ� ��
    // x�ڸ��� ��Ʈ�� 0���� �ٲ� ���ڰ� ���̴�.
    
    // 2���� ��쿡�� ��Ʈ ���� 0�� �ڸ� �� ���� ���� �ڸ��� ���� 1�� �ٲ� ��
    // �ٲ� �ڸ����� �Ʒ� �ڸ��� 1�� �ִٸ� 1�� 0���� �ٲ� ���ڰ� ���̴�.

    vector<long long> answer;
    
    for (long long num : numbers) {
        
        bitset<64> bs(num);

        int one_idx = -1, zero_idx = -1;

        for (int i = 63; i >= 0; i--) {
            if (bs[i] == 1) {
                one_idx = i;
                break;
            }
        }

        for (int i = 0; i < one_idx; i++) {
            if (bs[i] == 0) {
                zero_idx = i;
                break;
            }
        }

        if (zero_idx == -1) {

            bs[one_idx + 1] = 1;
            bs[one_idx] = 0;
        }
        else {

            bs[zero_idx] = 1;
            
            if (zero_idx > 0)
                bs[zero_idx - 1] = 0;
        }

        answer.push_back((long long)bs.to_ullong());
    }

    return answer;
}

void service() {

    vector<long long> n = { 2,7 };
    vector<long long> ans = solution(n);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

}

_2��_���Ϸ�_�ٸ�_��Ʈ_END