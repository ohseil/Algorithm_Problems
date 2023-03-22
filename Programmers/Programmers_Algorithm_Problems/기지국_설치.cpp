#include "기지국_설치.h"
#include <iostream>
#include <vector>

using namespace std;

기지국_설치_BEGIN

void init(vector<int>& stations, int n, int w) {
    
    vector<int> temp = stations;
    
    stations.clear();
    
    stations.push_back(-w);
    
    for (int i = 0; i < temp.size(); i++)
        stations.push_back(temp[i]);
    
    stations.push_back(n + w + 1);
}

int findNeedStationCountBetweenStations(int beforeStationPos, int stationPos, int w) {

    int needStationCount;

    int affectAptCountPerStation = 2 * w + 1;
    int affectedAptCountBetweenStations = 2 * w;
    int aptCountBetweenStations = stationPos - beforeStationPos - 1;
    int unaffectedAptCount;

    if (aptCountBetweenStations <= affectedAptCountBetweenStations)
        return 0;

    unaffectedAptCount = (aptCountBetweenStations - affectedAptCountBetweenStations);
    needStationCount = unaffectedAptCount / affectAptCountPerStation + 1;

    if (unaffectedAptCount % affectAptCountPerStation == 0)
        needStationCount--;
    
    return needStationCount;
}

int solution(int n, vector<int> stations, int w)
{
    // 각 기지국 사이에서 두 기지국의 영향을 받지 않는 아파트의 숫자를 구한다.
    // 하나의 기지국이 최대한 영향을 끼치는 아파트 수는 (2*w+1)개다.
    // 영향을 받지 않는 아파트 수를 (2*w+1)로 나눠서
    // 몇개의 기지국이 필요한지 구해서 더해 나간다.

    // 가장 처음 아파트가 포함 된 범위와 가장 마지막 아파트가 포함 된 범위의 경우,
    // 기지국이 하나만 있기 때문에
    // 쉬운 계산을 위해서 stations 배열의 앞뒤로 기지국 2개를 추가한다.

    int answer = 0;

    init(stations, n, w);

    for (int i = 1; i < stations.size(); i++)
        answer += findNeedStationCountBetweenStations(stations[i - 1], stations[i],  w);

    return answer;
}

void service() {

    int n = 11;
    vector<int> stations = { 4, 11 };
    int w = 1;

    cout << solution(n, stations, w) << endl;
}

기지국_설치_END