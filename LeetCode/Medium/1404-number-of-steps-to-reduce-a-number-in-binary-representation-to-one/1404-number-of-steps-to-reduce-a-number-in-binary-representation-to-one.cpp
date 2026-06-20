class Solution {
public:
    int numSteps(string s) {
        int idx = 0;
        int carry = 0;
        int ans = 0;

        reverse(s.begin(), s.end());

        while(idx < s.size() - 1){
            cout<<s<<endl;

            ans++;
            if(s[idx] == '0'){
                idx++;
                continue;
            }

            carry = 1;

            for(int i = idx; i < s.size(); i++){
                int ret = (s[i] - '0') + carry;

                s[i] = (ret%2) + '0';
                carry = ret >= 2;
            }

            if(carry) s += '1';
        }

        cout<<s<<endl;


        return ans;
    }
};