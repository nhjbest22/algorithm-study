class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sTot, tTos;

        for(int i = 0; i < s.size(); i++){
            char ch1 = s[i], ch2 = t[i];

            if(sTot.find(ch1) == sTot.end() && tTos.find(ch2) == tTos.end()){
                sTot[ch1] = ch2;
                tTos[ch2] = ch1;

                continue;
            }

            if(sTot.find(ch1) != sTot.end() && tTos.find(ch2) != tTos.end()){
                if(sTot[ch1] == ch2 && tTos[ch2] == ch1) continue;
            }

            return false;
        }

        return true;
    }
};