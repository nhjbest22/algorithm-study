class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] ans = new int[k][2];
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> {
            int dist1 = a[0]*a[0] + a[1]*a[1];
            int dist2 = b[0]*b[0] + b[1]*b[1];

            return dist1 - dist2;
        });

        int N = points.length;
        for(int i = 0; i < N; i++)
            pq.offer(points[i]);
    

        for(int i = 0; i < k; i++)
            ans[i] = pq.poll();
        

        return ans;
    }
}