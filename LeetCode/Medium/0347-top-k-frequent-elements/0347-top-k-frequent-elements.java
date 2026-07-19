class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] ans = new int[k];
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        Map<Integer, Integer> m = new HashMap<>();

        for(int num: nums)
            m.put(num, m.getOrDefault(num, 0) + 1);
        
        m.forEach((key, value)-> {
            pq.offer(new int[]{value, key});
        });

        for(int i = 0; i < k; i++){
            ans[i] = pq.poll()[1];
        }

        return ans;
    }
}