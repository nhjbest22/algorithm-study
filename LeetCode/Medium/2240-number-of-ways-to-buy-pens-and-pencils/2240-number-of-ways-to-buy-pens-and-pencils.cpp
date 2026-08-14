class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;

        int cost_max = max(cost1, cost2);
        int cost_min = min(cost1, cost2);

        while(total >= 0){
            ans += total/cost_min + 1;

            total -= cost_max;
        }

        return ans;
    }
};