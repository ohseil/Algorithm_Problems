#include "위장.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

위장_BEGIN

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    
    unordered_map<string, int> kind_m;

    for (vector<string> cloth : clothes) {
        kind_m[cloth[1]]++;
    }

    for (auto kind : kind_m)
        answer *= (kind.second + 1);

    answer--;

    return answer;
}

void service() {

    vector<vector<string>> c = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} };
    cout << solution(c) << endl;
}

위장_END