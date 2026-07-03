class Solution {
public:
    bool check(vector<int>& nums, int mid){
        auto it = lower_bound(nums.begin(), nums.end(), mid);

        return nums.end() - it >= mid;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // TTTTTFFFFF
        // x 이상인 수가 x 이상개 존재해야 함.

        int yes = 0, no = 1'001;
        while(yes + 1 < no){
            int mid = (yes + no)/2;

            if(check(nums, mid)) yes = mid;
            else no = mid;
        }

        auto it = lower_bound(nums.begin(), nums.end(), yes);

        return nums.end() - it == yes ? yes : -1;
    }
};