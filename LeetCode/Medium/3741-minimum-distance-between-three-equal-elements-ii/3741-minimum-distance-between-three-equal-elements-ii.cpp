class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT32_MAX;
        int N = nums.size();

        vector<int> last1(N+1, -1), last2(N+1, -1);

        for(int i = 0; i <N; i++){
            if(last1[nums[i]] != -1){
                ans = min(ans, 2*(i - last1[nums[i]]));
            }

            last1[nums[i]] = last2[nums[i]];
            last2[nums[i]] = i;
        }


        return ans == INT32_MAX ? -1 : ans;
    }
};