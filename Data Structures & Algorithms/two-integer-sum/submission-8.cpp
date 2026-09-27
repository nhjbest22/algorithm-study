class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<pair<int, int>> v(N);
        
        for(int i = 0; i < N; i++) v[i] = {nums[i], i};
        sort(v.begin(), v.end());

        int l = 0, r = N-1;

        while(l < r){
            int sum = v[l].first + v[r].first;

            if(sum == target) return {min(v[l].second, v[r].second), max(v[l].second, v[r].second)};

            if(sum > target) r--;
            else l++;
        }

        return {0, 0};
    }
};
