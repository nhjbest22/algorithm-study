class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        vector<vector<string>> ans;

        for(const auto& s: strs){
            vector<int> cnt('z' - 'a' + 1, 0);
            for(auto& ch: s) cnt['z' - ch]++;

            string key = "";
            for(int i = 0; i < 'z' - 'a' + 1; i++){
                key += (to_string(cnt[i]) + ',');
            }

            um[key].push_back(s);
        }

        for(auto& p: um) ans.push_back(p.second);
        return ans;
    }
};
