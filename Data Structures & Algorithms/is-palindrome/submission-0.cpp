class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.size();
        int l = 0, r = N - 1;

        while(1){
            while(l < N && !isalpha(s[l]) && !isdigit(s[l])) l++;
            while(r >= 0 && !isalpha(s[r]) && !isdigit(s[r])) r--;

            if(l > r) break;
            if(tolower(s[l]) != tolower(s[r])) return false;

            l++; r--;
        }

        return true;
    }
};
