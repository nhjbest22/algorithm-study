class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cur = 0;
        int N = nums.size();
        int MAX = -1;
        int op = 0;

        for(int i = 0; i < N; i++){
            if(nums[i] >= MAX){
                MAX = nums[i]; 
                continue;
            }

            nums[i] = MAX;
            op++;
        }

        return N - op;
    }
};