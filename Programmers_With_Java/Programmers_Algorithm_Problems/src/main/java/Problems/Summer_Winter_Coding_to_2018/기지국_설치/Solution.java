package Problems.Summer_Winter_Coding_to_2018.기지국_설치;

public class Solution {

    int[] addedStations;

    void init(int n, int[] stations, int w) {

        addedStations = new int[stations.length + 2];

        addedStations[0] = -w;

        for (int i = 0; i < stations.length; i++)
            addedStations[i + 1] = stations[i];

        addedStations[addedStations.length - 1] = n + w + 1;
    }

    int findNeedStationCountBetweenStations(int beforeStationPos, int stationPos, int w) {

        int needStationCount;

        int affectAptCountPerStation = 2 * w + 1;
        int affectedAptCountBetweenStations = 2 * w;
        int aptCountBetweenStations = stationPos - beforeStationPos - 1;
        int unaffectedAptCountBetweenStations;

        if (aptCountBetweenStations <= affectedAptCountBetweenStations)
            return 0;

        unaffectedAptCountBetweenStations = (aptCountBetweenStations - affectedAptCountBetweenStations);
        needStationCount = unaffectedAptCountBetweenStations / affectAptCountPerStation + 1;

        if (unaffectedAptCountBetweenStations % affectAptCountPerStation == 0)
            needStationCount--;

        return needStationCount;
    }

    public int solution(int n, int[] stations, int w) {

        // 각 기지국 사이에서 두 기지국의 영향을 받지 않는 아파트의 숫자를 구한다.
        // 하나의 기지국이 최대한 영향을 끼치는 아파트 수는 (2*w+1)개다.
        // 영향을 받지 않는 아파트 수를 (2*w+1)로 나눠서
        // 몇개의 기지국이 필요한지 구해서 더해 나간다.

        // 가장 처음 아파트가 포함 된 범위와 가장 마지막 아파트가 포함 된 범위의 경우,
        // 기지국이 하나만 있기 때문에
        // 쉬운 계산을 위해서 stations 배열의 앞뒤로 기지국 2개를 추가한다.

        int answer = 0;

        init(n, stations, w);

        for (int i = 1; i < addedStations.length; i++)
            answer += findNeedStationCountBetweenStations(addedStations[i - 1], addedStations[i], w);

        return answer;
    }

    public void service() {

        int n = 11;
        int[] stations = {4, 11};
        int w = 1;

        int answer = solution(n, stations, w);
        System.out.println(answer);
    }
}
