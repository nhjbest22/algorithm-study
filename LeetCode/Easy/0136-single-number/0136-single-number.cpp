class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> um;

        for(int i = 0; i < N; i++){
            um[nums[i]]++;
        }

        for(auto& p: um){
            if(p.second == 1) return p.first;
        }

        return 0;
    }
};