class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;

        int full = numBottles, empty = 0;
        while(full){
            ans += full;

            empty += full;
            full = 0;

            full += empty / numExchange;
            empty = empty % numExchange;
        }

        return ans;
    }
};