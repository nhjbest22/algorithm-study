class Solution {
public:
    int findMin(vector<int> &nums) {
        int N = nums.size();

        int yes = 0, no = N;

        while(yes + 1 < no){
            int mid = (yes + no)/2;

            if(nums[mid] >= nums[yes]) yes = mid;
            else no = mid;
        }

        yes = yes == N-1 ? 0 : yes + 1;

        return nums[yes];
    }
};
