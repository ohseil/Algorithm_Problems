package Problems.연습문제.바탕화면_정리;

public class Solution {

    public void service() {
        final String[] wallpaper = {".#...", "..#..", "...#."};

        final int[] answer = solution(wallpaper);
        for (int a : answer) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    public int[] solution(final String[] wallpaper) {
        final int maxX = wallpaper.length;
        final int maxY = wallpaper[0].length();
        final int[] answer = new int[]{maxX, maxY, 0, 0};

        for (int x = 0; x < maxX; x++) {
            for (int y = 0; y < maxY; y++) {
                if (wallpaper[x].charAt(y) == '#') {
                    if (answer[0] > x) {
                        answer[0] = x;
                    }
                    if (answer[1] > y) {
                        answer[1] = y;
                    }
                    if (answer[2] < x + 1) {
                        answer[2] = x + 1;
                    }
                    if (answer[3] < y + 1) {
                        answer[3] = y + 1;
                    }
                }
            }
        }
        return answer;
    }
}
