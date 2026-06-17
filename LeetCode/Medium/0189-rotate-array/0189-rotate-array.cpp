class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!k) return;

        int N = nums.size();

        int buffer[N+10];
        int st = N - (k%N);

        st %= N;

        for(int i = 0;i < N; i++){
            buffer[i] = nums[st++];

            st %= N;
        }

        for(int i = 0;i < N; i++){
            nums[i] = buffer[i];
        }
    }
};