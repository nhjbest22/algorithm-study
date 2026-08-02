class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT32_MAX;
        int N = nums.size();

        vector<int> v1(N+ 5, -1), v2(N+5, -1);

        for(int i = 0; i < N; i++){
            int& num = nums[i];
            
            if(v1[num] != -1)
                ans = min(ans, 2*(i - v1[num]));
            
            v1[num] = v2[num];
            v2[num] = i;
        }

        return ans == INT32_MAX ? -1 : ans;
    }
};