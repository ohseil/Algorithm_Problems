#include "ī��Ʈ_�ٿ�.h"
#include <iostream>
#include <vector>

using namespace std;

ī��Ʈ_�ٿ�_BEGIN

#define MAX_TOTAL_SCORE_CAN_GET 100000
#define BULL_SCORE 50
#define MAX_SINGLE_SCORE 20
#define MAX_SCORE_PER_DART 60
#define IDX_NUM_OF_DART 0
#define IDX_NUM_OF_SINGLE_OR_BULL 1

int bestPlayToGetScoreList[MAX_TOTAL_SCORE_CAN_GET + 1][2];

void initBestPlayToGetScoreList() {

    for (int score = 1; score <= MAX_SINGLE_SCORE; score++) {

        int doubleScore = score * 2;
        int tripleScore = score * 3;

        bestPlayToGetScoreList[score][IDX_NUM_OF_DART] = 1;
        bestPlayToGetScoreList[score][IDX_NUM_OF_SINGLE_OR_BULL] = 1;
        bestPlayToGetScoreList[doubleScore][IDX_NUM_OF_DART] = 1;
        bestPlayToGetScoreList[doubleScore][IDX_NUM_OF_SINGLE_OR_BULL] = 0;
        bestPlayToGetScoreList[tripleScore][IDX_NUM_OF_DART] = 1;
        bestPlayToGetScoreList[tripleScore][IDX_NUM_OF_SINGLE_OR_BULL] = 0;
    }

    bestPlayToGetScoreList[BULL_SCORE][IDX_NUM_OF_DART] = 1;
    bestPlayToGetScoreList[BULL_SCORE][IDX_NUM_OF_SINGLE_OR_BULL] = 1;

}

bool canGetScoreInOneDart(int score) { return bestPlayToGetScoreList[score][0] == 1; }

void findBestPlayToGetScore(int score, int maxScoreToGet) {

    int minNumOfDart = score;
    int maxNumOfSingleOrBull = 0;

    for (int dartScore = 1; dartScore <= maxScoreToGet; dartScore++) {

        if (canGetScoreInOneDart(dartScore) == false)
            continue;

        int beforeScore = score - dartScore;
        int numOfDartToGetBeforeScore = bestPlayToGetScoreList[beforeScore][IDX_NUM_OF_DART];
        int numOfSingleOrBullToGetBeforeScore = bestPlayToGetScoreList[beforeScore][IDX_NUM_OF_SINGLE_OR_BULL];

        int unitOfDart = 1;
        bool isSingleOrBull = (bestPlayToGetScoreList[dartScore][IDX_NUM_OF_SINGLE_OR_BULL] == 1) ? true : false;

        int expectedNumOfDart = numOfDartToGetBeforeScore + unitOfDart;
        int expectedNumOfSingleOrBull = numOfSingleOrBullToGetBeforeScore + ((isSingleOrBull == true) ? 1 : 0);

        if (expectedNumOfDart < minNumOfDart
            || (expectedNumOfDart == minNumOfDart && expectedNumOfSingleOrBull > maxNumOfSingleOrBull)) {
            minNumOfDart = expectedNumOfDart;
            maxNumOfSingleOrBull = expectedNumOfSingleOrBull;
        }

    }

    bestPlayToGetScoreList[score][IDX_NUM_OF_DART] = minNumOfDart;
    bestPlayToGetScoreList[score][IDX_NUM_OF_SINGLE_OR_BULL] = maxNumOfSingleOrBull;

}

vector<int> solution(int target) {
    
    // dynamic programming���� �ذ��ߴ�.       
    // dp[n][0] = ���� n�� ������� �ʿ��� �ּ� ��Ʈ ����        
    // dp[n][1] = ���� n�� ������� �ʿ��� �ִ� single or bull ����
        
    // ��Ʈ�� �ѹ��� ���� �� �ִ� ������ �ִ� 60���̴�.      
    // dp[60]���� �ʱ�ȭ�� �Ѵ�.
        
    // --< dp[1] ~ dp[20] >--        
    // �Ѱ��� ��Ʈ�� single ������ ���� �� �ִ�. dp[n][0] = 1, dp[n][1] = 1
        
    // --< dp[21] ~ dp[60] >--        
    // double, triple ������ �ѹ��� ���� �� �ִ� ������� dp[n][0] = 1, dp[n][1] = 0
    // �׷��� �ʴٸ�, dp[61] �̻�� ���������� dp�� ����Ѵ�.
      
    // dp[50]�� �Ѱ��� ��Ʈ�� bull ������ ���� �� �ִ�. dp[n][0] = 1, dp[n][1] = 1
        
    // --< dp[61] ~ dp[n] >--
    // dp[61] �̻���� dp[n]�� ����ϴ� ������
    // dp[n-1], dp[n-2] .. dp[n-60] �߿��� ���� �켱 ������ ���� �����͸� �����Ѵ�.
        
    // �켱 ������ ������,        
    // 1. ��Ʈ ������ ����� �Ѵ�. -> dp[n-score][0] + dp[score][0] ���� ���� �۾ƾ� �Ѵ�.        
    // 2. ��Ʈ ������ ���ٸ� single or bull ������ ���ƾ� �Ѵ�. -> dp[n-score][1] + dp[score][1] ���� ���� Ŀ�� �Ѵ�.        
    // �� �켱 ������ ������� �� ���� �켱 ������ ���� �����Ͱ� ���� �ȴ�.  
    // dp[n][0] = dp[n-score][0] + dp[score][0]  
    // dp[n][1] = dp[n-score][1] + dp[score][1]

    vector<int> answer;

    initBestPlayToGetScoreList();
    
    for (int score = MAX_SINGLE_SCORE + 1; score <= target; score++) {

        if (score <= MAX_SCORE_PER_DART) {
            if (canGetScoreInOneDart(score) == false)
                findBestPlayToGetScore(score, score - 1);
        }
        else
            findBestPlayToGetScore(score, MAX_SCORE_PER_DART);
    }

    answer = { bestPlayToGetScoreList[target][0], bestPlayToGetScoreList[target][1] };

    return answer;
}

void service() {

    int target = 58;

    vector<int> answer = solution(target);
    cout << answer[0] << " " << answer[1] << endl;
}

ī��Ʈ_�ٿ�_END