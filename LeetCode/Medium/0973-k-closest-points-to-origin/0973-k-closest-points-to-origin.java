class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] ans = new int[k][2];
        int N = points.length;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->{
            int d1 = a[0]*a[0] + a[1]*a[1];
            int d2 = b[0]*b[0] + b[1]*b[1];

            return d1 - d2;
        });

        for(int i = 0; i < N; i++)
            pq.offer(points[i]);

        for(int i = 0; i < k; i++)
            ans[i] = pq.poll();

        return ans;
    }
}