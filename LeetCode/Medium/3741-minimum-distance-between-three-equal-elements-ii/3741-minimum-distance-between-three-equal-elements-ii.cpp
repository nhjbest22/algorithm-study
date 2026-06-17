class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<pair<int, int>> v;
        int ans = INT32_MAX;
        int N = nums.size();

        for(int i = 0; i < N; i++)
            v.push_back({nums[i], i});
        
        sort(v.begin(), v.end());

        for(int i = 2; i < N; i++){
            if(v[i].first != v[i-2].first) continue;

            ans = min(ans, 2*(v[i].second - v[i-2].second));
        }

        return ans == INT32_MAX ? -1 : ans;
    }
};