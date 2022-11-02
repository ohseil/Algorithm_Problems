package Problems.Summer_Winter_Coding_to_2018.방문_길이;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class Solution {

    final int MIN_POS = -5;
    final int MAX_POS = 5;

    class Pos {
        int x;
        int y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pos pos = (Pos) o;
            return x == pos.x && y == pos.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }
    }

    class Route {

        Pos from;
        Pos to;

        Route(Pos from, Pos to) {
            if (from.x < to.x) {
                this.from = from;
                this.to = to;
            }
            else if (from.x == to.x) {
                if (from.y < to.y) {
                    this.from = from;
                    this.to = to;
                }
                else {
                    this.from = to;
                    this.to = from;
                }
            }
            else {
                this.from = to;
                this.to = from;
            }
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Route route = (Route) o;
            return Objects.equals(from, route.from) && Objects.equals(to, route.to);
        }

        @Override
        public int hashCode() {
            return Objects.hash(from, to);
        }
    }

    Set<Route> visitedRoutes = new HashSet<>();

    Pos move(Pos from, char dir) {
        if (dir == 'U') return new Pos(from.x, from.y + 1);
        if (dir == 'D') return new Pos(from.x, from.y - 1);
        if (dir == 'R') return new Pos(from.x + 1, from.y);
        if (dir == 'L') return new Pos(from.x - 1, from.y);
        return from;
    }

    boolean isCoordinatePlaneRange(Pos pos) {
        return (MIN_POS <= pos.x && pos.x <= MAX_POS)
                && (MIN_POS <= pos.y && pos.y <= MAX_POS);
    }

    public int solution(String dirs) {

        // 이동할때마다 경로를 set에 저장한다.
        // set은 중복을 허용하지 않는 특성이 있다.
        // 경로는 시작 점과 끝점으로 구성한다.
        // 또한 구성할 때, 정렬해서 순서대로 시작점, 끝점을 구성한다.

        // 이동이 끝난 후에 set의 크기가 답이다.

        int answer = 0;

        Pos pos = new Pos(0, 0);

        for (char dir : dirs.toCharArray()) {

            Pos nextPos = move(pos, dir);

            if (isCoordinatePlaneRange(nextPos) == false)
                continue;

            Route route = new Route(pos, nextPos);
            visitedRoutes.add(route);
            pos = nextPos;
        }

        answer = visitedRoutes.size();

        return answer;
    }

    public void service() {

        String dirs = "ULURRDLLU";
        int answer = solution(dirs);

        System.out.println(answer);
    }
}
