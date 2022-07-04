#include "������_��_�����.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

������_��_�����_BEGIN

#define LIMIT 10000000001

vector<string> solution(vector<vector<int>> line) {
    
    // 2���� ��ǥ ��� ���� ���� �ϳ��� �׷� �ִ´ٰ� �����Ѵ�.
    // �׷� ���� �� �̹� �׷��� �ִ� ��� ������� ������ Ȯ���Ѵ�.

    // ������ Ȯ���ϴ� ����� �� 1�� �Լ��� ������ ã�� ����� �̿��Ѵ�.
    // Ax + By + C = 0, Dx + Ey + F �϶�,
    // x = (BF - CE) / (AE - BD), y = (AF - CD) / (BD - AE) �̴�.

    vector<string> answer;
    
    set<pair<long long, long long>> star_s;

    long long min_x = LIMIT, min_y = LIMIT, max_x = -LIMIT, max_y = -LIMIT;

    for (int i = 1; i < line.size(); i++) {

        // Ax + By + C = 0
        long long A = line[i][0], B = line[i][1], C = line[i][2];

        for (int j = 0; j < i; j++) {

            // Dx + Ey + F = 0
            long long D = line[j][0], E = line[j][1], F = line[j][2];

            long long x_numerator = B*F - C*E;
            long long x_denominator = A*E - B*D;
            long long y_numerator = A*F - C*D;
            long long y_denominator = B*D - A*E;

            if (x_denominator == 0 || y_denominator == 0)
                continue;

            // ������ �ƴ� ���
            if (x_numerator % x_denominator != 0 ||
                y_numerator % y_denominator != 0)
                continue;

            long long x = x_numerator / x_denominator;
            long long y = y_numerator / y_denominator;

            if (min_x > x)
                min_x = x;
            if (max_x < x)
                max_x = x;
            if (min_y > y)
                min_y = y;
            if (max_y < y)
                max_y = y;

            star_s.insert({ x, y });

        }
        
    }

    for (long long i = 0; i <= (max_y - min_y); i++) {
        answer.emplace_back(string(max_x - min_x + 1, '.'));
    }

    for (pair<long long, long long> star : star_s) {
        answer[max_y - star.second][star.first - min_x] = '*';
    }


    return answer;
}

void service() {

    vector<vector<int>> l = { {2,-1,4},{-2,-1,4},{0,-1,1},{5,-8,-12},{5,8,12} };
    vector<string> ans = solution(l);
    for (auto a : ans)
        cout << a << endl;
}

������_��_�����_END