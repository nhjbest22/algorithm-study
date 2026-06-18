class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";

        int l = 0, r = 0;
        int overSum = 0;
        while(l < a.size() && r < b.size()){
            int sum = (a[l++] - '0') + (b[r++] - '0') + overSum;
            
            overSum = sum >= 2;
            ans += to_string((sum % 2));
        }

        while(l < a.size()){
            int sum = (a[l++] - '0') + overSum;
            overSum = sum >= 2;
            ans += to_string((sum % 2));
        }

        while(r < b.size()){
            int sum = (b[r++] - '0') + overSum;
            overSum = sum >= 2;
            ans += to_string((sum % 2));
        }

        if(overSum) ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};