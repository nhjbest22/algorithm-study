class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] ans = new int[k][2];
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> {
            int dist1 = a[0]*a[0] + a[1]*a[1];
            int dist2 = b[0]*b[0] + b[1]*b[1];

            return dist2 - dist1;
        });

        int N = points.length;
        for(int[] p: points){
            pq.offer(p);

            if(pq.size() > k)
                pq.poll();
        }    

        for(int i = 0; i < k; i++)
            ans[i] = pq.poll();
        

        return ans;
    }
}