class Solution {
public:
    int specialArray(vector<int>& nums) {
        int cnt[1'005] = {0, };
        for(auto& num: nums) cnt[num]++;

        for(int i = 999; i>=0; i--){
            cnt[i] += cnt[i+1];
        }

        for(int i = 0; i <= 1'000; i++){
            if(cnt[i] < i) break;

            if(cnt[i] == i) return i;
        }

        return -1;
    }
};