class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool isPrime[100'005];
        fill(isPrime, isPrime + 100'005, true);

        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i*i < 100'005; i++){
            if(!isPrime[i]) continue;

            for(int j = i * i; j < 100'005; j += i)
                isPrime[j] = false;
        }

        vector<int> primes;
        for(int i = 2; i < 100'005; i++){
            if(!isPrime[i]) continue;

            primes.push_back(i);
        }

        int N = nums.size();
        int ans = 0;
        for(int i = 0; i < N; i++){
            int& num = nums[i];

            if(i & 1){
                while(isPrime[num++])
                    ans++;
            }else{
                while(!isPrime[num++])
                    ans++;
            }
        }

        return ans;
    }
};