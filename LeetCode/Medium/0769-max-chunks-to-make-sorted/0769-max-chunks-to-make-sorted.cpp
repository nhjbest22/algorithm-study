class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int N = arr.size();

        int MAX = -1;
        for(int i = 0; i< N; i++){
            MAX = max(MAX, arr[i]);
            
            if(MAX == i) ans++;
        }

        return ans;
    }
};