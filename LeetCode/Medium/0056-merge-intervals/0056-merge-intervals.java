class Solution {
    public int[][] merge(int[][] intervals) {
        int N = intervals.length;
        ArrayList<int[]> list = new ArrayList<>();

        Arrays.sort(intervals, (a, b) -> {
            if(a[0] != b[0])
                return a[0] - b[0];
            return a[1] - b[1];
        });

        int st = intervals[0][0], en = intervals[0][1];

        for(int i = 1; i < N; i++){
            if(intervals[i][0] <= en){
                en = Math.max(intervals[i][1], en);
                continue;
            }

            list.add(new int[]{st, en});

            st = intervals[i][0];
            en = intervals[i][1];
        }

        list.add(new int[]{st, en});
        return list.toArray(new int[0][]);
    }
}