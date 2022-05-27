#include "��ȭ��ȣ_���.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    
    bool answer = true;
    
    // hashing ����� set ���
    unordered_set<string> num_set;

    sort(phone_book.begin(), phone_book.end());

    for (string phone : phone_book) {
        
        for (int i = 0; i < phone.length(); i++) {
            if (num_set.count(phone.substr(0, i + 1)) > 0) {
                answer = false;
                return answer;
            }
        }

        num_set.insert(phone);
    }
                
    return answer;
}

void ��ȭ��ȣ_���::service() {

    vector<string> p = { "119", "97674223", "1195524421" };
    cout << solution(p) << endl;
}