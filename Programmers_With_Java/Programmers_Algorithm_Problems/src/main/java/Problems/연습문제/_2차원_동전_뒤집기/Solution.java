package Problems.연습문제._2차원_동전_뒤집기;

public class Solution {

    private final int LIMIT_NUM_OF_FLIPS = 101;

    private class Board {

        int[][] board;
        int nextRowFlipIdx;
        int nextColFlipIdx;
        int numOfFlips;

        Board(int[][] board, int nextRowFlipIdx, int nextColFlipIdx, int numOfFlips) {
            this.board = board;
            this.nextRowFlipIdx = nextRowFlipIdx;
            this.nextColFlipIdx = nextColFlipIdx;
            this.numOfFlips = numOfFlips;
        }

        void flipInRow(int row) {

            for (int col = 0; col < maxC; col++) {
                if (board[row][col] == 1) board[row][col] = 0;
                else board[row][col] = 1;
            }

            nextRowFlipIdx = row + 1;
            numOfFlips++;

        }

        void flipInCol(int col) {

            for (int row = 0; row < maxR; row++) {
                if (board[row][col] == 1) board[row][col] = 0;
                else board[row][col] = 1;
            }

            nextColFlipIdx = col + 1;
            numOfFlips++;

        }

        boolean hasSameBoad(int[][] comparingBoard) {

            for (int r = 0; r < maxR; r++)
                for (int c = 0; c < maxC; c++)
                    if (board[r][c] != comparingBoard[r][c])
                        return false;

            return true;
        }

    }

    private int maxR;
    private int maxC;

    private void init(final int[][] board) {
        maxR = board.length;
        maxC = board[0].length;
    }

    Board createBoardClone(final Board board) {

        int[][] cloningBoard = board.board;
        int[][] newBoard = new int[cloningBoard.length][];

        for (int i = 0; i < cloningBoard.length; i++)
            newBoard[i] = cloningBoard[i].clone();

        return new Board(newBoard, board.nextRowFlipIdx, board.nextColFlipIdx, board.numOfFlips);
    }

    private int findMinNumOfColFlips(Board board, int[][] target) {

        if (board.hasSameBoad(target) == true)
            return board.numOfFlips;

        int minNumOfColFlips = LIMIT_NUM_OF_FLIPS;

        for (int flippingCol = board.nextColFlipIdx; flippingCol < maxC; flippingCol++) {

            Board flippedColBoard = createBoardClone(board);
            flippedColBoard.flipInCol(flippingCol);

            int numOfColFlips = findMinNumOfColFlips(flippedColBoard, target);

            if (numOfColFlips < minNumOfColFlips)
                minNumOfColFlips = numOfColFlips;

        }

        return minNumOfColFlips;
    }

    private int findMinNumOfFlips(Board board, int[][] target) {

        if (board.hasSameBoad(target) == true)
            return board.numOfFlips;

        int minNumOfRowFlips = LIMIT_NUM_OF_FLIPS;
        int minNumOfColFlips;

        for (int flippingRow = board.nextRowFlipIdx; flippingRow < maxR; flippingRow++) {

            Board flippedRowBoard = createBoardClone(board);
            flippedRowBoard.flipInRow(flippingRow);

            int numOfRowFlips = findMinNumOfFlips(flippedRowBoard, target);

            if (numOfRowFlips < minNumOfRowFlips)
                minNumOfRowFlips = numOfRowFlips;

        }

        minNumOfColFlips = findMinNumOfColFlips(board, target);

        if (minNumOfRowFlips < minNumOfColFlips) return minNumOfRowFlips;
        else return minNumOfColFlips;
    }


    public int solution(int[][] beginning, int[][] target) {

        /*

            각 row와 col은 flip하거나 안하거나 2가지 상태만 가능하다.
            각 coin의 상태를 생각해 보면, 순서와 상관 없이 coin이 포함된 row와 col의 flip 상태에 따라 정해진다.

            결국, 모든 경우를 생각해 보는 방식으로 해결했다.
            row와 col의 수는 최대 10개씩 밖에 안되기 때문에 가능하다.

            row 1개 flip하는 경우 -> 10C1가지
            row 2개 flip하는 경우 -> 10C2가지
            .
            .
            row 10개 flip하는 경우 -> 10C10가지

            row만 생각했을 때 flip할 수 있는 가지 수는 위의 경우를 모두 합 한 수다.

            그리고 각 경우마다 col을 flip하는 모든 경우를 생각한다.
            col을 flip하는 경우도 row와 같다.

            결국 가지 수는 ( 10C1 + 10C2 + .. + 10C10 ) * ( 10C1 + 10C2 + .. + 10C10 ) 가지가 된다.

            재귀 함수로 작성했다.

         */

        int answer = 0;
        Board beginBoard;

        init(beginning);

        beginBoard = new Board(beginning, 0, 0, 0);
        answer = findMinNumOfFlips(beginBoard, target);

        if (answer == LIMIT_NUM_OF_FLIPS)
            answer = -1;

        return answer;
    }

    public void service() {

        int[][] beginning = {{0,1,0,0,0},{1,0,1,0,1},{0,1,1,1,0},{1,0,1,1,0},{0,1,0,1,0}};
        int[][] target = {{0,0,0,1,1},{0,0,0,0,1},{0,0,1,0,1},{0,0,0,1,0},{0,0,0,0,1}};

        int answer = solution(beginning, target);
        System.out.println(answer);
    }

}
