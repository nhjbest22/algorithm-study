class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int MIN = 101;
        for(auto p: prices){
            MIN = min(MIN, p);
            ans = max(p - MIN, ans);
        }

        return ans;
    }
};
