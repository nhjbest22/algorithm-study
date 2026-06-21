class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int> ans(prices.begin(), prices.end());

        for(int i = 0; i <N; i++){
            int cur = prices[i];
            for(int j = i+1; j < N; j++){
                if(cur >= prices[j]){
                    ans[i] -= prices[j];
                    break;
                }
            }
        }

        return ans;
    }
};