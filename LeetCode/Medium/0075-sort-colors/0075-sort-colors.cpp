class Solution {
public:
    void quickSort(int st, int en, vector<int>& nums){
        if(en <= st + 1) return;

        int pivot = nums[st];

        int l = st + 1;
        int r = en - 1;

        while(1){
            while(l <= r && nums[l] <= pivot) l++;
            while(l <= r && nums[r] > pivot) r--;

            if(r < l) break;
            swap(nums[l], nums[r]);
        }

        swap(nums[st], nums[r]);

        quickSort(st, r, nums);
        quickSort(r+1, en, nums);
    }

    void sortColors(vector<int>& nums) {
        int N = nums.size();
        quickSort(0, N, nums);

        return;
    }
};