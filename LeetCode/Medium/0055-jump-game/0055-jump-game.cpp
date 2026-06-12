class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool check[100'005];
        fill(check, check + 100'005, false);

        int N = nums.size();
        check[0] = true;

        for(int i = 0; i < N; i++){
            if(check[i] == false) continue;
            
            int cur = nums[i];
            for(int j = 0; j <= cur && j + i < N; j++){
                check[i+j] = true;

            }
        }

        return check[N-1];
    }
};