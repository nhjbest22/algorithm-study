class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int MAX = *max_element(nums.begin(), nums.end());

        int N = nums.size();
        long long ans = 0;

        vector<int> v_max(100'005);

        int idx = 0;
        for(int i = 0; i < N; i++){
            if(nums[i] == MAX)
                v_max[idx++] = i;
        }

        if(idx < k) return 0;

        int prev = -1;

        for(int i = v_max[k-1]; i < N; i++){
            if(nums[i] == MAX)
                prev++;

            ans += (v_max[prev] + 1);
        }

        return ans;
    }
};