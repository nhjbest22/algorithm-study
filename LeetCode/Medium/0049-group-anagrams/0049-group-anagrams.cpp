class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> um;

        for(auto& str: strs){
            string token = str;
            sort(token.begin(), token.end());

            um[token].push_back(str);
        }

        for(auto& p: um){
            res.push_back(p.second);
        }

        return res;
    }
};