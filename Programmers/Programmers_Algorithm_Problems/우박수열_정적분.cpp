#include "우박수열_정적분.h"
#include <iostream>
#include <vector>

using namespace std;

우박수열_정적분_BEGIN

vector<double> definiteIntegralAreas;

class Pos {
public:
    int x;
    int y;
    Pos(int x, int y) : x(x), y(y) {}
};

double calculateAreaInRange(Pos smallYPos, Pos bigYPos) {
    
    double xDif = abs(bigYPos.x - smallYPos.x);
    double yDif = bigYPos.y - smallYPos.y;
    
    return (xDif * smallYPos.y) + (xDif * yDif / 2);
}

void findDefiniteIntegralsInHailstormSequence(int num) {

    int x = 1;

    while (num != 1) {

        int nextNum;
        int nextX = x + 1;

        double area;

        if (num % 2 == 0) {
            nextNum = num / 2;
            area = calculateAreaInRange(Pos(x, num), Pos(nextX, nextNum));
        }
        else {
            nextNum = num * 3 + 1;
            area = calculateAreaInRange(Pos(nextX, nextNum), Pos(x, num));
        }

        definiteIntegralAreas.push_back(area);

        num = nextNum;
        x = nextX;
    }
}

double findAreaInRange(int start, int end) {

    double totalArea = 0;

    for (int i = start; i <= end; i++)
        totalArea += definiteIntegralAreas[i];

    return totalArea;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    
    // 우박 수열을 계산하면서 각 x마다
    // x ~ x+1 범위의 정적분 영역을 계산해서 배열에 저장한다.
    // 각 입력 범위마다 저장된 영역의 배열을 확인해서 넓이들을 더해서 계산한다.

    vector<double> answer;
    
    findDefiniteIntegralsInHailstormSequence(k);

    for (vector<int> range : ranges) {
        
        int start = range[0];
        int end = definiteIntegralAreas.size() + range[1];

        if (start == end) {
            answer.push_back(0);
            continue;
        }

        if (start > end) {
            answer.push_back(-1);
            continue;
        }

        // 저장된 각 영역의 넓이는 범위의 작은 x값을 기준으로 저장되어 있기 때문에
        // 조건 확인 후 마지막 범위의 작은 x값으로 변경해 준다.
        end--;

        answer.push_back(findAreaInRange(start, end));
    }

    return answer;
}

void service() {

    int k = 5;
    vector<vector<int>> ranges = { {0,0},{0,-1},{2,-3},{3,-3} };

    vector<double> answer = solution(k, ranges);
    for (auto a : answer)
        cout << a << " ";
    cout << endl;
}

우박수열_정적분_END