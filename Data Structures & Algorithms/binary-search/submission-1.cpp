class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();

        int yes = N, no = -1;
        // 1, 1, 1 -> 100
        // 100, 100, 100 -> 1
        // 1, 1, 1 -> 1

        // target >= arr[mid] 의 최소 index

        while(no + 1 < yes){
            int mid = (yes + no) / 2;

            if(nums[mid] >= target) yes = mid;
            else no = mid;
        }

        return (yes == N || nums[yes] != target ? -1 : yes);
    }
};
