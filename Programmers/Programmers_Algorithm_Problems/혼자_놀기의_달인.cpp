#include "ȥ��_�����_����.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ȥ��_�����_����_BEGIN

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
    
	// ������ ���ڸ� �����ؼ� ����Ǿ� �ִ� ���ڸ� ����ؼ� ���� ���� ��,
	// �� ���ڴ� ������ �ִ�. �ٸ� ��ΰ� ����.
	// �׸��� ó�� ���ڸ� ������ ���ڴ�,
	// ���� ��ȣ�� �ߺ����� �ʱ� ������ �� �ٸ� ���ڷκ��� ������� �ʴ´�.
	// �׷��ٸ� ���߿� �� �� �� ���ڿ� �����ϴ� ����
	// ���� ���� ���ڰ� ó���� ���Ƿ� ������ ���� ��ȣ�� ���ۿ� ����.

	// �̰��� cycle�̶�� ������ �� �ִ�.
	// �ᱹ �� ���ӿ��� 1�� ������ 2�� ������ ���� �ϳ��� cycle�� ���Ե� ���� ���ڸ� �ǹ��Ѵ�.

	// ��� ���ڸ� ��ȸ�ϸ鼭 �� ���ڸ� ���� ���ڷ� ���� ���ڸ� Ž���� ������.
	// �ѹ� Ž�� �� ���ڴ� ���� Ž�� �� �����Ѵ�.
	// cycle�� ���� ���� �� �ƹ� ���ڿ��� �����ص� �ᱹ cycle�� ��� ���ڸ� Ž���ϱ� ������,
	// cycle ���� � ���ں��� Ž���ϴ��� �������.
	// �� cycle���� cycle�� ���Ե� ������ ������ list�� �����Ѵ�.

	// Ž���� ���� �� cycle�� ���� �������� ������ list�� ���� ������ 1�����,
	// cycle�� �ϳ���� �ǹ��̰�, 1�� ������ Ž���ϴ� �������� ��� ���ڰ� ���ȴٴ� �ǹ��̴�.
	// �׷��� ������ 0���� �ǹ��Ѵ�.

	// cycle�� ���� �������� ������ list�� ���� ������ 2�� �̻��̶��,
	// ������������ �����ؼ� ���� ū �� ���ڸ� 1�� ������ 2�� �������� �����Ѵ�.

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

ȥ��_�����_����_END