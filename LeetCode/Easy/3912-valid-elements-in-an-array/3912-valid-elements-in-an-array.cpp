class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> suffix(N, 0), prefix(N, 0);
        vector<int> ans;

        prefix[0] = nums[0];
        suffix[N-1] = nums[N-1];

        for(int i = 1; i < N; i++)
            prefix[i] = max(prefix[i-1], nums[i]);
        
        for(int i = N-2; i>= 0; i--)
            suffix[i] = max(suffix[i+1], nums[i]);
        
        for(int i = 0; i < N; i++){
            if(i == 0 || i == N-1){
                ans.push_back(nums[i]);
                continue;
            }

            if(nums[i] > prefix[i-1] || nums[i] > suffix[i+1])
                ans.push_back(nums[i]);
            
        }

        return ans;
    }
};