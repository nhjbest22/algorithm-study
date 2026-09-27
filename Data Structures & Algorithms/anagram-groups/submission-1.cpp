class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        for(auto& str: strs){
            string ori = str;

            sort(str.begin(), str.end());

            um[str].push_back(ori);            
        }

        vector<vector<string>> ans;
        for(auto val: um) ans.push_back(val.second);

        return ans;
    }
};
