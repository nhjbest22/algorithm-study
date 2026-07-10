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

            ans += (value + 2) / 3;
        }

        return ans;
    }
};