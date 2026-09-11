class Solution {
public:
    vector<int> constructArray(int N, int K) {
        vector<int> ans(N);

        for(int i = 0; i < K; i++)
            ans[i] = i % 2 ? N - i/2 : i/2 + 1;
        
        int diff = K % 2 ? 1 : -1;
        for(int i = K; i < N; i++){
            ans[i] = ans[i-1] + diff;
        }

        return ans;
    }
};