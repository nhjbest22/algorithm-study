class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        int l = a.size() -1, r = b.size() - 1;
        int carry = 0;

        while(l >= 0 || r >= 0 || carry != 0){
            int sum = 0;
            if(l >= 0)
                sum += a[l--] - '0';
            
            if(r >= 0)
                sum += b[r--] - '0';

            sum += carry;
            ans += (sum%2) + '0';

            carry = sum >= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};