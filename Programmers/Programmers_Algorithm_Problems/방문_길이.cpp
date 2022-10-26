#include "방문_길이.h"
#include <iostream>
#include <set>

using  namespace std;

방문_길이_BEGIN

#define MAX_POS 5
#define MIN_POS -5

struct Pos {
    int x;
    int y;
    Pos(int x, int y) : x(x), y(y) {}
};

struct Route {

    Pos from;
    Pos to;
    
    Route(Pos f, Pos t) : from(f), to(t) {
        if (from.x > to.x)
            swap(from, to);
        else if (from.x == to.x)
            if (from.y > to.y)
                swap(from, to);
    }
    
    bool operator<(const Route& route) const {
        if (from.x < route.from.x) return true;
        else if (from.x == route.from.x)
            if (from.y < route.from.y) return true;
            else if (from.y == route.from.y)
                if (to.x < route.to.x) return true;
                else if (to.x == route.to.x)
                    if (to.y < route.to.y) return true;
        return false;
    }
};

bool isCoordinatePlaneRange(Pos pos) {
    return (MIN_POS <= pos.x && pos.x <= MAX_POS) 
        && (MIN_POS <= pos.y && pos.y <= MAX_POS);
}

Pos move(Pos from, char dir) {
    if (dir == 'U') return Pos(from.x, from.y + 1);
    if (dir == 'D') return Pos(from.x, from.y - 1);
    if (dir == 'R') return Pos(from.x + 1, from.y);
    if (dir == 'L') return Pos(from.x - 1, from.y);
}

int solution(string dirs) {
    
    // 이동할때마다 경로를 set에 저장한다.
    // set은 중복을 허용하지 않는 특성이 있다.
    // 경로는 시작 점과 끝점으로 구성한다.
    // 또한 구성할 때, 정렬해서 순서대로 시작점, 끝점을 구성한다.

    // 이동이 끝난 후에 set의 크기가 답이다.

    int answer = 0;
    
    set<Route> visitedRoutes;

    Pos pos(0, 0);

    for (char dir : dirs) {

        Pos nextPos = move(pos, dir);

        if (isCoordinatePlaneRange(nextPos) == false)
            continue;

        Route route(pos, nextPos);
        visitedRoutes.insert(route);
        pos = nextPos;
    }

    answer = visitedRoutes.size();

    return answer;
}

void service() {
    
    string dirs = "ULURRDLLU";

    cout << solution(dirs) << endl;
}

방문_길이_END