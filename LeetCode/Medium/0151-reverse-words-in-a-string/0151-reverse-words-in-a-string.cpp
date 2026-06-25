class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;

        stringstream ss(s);
        string str;

        while(ss >> str)
            v.push_back(str);

        string ans;
        int N = v.size();

        for(int i = N-1; i>= 0; i--){
            ans += v[i] + ' ';
        }

        ans.pop_back();
        return ans;
    }
};