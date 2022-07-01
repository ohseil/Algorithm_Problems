#include "����Ʈ.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

����Ʈ_BEGIN

int solution(vector<int> people, int limit) {

    // ���� ū ���Ը� ���� ��� A�� �¿� ��츦 ������ ���� ��,
    // ���� ���� ���Ը� ���� ��� B�� ���� �¿� �� ���ٸ�
    // A�� ������ ȥ�� Ÿ���Ѵ�.
    // B�� ���� �¿� �� �ִٸ� A�� B�� ���� Ż �� �ִ�.
    
    // people �迭�� ���� ��, ó���� �������� 2���� ������ start, end�� �д�.
    // ���� �˰����� ����ϸ鼭 �� ������ �����͸� �ű��.
    // ȥ�� Ÿ���Ѵٸ� end--
    // �θ��� Ż �� �ִٸ� start++, end--

    int answer = 0;

    sort(people.begin(), people.end());

    int start = 0, end = people.size() - 1;

    while (start <= end) {

        if (people[start] + people[end] <= limit) {
            start++;
            end--;
        }
        else {
            end--;
        }

        answer++;
    }

    return answer;
}

void service() {

    vector<int> p = { 70, 50, 80, 50 };
    int limit = 100;
    cout << solution(p, limit) << endl;
}

����Ʈ_END