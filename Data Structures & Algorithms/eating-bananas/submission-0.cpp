class Solution {
public:
    bool check(vector<int>& piles, int h, int mid){
        long long sum = 0;
        for(auto& p: piles){
            sum += p / mid;
            sum += (p % mid > 0);
        }

        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int yes = 1'000'000'005;
        int no = 0;

        while(no + 1 < yes){
            int mid = (yes + no)/2;

            if(check(piles, h, mid)) yes = mid;
            else no = mid;
        }

        return yes;
    }
};
