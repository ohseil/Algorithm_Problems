#include "��ڼ���_������.h"
#include <iostream>
#include <vector>

using namespace std;

��ڼ���_������_BEGIN

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
    
    // ��� ������ ����ϸ鼭 �� x����
    // x ~ x+1 ������ ������ ������ ����ؼ� �迭�� �����Ѵ�.
    // �� �Է� �������� ����� ������ �迭�� Ȯ���ؼ� ���̵��� ���ؼ� ����Ѵ�.

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

        // ����� �� ������ ���̴� ������ ���� x���� �������� ����Ǿ� �ֱ� ������
        // ���� Ȯ�� �� ������ ������ ���� x������ ������ �ش�.
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

��ڼ���_������_END