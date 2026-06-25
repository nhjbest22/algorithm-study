class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;

        int MAX = *max_element(candies.begin(), candies.end());
        for(auto& candy: candies){
            ans.push_back(candy + extraCandies >= MAX);
        }

        return ans;
    }
};