package Problems.연습문제.카운트_다운;

public class Solution {

    private final int MAX_TOTAL_SCORE_CAN_GET = 100000;
    private final int BULL_SCORE = 50;
    private final int MAX_SINGLE_SCORE = 20;
    private final int MAX_SCORE_PER_DART = 60;
    private final int IDX_NUM_OF_DART = 0;
    private final int IDX_NUM_OF_SINGLE_OR_BULL = 1;

    private int bestPlayToGetScoreList[][];

    private void initBestPlayToGetScoreList() {

        bestPlayToGetScoreList = new int[MAX_TOTAL_SCORE_CAN_GET + 1][2];

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

    private boolean canGetScoreInOneDart(final int score) { return bestPlayToGetScoreList[score][0] == 1; }

    private void findBestPlayToGetScore(final int score, final int maxScoreToGet) {

        int minNumOfDart = score;
        int maxNumOfSingleOrBull = 0;

        for (int dartScore = 1; dartScore <= maxScoreToGet; dartScore++) {

            if (canGetScoreInOneDart(dartScore) == false)
                continue;

            int beforeScore = score - dartScore;
            int numOfDartToGetBeforeScore = bestPlayToGetScoreList[beforeScore][IDX_NUM_OF_DART];
            int numOfSingleOrBullToGetBeforeScore = bestPlayToGetScoreList[beforeScore][IDX_NUM_OF_SINGLE_OR_BULL];

            int unitOfDart = 1;
            boolean isSingleOrBull = (bestPlayToGetScoreList[dartScore][IDX_NUM_OF_SINGLE_OR_BULL] == 1) ? true : false;

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

    public int[] solution(int target) {

        // dynamic programming으로 해결했다.
        // dp[n][0] = 점수 n을 얻기위해 필요한 최소 다트 개수
        // dp[n][1] = 점수 n을 얻기위해 필요한 최대 single or bull 개수

        // 다트로 한번에 얻을 수 있는 점수는 최대 60점이다.
        // dp[60]까지 초기화를 한다.

        // --< dp[1] ~ dp[20] >--
        // 한개의 다트로 single 점수로 얻을 수 있다. dp[n][0] = 1, dp[n][1] = 1

        // --< dp[21] ~ dp[60] >--
        // double, triple 점수로 한번에 얻을 수 있는 점수라면 dp[n][0] = 1, dp[n][1] = 0
        // 그렇지 않다면, dp[61] 이상과 마찬가지로 dp를 계산한다.

        // dp[50]은 한개의 다트로 bull 점수로 얻을 수 있다. dp[n][0] = 1, dp[n][1] = 1

        // --< dp[61] ~ dp[n] >--
        // dp[61] 이상부터 dp[n]을 계산하는 과정은
        // dp[n-1], dp[n-2] .. dp[n-60] 중에서 가장 우선 순위가 높은 데이터를 선택한다.

        // 우선 순위의 조건은,
        // 1. 다트 개수가 적어야 한다. -> dp[n-score][0] + dp[score][0] 값이 가장 작아야 한다.
        // 2. 다트 개수가 같다면 single or bull 개수가 많아야 한다. -> dp[n-score][1] + dp[score][1] 값이 가장 커야 한다.
        // 이 우선 순위를 고려했을 때 가장 우선 순위가 높은 데이터가 선택 된다.
        // dp[n][0] = dp[n-score][0] + dp[score][0]
        // dp[n][1] = dp[n-score][1] + dp[score][1]

        int[] answer;

        initBestPlayToGetScoreList();

        for (int score = MAX_SINGLE_SCORE + 1; score <= target; score++) {

            if (score <= MAX_SCORE_PER_DART) {
                if (canGetScoreInOneDart(score) == false)
                    findBestPlayToGetScore(score, score - 1);
            }
            else
                findBestPlayToGetScore(score, MAX_SCORE_PER_DART);
        }

        answer = bestPlayToGetScoreList[target];

        return answer;
    }

    public void service() {

        int target = 58;

        int[] answer = solution(target);
        System.out.println(answer[0] + " " + answer[1]);
    }
}
