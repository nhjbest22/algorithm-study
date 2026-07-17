class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int idx = 0;
        int arr[2505] = {0, };

        for(int& num: nums){
            auto it = lower_bound(arr, arr + idx, num);

            if(it == arr + idx){
                arr[idx++] = num;
                continue;
            }

            *it = num;
        }

        return idx;
    }
};