class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        
        int ans = 0;
        int MAX = -1;
        for(int i = N-1; i >=0; i--){
            MAX = max(MAX, prices[i]);
            ans = max(ans, MAX - prices[i]);
        }

        return ans;
    }
};