class Solution {
public:
    bool isGCD(const string& target, int len){
        int N = target.size() / len;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < len; j++){
                if(target[i*len + j] != target[j]) return false;
            }
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int N = min(str1.size(), str2.size());

        int ans = 0;
        for(int i = 0; i < N; i++){
            if(str1[i] != str2[i]) break;
            if(str1.size() % (i+1) != 0) continue;
            if(str2.size() % (i+1) != 0) continue;

            if(isGCD(str1, i+1) && isGCD(str2, i+1)) ans = i+1;
        }

        return str1.substr(0, ans);
    }
};