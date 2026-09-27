class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int MAX = 0;
        
        for(auto x: us){
            if(us.find(x-1) != us.end()) continue;

            int y = x;            
            while(us.find(y + 1) != us.end()){
                y++;
            }

            MAX = max(MAX, y - x + 1);
        }

        return MAX;
    }
};
