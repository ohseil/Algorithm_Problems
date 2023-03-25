package Problems.연습문제.공원_산책;

import java.util.Map;
import java.util.Optional;

public class Solution {

    class Pos {
        final int r;
        final int c;
        Pos(final int r, final int c) {
            this.r = r;
            this.c = c;
        }
    }

    private static final Map<String, int[]> drc = Map.of(
            "N", new int[]{-1,0},
            "S", new int[]{1,0},
            "W", new int[]{0,-1},
            "E", new int[]{0,1}
    );

    private Pos start;

    public void service() {
        final String[] park = {"SOO","OXX","OOO"};
        final String[] routes = {"E 2","S 2","W 1"};

        final int[] answer = solution(park, routes);
        System.out.println(answer[0] + " " + answer[1]);
    }

    public int[] solution(String[] park, String[] routes) {
        int[] answer = {};

        findStartPos(park);

        Pos cur = start;

        for (String route : routes) {
            final String[] tokens = route.split(" ");
            final String direction = tokens[0];
            final int dist = Integer.parseInt(tokens[1]);

            Optional<Pos> next = findNextPos(cur, direction, dist, park);

            if (next.isEmpty()) {
                continue;
            }
            cur = next.get();
        }

        answer = new int[]{cur.r, cur.c};
        return answer;
    }

    private void findStartPos(String[] park) {
        for (int r = 0; r < park.length; r++) {
            for (int c = 0; c < park[0].length(); c++) {
                if (park[r].charAt(c) == 'S') {
                    start = new Pos(r, c);
                    return;
                }
            }
        }
    }

    private Optional<Pos> findNextPos(final Pos cur, final String direction, final int dist, final String[] park) {
        for (int d = 1; d <= dist; d++) {
            if (!validatePos(cur.r + drc.get(direction)[0] * d, cur.c + drc.get(direction)[1] * d, park)) {
                return Optional.empty();
            }
        }
        return Optional.of(new Pos(cur.r + drc.get(direction)[0] * dist, cur.c + drc.get(direction)[1] * dist));
    }

    private boolean validatePos(final int r, final int c, final String[] park) {
        if (r < 0) {
            return false;
        }
        if (c < 0) {
            return false;
        }
        if (r >= park.length) {
            return false;
        }
        if (c >= park[0].length()) {
            return false;
        }
        return park[r].charAt(c) != 'X';
    }
}
