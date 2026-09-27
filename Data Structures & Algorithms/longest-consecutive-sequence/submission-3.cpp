class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int MAX = 0;
        
        for(auto num: us){
            int cnt = 1;

            if(us.find(num-1) != us.end()) continue;
            
            while(us.find(num + 1) != us.end()){
                num++; cnt++;
            }

            MAX = max(MAX, cnt);
        }

        return MAX;
    }
};
