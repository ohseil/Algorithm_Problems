#include "캐시.h"
#include <iostream>
#include <vector>

using namespace std;

캐시_BEGIN

int solution(int cacheSize, vector<string> cities) {
    
    // 각 city를 처리할 때마다 확인해야할 점은
    // 1. cache hit인지 miss인지 확인이 필요하고
    // 2. miss일때 어느 자리에 저장할 것인지 알아야 한다.

    // cache 배열을 만들어서 저장 된 시간과 도시 이름을 저장한다.
    // 저장 된 시간의 초기 값은 -1이다.

    // city 입력을 처리할 때 시작 시간을 t = 0으로 시작한다.
    // city 하나를 처리할 때마다 t는 1씩 증가한다.
    
    // city 하나 처리할때마다 cache를 한번 순회한다.
    // 순회하면서 위의 확인 필요 내용들을 확인한다.
    // 도시 이름이 일치하는지 확읺해서 cache hit인지 miss인지 확인하고,
    // miss일 경우를 대비해서 가장 접근한 시간이 오래된 시간의 자리를 찾는다.
    // 오래된 시간의 의미는 가장 작은 값을 의미한다.

    // cache에 저장할 때는 t와 city 문자열을 저장한다.
    // 대소문자 구분이 없으므로 각 city의 문자열을 모두 소문자로 바꿔서 계산한다.

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

캐시_END