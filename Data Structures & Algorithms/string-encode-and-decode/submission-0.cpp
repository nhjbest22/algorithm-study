class Solution {
public:
    string encode(vector<string>& strs) {
        string str;

        for(auto& s: strs){
            int N = s.size();
            str += (to_string(N) + ":" +s);
        }

        return str;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        
        int prev = 0;
        int cur;
        while((cur = s.find(':', prev)) != string::npos){
            int len = stoi(s.substr(prev, cur - prev));

            string str = s.substr(cur + 1, len);
            ans.push_back(str);
            
            prev = cur + len + 1;
        }

        return ans;
    }
};
