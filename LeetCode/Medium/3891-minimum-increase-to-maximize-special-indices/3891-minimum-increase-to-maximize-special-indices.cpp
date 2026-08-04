class Solution {
public:
    int find_local_diff(vector<int>& nums, int cur){
        int local_diff = max(nums[cur-1], nums[cur+1]) - nums[cur];

        return max(0, local_diff + 1);
    }

    long long minIncrease(vector<int>& nums) {
        // 짝수 개, 홀수 개 차이가 있음

        // 1 2 3 4 5 6 (짝수)
        // (2, 4), (2, 5), (3, 5)

        // 1 2 3 4 5 6 7 (홀수)
        // (2, 4, 6)

        // 0 1 2 3 4 5 6 7
        // (1, 3, 5), (1, 3, 6), (1, 4, 6), (2, 4, 6)
        long long MIN;
        int N = nums.size();
        
        int target = (N+1)/2 - 1;
        
        long long sum = 0;

        if(N % 2){
            for(int i = 1; i < N; i += 2){
                int diff = find_local_diff(nums, i);
                sum += diff;
            }

            return sum;
        }

        long long odd_sum[100'005] = {0, };
        long long even_sum[100'005] = {0, };

        odd_sum[1] = find_local_diff(nums, 1);
        for(int i = 3; i < N - 1; i+= 2)
            odd_sum[i] = odd_sum[i-2] + find_local_diff(nums, i);

        even_sum[N-2] = find_local_diff(nums, N-2);
        for(int i = N-4; i > 0; i-= 2)
            even_sum[i] = even_sum[i+2] + find_local_diff(nums, i);

        MIN = even_sum[2];

        for(int i = 1; i < N-1; i += 2){
            long long sum = odd_sum[i] + even_sum[i+3];

            MIN = min(MIN, sum);
        }

        return MIN;
    }
};