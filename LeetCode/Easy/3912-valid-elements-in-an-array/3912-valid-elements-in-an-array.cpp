class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> suffix(N, 0);
        vector<int> ans;

        suffix[N-1] = nums[N-1];
        for(int i = N-2; i>= 0; i--)
            suffix[i] = max(suffix[i+1], nums[i]);

        int MAX = -1;
        
        for(int i = 0; i < N; i++){
            if(i == 0 || i == N-1){
                ans.push_back(nums[i]);
                MAX = max(nums[i], MAX);

                continue;
            }


            if(MAX < nums[i] || nums[i] > suffix[i+1])
                ans.push_back(nums[i]);
            
            MAX = max(MAX, nums[i]);
        }

        return ans;
    }
};