class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int from[1005], to[1005];
        fill(from, from + 1005, 0);
        fill(to, to + 1005, 0);

        int N = trust.size();

        for(int i = 0; i < N; i++){
            from[trust[i][0]]++;
            to[trust[i][1]]++;
        }

        int ans = -1;
        for(int i = 1; i<= n; i++){
            if(to[i] == n-1 && from[i] == 0) {
                if(ans != -1) return -1;

                ans = i;
            }
        }

        return ans;
    }
};