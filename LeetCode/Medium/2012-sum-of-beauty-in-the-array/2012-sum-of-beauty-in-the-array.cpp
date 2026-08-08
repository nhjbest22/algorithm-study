class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N, 0), suffix(N, 0);
        vector<int> state(N, 0);

        // prefix -> MAX, suffix -> MIN

        prefix[0] = nums[0];
        for(int i = 1; i < N; i++)
            prefix[i] = max(nums[i], prefix[i-1]);
        
        suffix[N-1] = nums[N-1];
        for(int i = N-2; i>=0; i--)
            suffix[i] = min(nums[i], suffix[i+1]);

        for(int i = 1; i < N-1; i++){
            int& num = nums[i];

            if(num > prefix[i-1] && num < suffix[i+1]){
                state[i] = 2;
                continue;
            }

            if(num > nums[i-1] && num < nums[i+1])
                state[i] = 1;
        }

        int ans = accumulate(state.begin(), state.end(), 0);
        return ans;
    }
};