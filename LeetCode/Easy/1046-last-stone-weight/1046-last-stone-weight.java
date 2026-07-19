class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        int N = stones.length;
        for(int size: stones)
            pq.offer(size);

        while(pq.size() > 1){
            int a = pq.poll(), b = pq.poll();

            if(a == b) continue;

            pq.offer(a - b);
        }

        return pq.isEmpty() ? 0 : pq.peek();
    }
}