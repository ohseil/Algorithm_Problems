package Problems._2022_KAKAO_BLIND_RECRUITMENT.신고_결과_받기;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*

    문제를 해결하기 위해 얻어야 할 정보는 총 3가지다.

    1. id가 신고한 id 리스트

        HashMap을 사용했고, value로 신고한 id 리스트를 저장하기 위해 HashSet을 사용했다.
        HashSet을 사용한 이유는 중복을 확인하기 위해서다.

    2. id가 신고된 횟수

        HashMap을 사용했고, 중복 신고가 아닌 경우에만 횟수를 세었다.

 */

public class Solution {

    private Map<String, Set<String>> reportedIdMap;
    private Map<String, Integer> numOfReportedMap;

    public void service() {

        String[] id_list = {"muzi", "frodo", "apeach", "neo"};
        String[] reports = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
        int k = 2;

        int[] answer = solution(id_list, reports, k);
        for (int a : answer)
            System.out.print(a + " ");

    }

    public int[] solution(String[] id_list, String[] report, int k) {

        int[] answer = new int[id_list.length];

        init();
        makeMapFromReportInform(report);

        for (int i = 0; i < id_list.length; i++) {

            String id = id_list[i];

            answer[i] = findNumOfEmails(id, k);

        }

        return answer;
    }

    private void init() {
        reportedIdMap = new HashMap<>();
        numOfReportedMap = new HashMap<>();
    }

    private void makeMapFromReportInform(final String[] reportList) {

        for (String report : reportList) {

            String[] tokens = report.split(" ");

            String reportingId = tokens[0];
            String reportedId = tokens[1];

            Set<String> reportedIdSet = reportedIdMap.getOrDefault(reportingId, new HashSet<>());

            if (reportedIdSet.contains(reportedId) == true)
                continue;

            reportedIdSet.add(reportedId);
            reportedIdMap.put(reportingId, reportedIdSet);
            numOfReportedMap.put(reportedId, numOfReportedMap.getOrDefault(reportedId, 0) + 1);

        }

    }

    private int findNumOfEmails(final String id, final int limitNumOfReport) {

        if (reportedIdMap.containsKey(id) == false)
            return 0;

        int numOfEmails = 0;

        for (String reportedId : reportedIdMap.get(id)) {

            int numOfReported = numOfReportedMap.get(reportedId);

            if (numOfReported >= limitNumOfReport)
                numOfEmails++;

        }

        return numOfEmails;
    }

}
