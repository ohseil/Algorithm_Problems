package Problems.연습문제.혼자서_하는_틱택토;

/**
 * 규칙을 어겼는지에 대한 조건은 크게 2가지가 있다.
 *
 * 1. O의 개수와 X의 개수를 비교하면 잘못 표시한 경우를 확인할 수 있다.
 * 2. 3개가 일치하는 경우들에 대해 확인한다. 3개가 일치하는 경우를 정답이라고 하자.
 * 2-1. 정답의 개수가 3개 이상이면 무조건 게임이 끝난 후에 표시한 것이다.
 * 2-2. 정답의 개수가 2개이면 몇 가지 조건을 더 확인해야 한다.
 * 2-2-1. 2개인데 정답을 위해 표시한 칸의 개수가 6개이면 무조건 게임이 끝난 후에 표시한 것이다.
 * 2-2-2. 2개인데 정답을 위해 표시한 칸의 개수가 5개이면 겹치는 칸이 있으므로 마지막에 표시한 경우의 조건을 확인한다.
 *        1번 규칙에서의 계산으로 마지막에 'O' 차례인지 'X' 차례인지 알 수 있다.
 *        정답을 위해 표시한 문자와 마지막 차례인 문자와 같으면 정상적으로 만들어질 수 있는 상황이 된다.
 *        같지 않으면 무조건 게임이 끝난 후에 표시한 것이다.
 * 2-3. 정답의 개수가 1개일 때도 2개일 때와 마찬가지로 마지막에 표시한 문자를 확인한다.
 */

public class Solution {

    private final int[][] answerMarkMap = new int[3][3];

    private int answerCnt = 0;
    private int answerMarkCnt = 0;
    private char lastAnswerMark = '?';
    private boolean isLastTurnO = false;

    public void service() {
        final String[] board = {"O.X", ".O.", "..X"};

        final int answer = solution(board);
        System.out.println(answer);
    }

    public int solution(String[] board) {
        int answer = 1;

        if (!isValidMarkCnt(board) || !isValidAnswerCnt(board)) {
            answer = 0;
        }
        return answer;
    }

    private boolean isValidMarkCnt(final String[] board) {
        int oCnt = 0;
        int xCnt = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'O') {
                    oCnt++;
                } else if (board[i].charAt(j) == 'X') {
                    xCnt++;
                }
            }
        }

        if (!((xCnt == oCnt) || (oCnt == xCnt + 1))) {
            return false;
        }
        if (oCnt == xCnt + 1) {
            isLastTurnO = true;
        }
        return true;
    }

    private boolean isValidAnswerCnt(final String[] board) {
        for (int i = 0; i < 3; i++) {
            // 가로
            findAnswer(i, 0, i, 1, i, 2, board);
            // 세로
            findAnswer(0, i, 1, i, 2, i, board);
        }
        // 대각선
        findAnswer(0,0, 1,1, 2,2, board);
        findAnswer(0,2, 1,1, 2,0, board);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (answerMarkMap[i][j] == 1) {
                    answerMarkCnt++;
                }
            }
        }

        if (answerCnt > 2) {
            return false;
        }
        if (answerCnt >= 1) {
            if (isLastTurnO && lastAnswerMark == 'X') {
                return false;
            } else if (!isLastTurnO && lastAnswerMark == 'O') {
                return false;
            }
        }
        if (answerCnt == 2) {
            if (answerMarkCnt == 6) {
                return false;
            }
        }
        return true;
    }

    private void findAnswer(int r1, int c1, int r2, int c2, int r3, int c3, String[] board) {
        if (board[r1].charAt(c1) != '.' &&
                board[r1].charAt(c1) == board[r2].charAt(c2) &&
                board[r2].charAt(c2) == board[r3].charAt(c3)) {
            answerMarkMap[r1][c1] = answerMarkMap[r2][c2] = answerMarkMap[r3][c3] = 1;
            lastAnswerMark = board[r1].charAt(c1);
            answerCnt++;
        }
    }
}
