class Solution {

    public int[] twoSum(int[] nums, int target) {
        int N = nums.length;
        Map<Integer, Integer> m = new HashMap<>();

        for(int i = 0; i < N; i++){
            int find = target - nums[i];

            if(m.containsKey(find))
                return new int[]{m.get(find), i};

            m.put(nums[i], i);
        }

        return new int[]{};
    }
}