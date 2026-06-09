class Solution {
public:
    bool checkOnesSegment(string s) {
        bool isZero = false;
        for(auto& ch: s){
            if(ch == '0'){
                isZero = true;
                continue;
            }

            if(isZero) return false;
        }

        return true;
    }
};