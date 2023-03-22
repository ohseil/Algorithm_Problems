#include "�ù����.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

�ù����_BEGIN

stack<int> subContainerBelt;

int findNumOfBoxCanLoadInOrder(vector<int>& order) {

    int numOfBoxCanLoad = 0;

    int boxNumToGetNow = 1;

    for (int boxNumToLoad : order) {

        if (boxNumToLoad < boxNumToGetNow) {

            if (subContainerBelt.top() != boxNumToLoad)
                break;

            subContainerBelt.pop();
        }
        else if (boxNumToLoad >= boxNumToGetNow) {

            for (int box = boxNumToGetNow; box < boxNumToLoad; box++)
                subContainerBelt.push(box);

            boxNumToGetNow = boxNumToLoad + 1;

        }

        numOfBoxCanLoad++;
    }

    return numOfBoxCanLoad;
}

int solution(vector<int> order) {
    
	/*

	    ���� �����̳� ��Ʈ�� stack ������ ����.

		order �迭�� ������� �ù踦 �Ǿ�� �Ѵ�.
		order �迭�� ��ȸ�ؼ� �Ǿ�� �� �ù踦 �ϳ��� �ƴ´�.

		�����̳� ��Ʈ������ �ù� ��ȣ�� 1���� ���ʴ�� ������ �ȴ�.
		���� �Ǿ�� �� ������ �ù� ��ȣ�� x��� ����.
		���� �����̳� ��Ʈ���� ������ �ù� ��ȣ�� a��� ����.

		[ x == a ]
		�ٷ� Ʈ���� ������ �ȴ�.

		[ x > a ]
		���� �����̳� ��Ʈ���� ������ ���� �ù��̱� ������
		x��ȣ�� ���� ������ ���� �����̳� ��Ʈ�� �ƴ´�.

		[ x < a ]
		�̹� �����̳� ��Ʈ���� ���� �ù踦 �ǹ��Ѵ�.
		���� ���� �����̳ʿ� �ִ� �ù��.
		���⼭ ���� ���� �����̳ʿ��� �ٷ� �������� ���� �� �ù� ��ȣ�� ��ġ���� �ʴ´ٸ�,
		�� �̻� �ù踦 ���� �� ���ٴ� ���� �ǹ��Ѵ�.

	*/

    int answer = 0;
    
    answer = findNumOfBoxCanLoadInOrder(order);

    return answer;
}

void service() {

    vector<int> order = { 4, 3, 1, 2, 5 };

    int answer = solution(order);
    cout << answer << endl;
}

�ù����_END