#include "������_��ġ.h"
#include <iostream>
#include <vector>

using namespace std;

������_��ġ_BEGIN

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
    // �� ������ ���̿��� �� �������� ������ ���� �ʴ� ����Ʈ�� ���ڸ� ���Ѵ�.
    // �ϳ��� �������� �ִ��� ������ ��ġ�� ����Ʈ ���� (2*w+1)����.
    // ������ ���� �ʴ� ����Ʈ ���� (2*w+1)�� ������
    // ��� �������� �ʿ����� ���ؼ� ���� ������.

    // ���� ó�� ����Ʈ�� ���� �� ������ ���� ������ ����Ʈ�� ���� �� ������ ���,
    // �������� �ϳ��� �ֱ� ������
    // ���� ����� ���ؼ� stations �迭�� �յڷ� ������ 2���� �߰��Ѵ�.

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

������_��ġ_END