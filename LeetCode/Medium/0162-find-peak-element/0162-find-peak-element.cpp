class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // yes -> peak 포함 오른쪽 구간

        // 1 2 3 2 1
        // n n y y y 

        int N = nums.size();
        int no = -1, yes = N;

        // 3, 7
        // 5

        while(no + 1 < yes){
            int mid = (yes + no)/2;

            long long l = (mid > 0 ? nums[mid-1] : INT64_MIN);
            long long r = (mid < N-1 ? nums[mid+1]: INT64_MIN);

            if(nums[mid] > l && nums[mid] > r){
                yes = mid;
                break;
            }

            if(nums[mid] > l) no = mid;
            else yes = mid;
        }

        return yes;
    }
};