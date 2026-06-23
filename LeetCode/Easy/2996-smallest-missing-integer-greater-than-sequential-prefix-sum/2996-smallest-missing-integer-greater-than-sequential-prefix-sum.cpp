class Solution {
public:
    int missingInteger(vector<int>& nums) {
        bool isExist[55];
        fill(isExist, isExist + 55, false);

        int N = nums.size();
        for(int i = 0; i < N; i++)
            isExist[nums[i]] = true;

        int sum = nums[0];
        for(int i = 1; i < N; i++){
            if(nums[i] != nums[i-1] + 1) break;

            sum += nums[i];
        }

        if(sum > 50) return sum;

        while(1){
            if(!isExist[sum]) break;
            
            sum++;
        }

        return sum;
    }
};