class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int N = nums.size();
        int ans = 0;
        vector<int> suffix(N, 0);

        suffix[N-1] = nums[N-1];
        for(int i = N-2; i>=0; i--)
            suffix[i] = min(nums[i], suffix[i+1]);

        int left_max = nums[0];
        for(int i = 1; i < N-1; i++){
            left_max = max(left_max, nums[i-1]);
            int& num = nums[i];

            if(num > left_max && num < suffix[i+1]){
                ans += 2;
                continue;
            }

            if(num > nums[i-1] && num < nums[i+1])
                ans += 1;
        }
        
        return ans;
    }
};