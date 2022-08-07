#include "줄_서는_방법.h"
#include <iostream>
#include <vector>

using namespace std;

줄_서는_방법_BEGIN

vector<int> solution(int n, long long k) {
    
    // 규칙을 찾아서 해결했다.

    // 규칙을 찾아보면,
    // 처음 한자리만 움직이는 경우를 보면 1가지이고
    // 두 자리만 움직이는 경우를 보면 2가지이다.
    // 그리고 세 자리만 움직이는 경우를 보면 6가지이다.
    // n번재 자리의 숫자들의 모든 순서의 가지수는 n! 가지이다.
    // 그럼 n번째 자리가 고정되어 있는 경우를 생각해 보면,
    // 그 밑의 자리들의 모든 순서의 개수는 (n-1)! 가지이다.
    // (n-1)! 가지가 지난 후에 n자리 수가 다음 숫자로 바뀐다는 것이다.
    // 이 규칙을 생각해서 처음에 k를 (n-1)!으로 나눈 몫을 index로 해서
    // 정렬되어 있는 배열의 숫자의 위치를 찾는다.
    // 이 때, 찾은 숫자는 배열에서 제거한다.
    // k의 값도 k %= (n-1)!이 된다.
    // 이 과정을 통해서 첫번째 자리의 숫자부터 마지막 자리의 숫자까지 선택해 나간다.
    // 도중에 k가 0이 되는 경우는 배열에 남아있는 숫자를 그대로 선택하면 된다.

    vector<int> answer;
    vector<int> numV;
    long long factorial = 1;
    int facLastNum = n - 1;

    for (int i = 1; i <= n; i++)
        numV.push_back(i);

    for (int i = 2; i <= facLastNum; i++)
        factorial *= i;

    k--;

    while (k > 0) {

        int quotient = k / factorial;
        
        answer.push_back(numV[quotient]);

        numV.erase(numV.begin() + quotient);
    
        k %= factorial;
        factorial /= facLastNum;
        facLastNum--;
    }

    if (numV.empty() == false)
        for (int num : numV)
            answer.push_back(num);

    return answer;
}

void service() {

    int n = 3;
    int k = 5;

    vector<int> ans = solution(n, k);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}

줄_서는_방법_END