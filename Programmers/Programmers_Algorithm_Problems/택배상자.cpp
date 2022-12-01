#include "택배상자.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

택배상자_BEGIN

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

	    보조 컨테이너 벨트는 stack 구조와 같다.

		order 배열의 순서대로 택배를 실어야 한다.
		order 배열을 순회해서 실어야 할 택배를 하나씩 싣는다.

		컨테이너 벨트에서는 택배 번호가 1부터 차례대로 내리게 된다.
		현재 실어야 할 순서의 택배 번호를 x라고 하자.
		현재 컨테이너 벨트에서 내리는 택배 번호를 a라고 하자.

		[ x == a ]
		바로 트럭에 실으면 된다.

		[ x > a ]
		아직 컨테이너 벨트에서 내리지 않은 택배이기 때문에
		x번호가 나올 때까지 보조 컨테이너 벨트에 싣는다.

		[ x < a ]
		이미 컨테이너 벨트에서 내린 택배를 의미한다.
		따라서 보조 컨테이너에 있는 택배다.
		여기서 만약 보조 컨테이너에서 바로 꺼내지는 가장 앞 택배 번호와 일치하지 않는다면,
		더 이상 택배를 실을 수 없다는 것을 의미한다.

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

택배상자_END