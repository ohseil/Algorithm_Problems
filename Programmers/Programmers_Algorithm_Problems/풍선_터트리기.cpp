#include "풍선_터트리기.h"
#include <iostream>
#include <vector>

using namespace std;

풍선_터트리기_BEGIN

void setLeftMinNums(vector<int>& leftMinNums, vector<int>& a) {
    
    leftMinNums[0] = a[0];
    
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < leftMinNums[i - 1]) leftMinNums[i] = a[i];
        else leftMinNums[i] = leftMinNums[i - 1];
    }
}

void setRightMinNums(vector<int>& rightMinNums, vector<int>& a) {

    rightMinNums[a.size() - 1] = a[a.size() - 1];

    for (int i = a.size() - 2; i >= 0; i--) {
        if (a[i] < rightMinNums[i + 1]) rightMinNums[i] = a[i];
        else rightMinNums[i] = rightMinNums[i + 1];
    }
}

int solution(vector<int> a) {
    
    // 임의로 선택한 풍선을 남기려고 해본다.
    // 만약 선택한 풍선이 가장 작은 숫자풍선이라고 한다면,
    // 어떻게 터트려도 결국 선택한 풍선이 남게 된다.
    
    // 선택한 풍선이 2번째로 작은 숫자풍선이라고 한다면,
    // 가장 작은 숫자풍선은 어떻게 해도 마지막까지 남게 되고,
    // 선택한 풍선과 인접하게 된다. 이 때 작은 풍선을 터트리는 행동을 하면 가능하다.

    // 여기까지 생각해 보면,
    // 결국에는 선택한 풍선보다 큰 숫자풍선만 남기거나
    // 선택한 풍선보다 작은 숫자를 하나만 남겨야 선택한 풍선을 마지막에 남길 수 있다.
    // 선택한 풍선보다 작은 숫자풍선이 여러개더라도 결국 인접하게 되면,
    // 마지막에는 선택한 풍선보다 작은 숫자풍선이 하나만 남게 된다.

    // 그런데,
    // 선택한 풍선을 기준으로 왼쪽 풍선들과 오른쪽 풍선들은 마지막까지 인접할 수 없다.
    // 그렇기 때문에 결국, 선택한 풍선이 마지막까지 남으려면
    // 선택한 풍선보다 작은 숫자풍선이 존재하지 않거나, 왼쪽에만 존재하거나, 오른쪽에만 존재해야 한다.

    // 각 풍선의 위치에서 왼쪽 풍선들 중 가장 작은 숫자와 오른쪽 풍선들 중 가장 작은 숫자를 알기 위해
    // 배열 2개를 만든다.
    // 풍선 배열을 왼쪽으로 한번 순회, 오른쪽으로 한번 순회해서 총 2번 순회한다.
    // 순회하면서 각 위치를 기준으로 여태 순회하면서 확인했던 숫자 중 가장 작은 숫자를 저장한다.

    // 이 2개의 배열을 사용하면 임의로 풍선을 선택했을 때,
    // 선택한 풍선을 기준으로 왼쪽과 오른쪽에 더 작은 숫자가 존재하는지 O(1) 시간복잡도로 확인할 수 있다.

    int answer = 0;
    
    vector<int> leftMinNums(a.size()), rightMinNums(a.size());

    setLeftMinNums(leftMinNums, a);
    setRightMinNums(rightMinNums, a);

    for (int i = 0; i < a.size(); i++) {

        if (leftMinNums[i] >= a[i] || rightMinNums[i] >= a[i])
            answer++;
    }

    return answer;
}

void service() {

    vector<int> a = { 9,-1,-5 };

    cout << solution(a) << endl;
}

풍선_터트리기_END