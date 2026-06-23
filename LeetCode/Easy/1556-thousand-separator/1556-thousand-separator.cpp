class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());

        string ans;
        for(int i = 0; i <= str.size()/3; i++){
            ans += str.substr(3*i, 3);
            if(3*(i+1) < str.size()) ans += ".";
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};