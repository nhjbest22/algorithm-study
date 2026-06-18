class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        int N = str.size();

        for(int i = 0; i < N/2; i++){
            if(str[i] != str[N-1-i]) return false;
        }

        return true;
    }

};