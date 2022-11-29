#include "연속_부분_수열_합의_개수.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

연속_부분_수열_합의_개수_BEGIN

#define HashSet unordered_set

#define NUM_OF_SUBSEQUENCE_INCLUDED_ALL_ELEMENT 1

int lenOfElementList;

class Subsequence {

public:

    int startIdx;
    int numOfDigits;
    int sum;
    
    Subsequence(int startIdx, int numOfDigits, int sum)
    : startIdx(startIdx), numOfDigits(numOfDigits), sum(sum) {}

    int getNextIdxOfNumToAdd() {
        return (startIdx + numOfDigits) % lenOfElementList;
    }
};

HashSet<int> numSet;
queue<Subsequence> q;

void init(vector<int>& elements) {
    lenOfElementList = elements.size();
}

void findAllSubsequence(vector<int>& elements) {

    for (int i = 0; i < lenOfElementList; i++)
        q.push(Subsequence(i, 1, elements[i]));

    while (q.empty() == false) {

        Subsequence subsequence = q.front();
        q.pop();

        numSet.insert(subsequence.sum);

        if (subsequence.numOfDigits + 1 == lenOfElementList)
            continue;

        subsequence.sum += elements[subsequence.getNextIdxOfNumToAdd()];
        subsequence.numOfDigits++;
        q.push(subsequence);
    }
}

int solution(vector<int> elements) {
    
    // Subsequence라는 개념을 class로 정의한다.     
    // Subsequence 안에는     
    // 시작 index, 포함하는 숫자의 개수, 포함 된 숫자의 총 합 정보를 포함한다.     
    // 그리고 다음 더해야 할 숫자의 index를 반환하는 함수를 가지고 있다.   
    // 다음 더해야 할 숫자의 index = (시작 index + 포함하는 숫자의 개수) % elements의 길이 로 구할 수 있다.
    // 원형이기 때문에 % 연산을 해줘야 한다.
  
    // elements의 각 원소들을 시작점으로 해서 Subsequence 객체를 만들어서 큐에 삽입한다.  
    // 큐에 담겨있는 Subsequence 객체는 빠져나올 때마다,
    // 다음 포함해야 할 숫자를 포함시키고 다시 큐에 삽입된다. 
    // 삽입하기 전에 숫자를 포함한 후의 숫자들의 총합을 Hash Set에 저장해서 중복을 제거한 부분 수열의 합들을 구한다.

    // Subsequence를 큐에 다시 삽입하기 전에, 
    // Subsequence의 현재 포함 된 숫자의 개수를 확인한다.  
    // 숫자의 개수가 elements의 length와 동일하다면 모든 숫자를 포함하는 것이기 때문에  
    // 큐에 삽입하지 않는다. 
    // 왜냐하면 모든 Subsequence는 결국 모든 숫자를 포함하게 되기 때문에 불필요한 연산을 제거하기 위해서다.
    // 모든 숫자를 포함하는 부분 수열은 유일하게 1개이기 때문에 나중에 더해준다.

    int answer = 0;
    
    init(elements);
    findAllSubsequence(elements);

    answer = numSet.size() + NUM_OF_SUBSEQUENCE_INCLUDED_ALL_ELEMENT;

    return answer;
}

void service() {

    vector<int> elements = { 7,9,1,1,4 };

    int answer = solution(elements);
    cout << answer << endl;
}

연속_부분_수열_합의_개수_END