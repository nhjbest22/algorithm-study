class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int suffixMIN[2'005];
        int N = arr.size();
        int ans = 0;

        int MIN = INT32_MAX;
        for(int i = N-1; i>= 0; i--){
            MIN = min(MIN, arr[i]);
            suffixMIN[i] = MIN;
        }
        suffixMIN[N] = INT32_MAX;

        int MAX = -1;

        for(int i = 0; i < N; i++){
            MAX = max(MAX, arr[i]);

            if(MAX <= suffixMIN[i+1]) ans++;
        }

        return ans;
    }
};