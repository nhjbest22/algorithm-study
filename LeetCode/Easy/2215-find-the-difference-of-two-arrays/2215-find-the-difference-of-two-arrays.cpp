class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        unordered_set<int> us1, us2;

        for(int i = 0; i < nums1.size(); i++)
            us1.insert(nums1[i]);
        
        for(int i = 0; i < nums2.size(); i++)
            us2.insert(nums2[i]);
        
        for(auto& num: us1){
            if(us2.find(num) != us2.end())
                continue;
            
            v1.push_back(num);
        }

        for(auto& num: us2){
            if(us1.find(num) != us1.end())
                continue;
            
            v2.push_back(num);
        }

        return {v1, v2};
    }
};