class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] ans = new int[k];
        Map<Integer, Integer> m = new HashMap<>();
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> m.get(a) - m.get(b));

        for(int num: nums)
            m.put(num, m.getOrDefault(num, 0) + 1);
        
        m.forEach((key, value)-> {
           pq.offer(key);

           if(pq.size() > k) pq.poll(); 
        });

        for(int i = 0; i < k; i++){
            ans[i] = pq.poll();
        }

        return ans;
    }
}