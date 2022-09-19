#include "ĳ��.h"
#include <iostream>
#include <vector>

using namespace std;

ĳ��_BEGIN

int solution(int cacheSize, vector<string> cities) {
    
    // �� city�� ó���� ������ Ȯ���ؾ��� ����
    // 1. cache hit���� miss���� Ȯ���� �ʿ��ϰ�
    // 2. miss�϶� ��� �ڸ��� ������ ������ �˾ƾ� �Ѵ�.

    // cache �迭�� ���� ���� �� �ð��� ���� �̸��� �����Ѵ�.
    // ���� �� �ð��� �ʱ� ���� -1�̴�.

    // city �Է��� ó���� �� ���� �ð��� t = 0���� �����Ѵ�.
    // city �ϳ��� ó���� ������ t�� 1�� �����Ѵ�.
    
    // city �ϳ� ó���Ҷ����� cache�� �ѹ� ��ȸ�Ѵ�.
    // ��ȸ�ϸ鼭 ���� Ȯ�� �ʿ� ������� Ȯ���Ѵ�.
    // ���� �̸��� ��ġ�ϴ��� Ȯ���ؼ� cache hit���� miss���� Ȯ���ϰ�,
    // miss�� ��츦 ����ؼ� ���� ������ �ð��� ������ �ð��� �ڸ��� ã�´�.
    // ������ �ð��� �ǹ̴� ���� ���� ���� �ǹ��Ѵ�.

    // cache�� ������ ���� t�� city ���ڿ��� �����Ѵ�.
    // ��ҹ��� ������ �����Ƿ� �� city�� ���ڿ��� ��� �ҹ��ڷ� �ٲ㼭 ����Ѵ�.

    if (cacheSize == 0)
        return cities.size() * 5;

    int answer = 0;

    vector<pair<int, string>> cache(cacheSize, { -1, "" });

    int t = 0;

    for (string city : cities) {

        for (int i = 0; i < city.length(); i++)
            city[i] = tolower(city[i]);

        int oldestTimeLastUsed = 100000;
        int spaceIdx = -1;

        bool isCacheHit = false;
    
        for (int i = 0; i < cacheSize; i++) {
            
            if (cache[i].second == city) {
                isCacheHit = true;
                spaceIdx = i;
                break;
            }

            if (cache[i].first < oldestTimeLastUsed) {
                oldestTimeLastUsed = cache[i].first;
                spaceIdx = i;
            }
        }

        if (isCacheHit == true) {
            cache[spaceIdx].first = t;
            answer += 1;
        }
        else {
            cache[spaceIdx] = { t, city };
            answer += 5;
        }

        t++;
    }

    return answer;
}

void service() {

    int cacheSize = 3;
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    cout << solution(cacheSize, cities) << endl;
}

ĳ��_END