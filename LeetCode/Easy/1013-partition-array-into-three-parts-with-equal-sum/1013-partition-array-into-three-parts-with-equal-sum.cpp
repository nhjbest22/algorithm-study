class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int N = arr.size();
        for(int i = 1; i < N; i++){
            arr[i] += arr[i-1];
        }

        if(arr[N-1] % 3 != 0) return false;

        int f = arr[N-1]/3, m = 2*f;
        int f_idx = -1;

        for(int i = 0; i < N-1; i++){
            if(f_idx == -1 && arr[i] == f){
                f_idx = i;
                continue;
            }

            if(f_idx != -1 && arr[i] == m){
                return true;
            }
        }

        return false;
    }
};