#include "�湮_����.h"
#include <iostream>
#include <set>

using  namespace std;

�湮_����_BEGIN

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
    
    // �̵��Ҷ����� ��θ� set�� �����Ѵ�.
    // set�� �ߺ��� ������� �ʴ� Ư���� �ִ�.
    // ��δ� ���� ���� �������� �����Ѵ�.
    // ���� ������ ��, �����ؼ� ������� ������, ������ �����Ѵ�.

    // �̵��� ���� �Ŀ� set�� ũ�Ⱑ ���̴�.

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

�湮_����_END