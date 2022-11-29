#include "����_�κ�_����_����_����.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

����_�κ�_����_����_����_BEGIN

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
    
    // Subsequence��� ������ class�� �����Ѵ�.     
    // Subsequence �ȿ���     
    // ���� index, �����ϴ� ������ ����, ���� �� ������ �� �� ������ �����Ѵ�.     
    // �׸��� ���� ���ؾ� �� ������ index�� ��ȯ�ϴ� �Լ��� ������ �ִ�.   
    // ���� ���ؾ� �� ������ index = (���� index + �����ϴ� ������ ����) % elements�� ���� �� ���� �� �ִ�.
    // �����̱� ������ % ������ ����� �Ѵ�.
  
    // elements�� �� ���ҵ��� ���������� �ؼ� Subsequence ��ü�� ���� ť�� �����Ѵ�.  
    // ť�� ����ִ� Subsequence ��ü�� �������� ������,
    // ���� �����ؾ� �� ���ڸ� ���Խ�Ű�� �ٽ� ť�� ���Եȴ�. 
    // �����ϱ� ���� ���ڸ� ������ ���� ���ڵ��� ������ Hash Set�� �����ؼ� �ߺ��� ������ �κ� ������ �յ��� ���Ѵ�.

    // Subsequence�� ť�� �ٽ� �����ϱ� ����, 
    // Subsequence�� ���� ���� �� ������ ������ Ȯ���Ѵ�.  
    // ������ ������ elements�� length�� �����ϴٸ� ��� ���ڸ� �����ϴ� ���̱� ������  
    // ť�� �������� �ʴ´�. 
    // �ֳ��ϸ� ��� Subsequence�� �ᱹ ��� ���ڸ� �����ϰ� �Ǳ� ������ ���ʿ��� ������ �����ϱ� ���ؼ���.
    // ��� ���ڸ� �����ϴ� �κ� ������ �����ϰ� 1���̱� ������ ���߿� �����ش�.

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

����_�κ�_����_����_����_END