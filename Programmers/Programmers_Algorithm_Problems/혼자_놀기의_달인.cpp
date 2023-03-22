#include "혼자_놀기의_달인.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

혼자_놀기의_달인_BEGIN

vector<bool> boxOpenedStatusList;
vector<int> numOfBoxesOfCycleList;

void initAllOfTheLists(vector<int>& boxList) {
    boxOpenedStatusList.assign(boxList.size(), false);
}

void openLinkingBoxes(vector<int> boxList, int startBoxNum) {

    int numOfLinkingBoxes = 0;
    int openingBoxNum = startBoxNum;
    bool boxOpenStatus = boxOpenedStatusList[startBoxNum];

    while (boxOpenStatus == false) {

        boxOpenedStatusList[openingBoxNum] = true;
        numOfLinkingBoxes++;

        openingBoxNum = boxList[openingBoxNum] - 1;
        boxOpenStatus = boxOpenedStatusList[openingBoxNum];
    }

    if (numOfLinkingBoxes > 0)
        numOfBoxesOfCycleList.push_back(numOfLinkingBoxes);
}

void openAllTheBoxes(vector<int>& boxList) {

    for (int i = 0; i < boxList.size(); i++) {

        bool boxOpenStatus = boxOpenedStatusList[i];

        if (boxOpenStatus == true)
            continue;

        openLinkingBoxes(boxList, i);
    }
}

int findMaxGameScore() {

    int maxGameScore;

    if (numOfBoxesOfCycleList.size() < 2)
        return 0;

    sort(numOfBoxesOfCycleList.begin(), numOfBoxesOfCycleList.end(), greater<>());
    maxGameScore = numOfBoxesOfCycleList[0] * numOfBoxesOfCycleList[1];

    return maxGameScore;
}

int solution(vector<int> cards) {
    
	// 임의의 상자를 선택해서 연결되어 있는 상자를 계속해서 열어 나갈 때,
	// 열 상자는 정해져 있다. 다른 경로가 없다.
	// 그리고 처음 상자를 제외한 상자는,
	// 상자 번호가 중복되지 않기 때문에 또 다른 상자로부터 연결되지 않는다.
	// 그렇다면 도중에 한 번 연 상자에 접근하는 경우는
	// 상자 안의 숫자가 처음에 임의로 선택한 상자 번호인 경우밖에 없다.

	// 이것을 cycle이라고 생각할 수 있다.
	// 결국 이 게임에서 1번 집군과 2번 집군은 각각 하나의 cycle에 포함된 상자 숫자를 의미한다.

	// 모든 상자를 순회하면서 각 상자를 시작 상자로 놓고 상자를 탐색해 나간다.
	// 한번 탐색 된 상자는 다음 탐색 때 제외한다.
	// cycle에 속한 상자 중 아무 상자에서 시작해도 결국 cycle의 모든 상자를 탐색하기 때문에,
	// cycle 내의 어떤 상자부터 탐색하던지 상관없다.
	// 각 cycle마다 cycle에 포함된 상자의 개수를 list로 저장한다.

	// 탐색이 끝난 후 cycle의 상자 개수들을 저장한 list의 원소 개수가 1개라면,
	// cycle이 하나라는 의미이고, 1번 집군을 탐색하는 과정에서 모든 상자가 열렸다는 의미이다.
	// 그렇기 때문에 0점을 의미한다.

	// cycle의 상자 개수들을 저장한 list의 원소 개수가 2개 이상이라면,
	// 내림차순으로 정렬해서 가장 큰 두 숫자를 1번 집군과 2번 집군으로 선택한다.

    int answer = 0;
    
    initAllOfTheLists(cards);
    openAllTheBoxes(cards);

    answer = findMaxGameScore();

    return answer;
}

void service() {

    vector<int> cards = { 8,6,3,7,2,5,1,4 };

    int answer = solution(cards);
    cout << answer << endl;
}

혼자_놀기의_달인_END