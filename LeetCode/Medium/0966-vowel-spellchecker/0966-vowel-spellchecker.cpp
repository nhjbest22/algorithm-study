class Solution {
public:
    string& toLower(string& str){
        for(auto& ch: str){
            ch = tolower(ch);
        }

        return str;
    }

    string& vowelToA(string& str){
        for(auto& ch: str){
            for(auto& vowel: {'a', 'e', 'i', 'o', 'u'}){
                if(ch == vowel){
                    ch = 'a';
                    break;
                }
            }
        }

        return str;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> case1;
        unordered_map<string, string> case2, case3;
        vector<string> ans;

        int N = wordlist.size();

        for(int i = N-1; i >= 0; i--){
            string inp = wordlist[i];

            case1.insert(inp);
            case2[toLower(inp)] = wordlist[i];
            case3[vowelToA(inp)] = wordlist[i];
        }

        for(auto& query: queries){
            if(case1.find(query) != case1.end()){
                ans.push_back(query);
                continue;
            }

            if(case2.find(toLower(query)) != case2.end()){
                ans.push_back(case2[query]);
                continue;
            }

            if(case3.find(vowelToA(query)) != case3.end()){
                ans.push_back(case3[query]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};