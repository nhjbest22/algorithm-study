class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!k) return;

        int N = nums.size();

        int buffer[N+10];

        for(int i = 0; i <N; i++){
            int nxt = (i+k) % N;
            buffer[nxt] = nums[i];
        }

        for(int i = 0;i < N; i++){
            nums[i] = buffer[i];
        }
    }
};