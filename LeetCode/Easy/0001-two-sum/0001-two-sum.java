class Solution {

    public int[] twoSum(int[] nums, int target) {
        record Pair(int num, int idx) {}
        int N = nums.length;
        Pair[] arr = new Pair[N];

        for(int i = 0; i < N; i++)
            arr[i] = new Pair(nums[i], i);
        
        Arrays.sort(arr, (a, b) -> a.num() - b.num());
        int l = 0, r = N - 1;

        while(l < r){
            int sum = arr[l].num() + arr[r].num();

            if(sum == target) break;

            if(sum < target) l++;
            else r--;
        }

        int[] ans = {arr[l].idx(), arr[r].idx()};
        return ans;
    }
}