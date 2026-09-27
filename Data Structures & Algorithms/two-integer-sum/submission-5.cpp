class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();

        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; i++)
            v[i] = {nums[i], i};
        
        sort(v.begin(), v.end());

        for(auto& [num, idx]: v){
            auto it = lower_bound(v.begin(), v.end(), make_pair(target - num, idx + 1));
            int ptr = it - v.begin();

            if(ptr == N || it->second == idx) continue;
            if(it->first != target - num) continue;

            return {idx, it->second};
        }

        return {0, 0};
    }
};
