class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int offset = 1000;
        vector<int> cnt (2005, 0);

        for(auto num: nums){
            cnt[num + offset]++;
        }

        vector<pair<int, int>> v;
        for(int i = 0; i < 2005; i++){
            if(!cnt[i]) continue;

            v.push_back({cnt[i], i - offset});
        }

        sort(v.begin(), v.end(), greater<>());

        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = v[i].second;

        return ans;
    }
};
