class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> um;

        int ans = 0;

        for(auto& task: tasks){
            um[task]++;
        }

        for(auto& [key, value]: um){
            if(value == 1) return -1;

            int cnt = value / 3;
            int remainder = value % 3;

            if(remainder % 2 != 0){
                cnt--;
                remainder += 3;
            }

            cnt += remainder / 2;

            ans += cnt;
        }

        return ans;
    }
};