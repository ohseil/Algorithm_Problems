package Problems._2023_KAKAO_BLIND_RECRUITMENT.택배_배달과_수거하기;

/**
 * 가장 짧은 이동거리로 이동하기 위해서는 가장 멀리 있는 집부터 처리하면 된다.
 * 결국, 어떤 상황에서도 멀리 있는 집을 들러서 언젠간 처리해야 하기 때문에
 * 가장 멀리 있는 집부터 처리해야 가장 멀리 있는 집을 들리는 횟수가 적고 이동 거리도 짧다.
 *
 * 이렇게 가정하고 모든 택배 상자를 배달하고 빈 상자를 회수하는 과정을 생각해 보면,
 * 택배를 물류 창고에서 싣는 개수는 가장 멀리 있는 집부터 차례대로 배달해야 하는 택배 상자 개수를 최대한 싣는다고 생각하면 된다.
 * 가장 멀리 있는 집으로 이동하면서 가장 멀리 배달해야 하는 집에 실었던 상자를 모두 배달하게 되고
 * 가장 멀리 있는 집에 도착했을 때는 비어있는 상태가 된다.
 * 다시 돌아오면서 빈 상자를 회수하는데 이 때도 마찬가지로 가장 멀리에서 회수해야 하는 집부터 차례대로 최대한 회수한다.
 * 이 과정을 반복할 때 가장 멀리 있는 집을 갱신해 주어야 시간 복잡도를 줄일 수 있다.
 * 가장 멀리 있는 집의 기준은 배달해야 할 택배 상자가 남았거나 회수해야 할 상자가 남은 집 중 가장 멀리 있는 집이다.
 */

public class Solution {

    private int deliveryTotal = 0;
    private int pickupTotal = 0;

    public void service() {
        int cap = 4;
        int n = 5;
        int[] deliveries = {1,0,3,1,2};
        int[] pickups = {0,3,0,4,0};

        long answer = solution(cap, n, deliveries, pickups);
        System.out.println(answer);
    }

    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;

        countDeliveryAndPickupTotal(deliveries, pickups);

        int farthestPos = n - 1;

        while(deliveryTotal > 0 || pickupTotal > 0) {

            for (int i = farthestPos; i >= 0; i--) {
                if (deliveries[i] > 0 || pickups[i] > 0) {
                    farthestPos = i;
                    answer += ((i + 1) * 2L);
                    break;
                }
            }

            deliver(deliveries, farthestPos, cap);
            pickup(pickups, farthestPos, cap);
        }
        return answer;
    }

    private void countDeliveryAndPickupTotal(final int[] deliveries, final int[] pickups) {
        for (int deliveryCnt : deliveries) {
            deliveryTotal += deliveryCnt;
        }
        for (int pickupCnt : pickups) {
            pickupTotal += pickupCnt;
        }
    }

    private void deliver(final int[] deliveries, final int farthestPos, final int fullLoadCnt) {
        int loadCnt = fullLoadCnt;

        for (int i = farthestPos; i >= 0; i--) {
            if (deliveries[i] == 0) {
                continue;
            }
            if (loadCnt == 0) {
                break;
            }

            if (loadCnt >= deliveries[i]) {
                loadCnt -= deliveries[i];
                deliveryTotal -= deliveries[i];
                deliveries[i] = 0;
            } else {
                deliveries[i] -= loadCnt;
                deliveryTotal -= loadCnt;
                loadCnt = 0;
            }
        }
    }

    private void pickup(final int[] pickups, final int farthestPos, final int limit) {
        int pickupCnt = 0;

        for (int i = farthestPos; i >= 0; i--) {
            if (pickups[i] == 0) {
                continue;
            }
            if (pickupCnt == limit) {
                break;
            }

            int space = limit - pickupCnt;

            if (space >= pickups[i]) {
                pickupCnt += pickups[i];
                pickupTotal -= pickups[i];
                pickups[i] = 0;
            } else {
                pickups[i] -= space;
                pickupTotal -= space;
                pickupCnt = limit;
            }
        }
    }
}
